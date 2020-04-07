#include "FWCore/MessageLogger/interface/MessageLogger.h"
//#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
//#include "FWCore/Common/interface/TriggerNames.h"
#include "2018lldj/ntuples/interface/lldjNtuple.h"
#include <iomanip>
#include <bitset>
using namespace std;

// (local) variables associated with tree branches
Int_t       AODrun_;
Long64_t    AODevent_;
Int_t       AODlumis_;
Bool_t      AODisData_;

Int_t       AODnTruePU_;
Int_t       AODnVtx_;
Int_t       AODnGoodVtx_;
Int_t       AODnTrksPV_;
Bool_t      AODisPVGood_;
Float_t     AODGenEventWeight_;
//new variables
float                 AODfixedGridRhoFastjetAll_;
int                   AODnBunchXing_;
std::vector<int>      AODBunchXing_;
std::vector<int>      AODnPU_;
std::vector<float>      AODnPUmean_;

void ResetEventBranches()
{
  AODfixedGridRhoFastjetAll_ = -999.;
  AODnBunchXing_ = 0;
  AODBunchXing_.clear();
  AODnPU_.clear();
  AODnPUmean_.clear();
};

void lldjNtuple::branchesAODEvent(TTree* tree) {

  tree->Branch("run",     	       &AODrun_);
  tree->Branch("event",    	       &AODevent_);
  tree->Branch("lumis",   	       &AODlumis_);
  tree->Branch("isData",  	       &AODisData_);

  tree->Branch("AODnTruePU",              &AODnTruePU_);
  tree->Branch("AODnVtx",                 &AODnVtx_);
  tree->Branch("AODnGoodVtx",             &AODnGoodVtx_);
  tree->Branch("AODnTrksPV",              &AODnTrksPV_);
  tree->Branch("AODisPVGood",             &AODisPVGood_);
  tree->Branch("AODGenEventWeight",       &AODGenEventWeight_);
  //new variables
  tree->Branch("AODfixedGridRhoFastjetAll",   &AODfixedGridRhoFastjetAll_);
  tree->Branch("AODnBunchXing",               &AODnBunchXing_);
  tree->Branch("AODBunchXing",                &AODBunchXing_);
  tree->Branch("AODnPU",                      &AODnPU_);
  tree->Branch("AODnPUmean",                  &AODnPUmean_);
}

void lldjNtuple::fillAODEvent(const edm::Event& e, const edm::EventSetup& es) {

  //reset local variables
  ResetEventBranches();

  AODrun_    = e.id().run();
  AODevent_  = e.id().event();
  AODlumis_  = e.luminosityBlock();
  AODisData_ = e.isRealData();

  //-----------------------
  //Get PU INFO
  //------------------------
  AODnTruePU_ = -1 ;
  if (!e.isRealData()) {
   edm::Handle<vector<PileupSummaryInfo> > AODpuInfoHandle;
   e.getByToken(AODpuCollection_, AODpuInfoHandle);
   if ( AODpuInfoHandle->size() > 0 ){
    AODnTruePU_ = AODpuInfoHandle->at(0).getTrueNumInteractions() ;
    //AODnTruePU_ = AODpuInfoHandle->at(1).getTrueNumInteractions() ;
   }

   //new info from Cristian
   for( const auto &pu : *AODpuInfoHandle )
   {
     AODBunchXing_.push_back(pu.getBunchCrossing());
     AODnPU_.push_back( pu.getPU_NumInteractions() );
     AODnPUmean_.push_back( pu.getTrueNumInteractions() );
     AODnBunchXing_++;
   }
  }


  edm::Handle<edm::View<reco::Vertex>  >  AODVertexHandle;
  e.getByToken( AODVertexLabel_      ,  AODVertexHandle );

  AODnVtx_     = 0;
  AODnGoodVtx_ = 0;
  for(int k = 0; k < (int)AODVertexHandle->size();k++){
  if (AODVertexHandle->at(k).isValid())
  {

   if (AODnVtx_ == 0) // assumes leading vtx in collection is PV
   {
    AODnTrksPV_ = AODVertexHandle->at(k).nTracks();
    AODisPVGood_ = false;
    if (!AODVertexHandle->at(k).isFake() &&
         AODVertexHandle->at(k).ndof() > 4. &&
         fabs(AODVertexHandle->at(k).z()) <= 24. &&
         fabs(AODVertexHandle->at(k).position().rho()) <= 2.)  AODisPVGood_ = true;
   } // if AODnVtx_ == 0

   // all vertices
   if (!AODVertexHandle->at(k).isFake() &&
        AODVertexHandle->at(k).ndof() > 4. &&
        fabs(AODVertexHandle->at(k).z()) <= 24. &&
        fabs(AODVertexHandle->at(k).position().rho()) <= 2.)  AODnGoodVtx_++;

   AODnVtx_++;
  } // if AODVertexHandle->at(k).isValid()
  else {edm::LogWarning("lldjNtuple") << "Primary vertices info not unavailable";}

  }
  if (!e.isRealData()){
  edm::Handle<GenEventInfoProduct>  AODGenEventInfoHandle;
  e.getByToken(AODGenEventInfoLabel_, AODGenEventInfoHandle);
  GenEventWeight =AODGenEventInfoHandle->weight();
  AODGenEventWeight_ = GenEventWeight;
  }

  //--------------------------
  //get fixedGridRhoFastjetAll
  //--------------------------
  e.getByToken(rhoLabel_, rhoHandle);
  AODfixedGridRhoFastjetAll_ = *rhoHandle;
}
