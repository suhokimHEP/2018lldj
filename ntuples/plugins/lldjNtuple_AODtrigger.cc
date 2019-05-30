// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Math/interface/deltaR.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"

#include "2018lldj/ntuples/interface/lldjNtuple.h"

// (local) variables associated with tree branches

// triggers used in VHbb
// https://indico.cern.ch/event/655639/contributions/2670493/attachments/1497203/2337123/VHbb_Approval_28_07_17_v10.pdf#page=8

// trigger fired variables
ULong64_t   AOD_HLT_DoubleEle33_;
ULong64_t   AOD_HLT_Ele23Ele12_;
ULong64_t   AOD_HLT_Ele23Ele12_noDZ_;

ULong64_t   AOD_HLT_Mu17Mu8_;
ULong64_t   AOD_HLT_Mu17Mu8_Mass8_;
ULong64_t   AOD_HLT_Mu17Mu8_Mass3p8_;
//ULong64_t   AOD_HLT_Mu17TkMu8_;

ULong64_t   AOD_HLT_Mu17Mu8_noDZ_;
//ULong64_t   AOD_HLT_Mu17TkMu8_noDZ_;

ULong64_t   AOD_HLT_Mu8Ele23_DZ_;
ULong64_t   AOD_HLT_Mu8Ele23_noDZ_;
ULong64_t   AOD_HLT_Mu23Ele12_DZ_;
ULong64_t   AOD_HLT_Mu23Ele12_noDZ_;
ULong64_t   AOD_HLT_Mu12Ele23_DZ_;
ULong64_t   AOD_HLT_Mu12Ele23_noDZ_;

// trigger is prescaled variables
ULong64_t   AOD_HLT_DoubleEle33_isPS_;
ULong64_t   AOD_HLT_Ele23Ele12_isPS_;
ULong64_t   AOD_HLT_Ele23Ele12_noDZ_isPS_;

ULong64_t   AOD_HLT_Mu17Mu8_isPS_;
ULong64_t   AOD_HLT_Mu17Mu8_Mass8_isPS_;
ULong64_t   AOD_HLT_Mu17Mu8_Mass3p8_isPS_;
//ULong64_t   AOD_HLT_Mu17TkMu8_isPS_;

ULong64_t   AOD_HLT_Mu17Mu8_noDZ_isPS_;
//ULong64_t   AOD_HLT_Mu17TkMu8_noDZ_isPS_;

ULong64_t   AOD_HLT_Mu8Ele23_DZ_isPS_;
ULong64_t   AOD_HLT_Mu8Ele23_noDZ_isPS_;
ULong64_t   AOD_HLT_Mu23Ele12_DZ_isPS_;
ULong64_t   AOD_HLT_Mu23Ele12_noDZ_isPS_;
ULong64_t   AOD_HLT_Mu12Ele23_DZ_isPS_;
ULong64_t   AOD_HLT_Mu12Ele23_noDZ_isPS_;

void lldjNtuple::branchesAODTrigger(TTree* tree){
  tree->Branch("AOD_HLT_DoubleEle33",      &AOD_HLT_DoubleEle33_)     ;
  tree->Branch("AOD_HLT_Ele23Ele12",       &AOD_HLT_Ele23Ele12_)     ;
  tree->Branch("AOD_HLT_Ele23Ele12_noDZ",  &AOD_HLT_Ele23Ele12_noDZ_) ;
  
  tree->Branch("AOD_HLT_Mu17Mu8"  ,        &AOD_HLT_Mu17Mu8_)   ;
  tree->Branch("AOD_HLT_Mu17Mu8_Mass8"  ,  &AOD_HLT_Mu17Mu8_Mass8_)   ;
  tree->Branch("AOD_HLT_Mu17Mu8_Mass3p8"  ,&AOD_HLT_Mu17Mu8_Mass3p8_)   ;
  //tree->Branch("AOD_HLT_Mu17TkMu8",        &AOD_HLT_Mu17TkMu8_) ;

  tree->Branch("AOD_HLT_Mu17Mu8_noDZ"  ,   &AOD_HLT_Mu17Mu8_noDZ_)   ;
  //tree->Branch("AOD_HLT_Mu17TkMu8_noDZ",   &AOD_HLT_Mu17TkMu8_noDZ_) ;

  tree->Branch("AOD_HLT_Mu8Ele23_DZ"  ,    &AOD_HLT_Mu8Ele23_DZ_)     ;
  tree->Branch("AOD_HLT_Mu8Ele23_noDZ"  ,  &AOD_HLT_Mu8Ele23_noDZ_)     ;
  tree->Branch("AOD_HLT_Mu23Ele12_DZ"  ,   &AOD_HLT_Mu23Ele12_DZ_)    ;
  tree->Branch("AOD_HLT_Mu23Ele12_noDZ"  , &AOD_HLT_Mu23Ele12_noDZ_) ;
  tree->Branch("AOD_HLT_Mu12Ele23_DZ"  ,   &AOD_HLT_Mu12Ele23_DZ_) ;
  tree->Branch("AOD_HLT_Mu12Ele23_noDZ"  , &AOD_HLT_Mu12Ele23_noDZ_) ;

  //prescale
  tree->Branch("AOD_HLT_DoubleEle33_isPS",      &AOD_HLT_DoubleEle33_isPS_)      ;
  tree->Branch("AOD_HLT_Ele23Ele12_isPS",       &AOD_HLT_Ele23Ele12_isPS_)      ;
  tree->Branch("AOD_HLT_Ele23Ele12_noDZ_isPS",  &AOD_HLT_Ele23Ele12_noDZ_isPS_) ;
  
  tree->Branch("AOD_HLT_Mu17Mu8_isPS",          &AOD_HLT_Mu17Mu8_isPS_)   ;
  tree->Branch("AOD_HLT_Mu17Mu8_Mass8_isPS",    &AOD_HLT_Mu17Mu8_Mass8_isPS_)   ;
  tree->Branch("AOD_HLT_Mu17Mu8_Mass3p8_isPS",  &AOD_HLT_Mu17Mu8_Mass3p8_isPS_)   ;
  //tree->Branch("AOD_HLT_Mu17TkMu8_isPS",        &AOD_HLT_Mu17TkMu8_isPS_) ;

  tree->Branch("AOD_HLT_Mu17Mu8_noDZ_isPS",     &AOD_HLT_Mu17Mu8_noDZ_isPS_)   ;
  //tree->Branch("AOD_HLT_Mu17TkMu8_noDZ_isPS",   &AOD_HLT_Mu17TkMu8_noDZ_isPS_) ;

  tree->Branch("AOD_HLT_Mu8Ele23_DZ_isPS",      &AOD_HLT_Mu8Ele23_DZ_isPS_)     ;
  tree->Branch("AOD_HLT_Mu8Ele23_noDZ_isPS",    &AOD_HLT_Mu8Ele23_noDZ_isPS_)     ;
  tree->Branch("AOD_HLT_Mu23Ele12_DZ_isPS",     &AOD_HLT_Mu23Ele12_DZ_isPS_) ;
  tree->Branch("AOD_HLT_Mu23Ele12_noDZ_isPS",   &AOD_HLT_Mu23Ele12_noDZ_isPS_)    ;
  tree->Branch("AOD_HLT_Mu12Ele23_DZ_isPS",     &AOD_HLT_Mu12Ele23_DZ_isPS_) ;
  tree->Branch("AOD_HLT_Mu12Ele23_noDZ_isPS",   &AOD_HLT_Mu12Ele23_noDZ_isPS_) ;
}


void lldjNtuple::fillAODTrigger(const edm::Event &e, const edm::EventSetup &es){
  
  AOD_HLT_DoubleEle33_      = 0;
  AOD_HLT_Ele23Ele12_       = 0;
  AOD_HLT_Ele23Ele12_noDZ_  = 0;
  
  AOD_HLT_Mu17Mu8_          = 0;
  AOD_HLT_Mu17Mu8_Mass8_          = 0;
  AOD_HLT_Mu17Mu8_Mass3p8_          = 0;
  //AOD_HLT_Mu17TkMu8_        = 0;

  AOD_HLT_Mu17Mu8_noDZ_     = 0;
  //AOD_HLT_Mu17TkMu8_noDZ_   = 0;

  AOD_HLT_Mu8Ele23_DZ_          = 0;
  AOD_HLT_Mu8Ele23_noDZ_          = 0;
  AOD_HLT_Mu23Ele12_DZ_         = 0;
  AOD_HLT_Mu23Ele12_noDZ_      = 0;
  AOD_HLT_Mu12Ele23_DZ_      = 0;
  AOD_HLT_Mu12Ele23_noDZ_      = 0;

  //prescale
  AOD_HLT_DoubleEle33_isPS_      = 0;
  AOD_HLT_Ele23Ele12_isPS_       = 0;
  AOD_HLT_Ele23Ele12_noDZ_isPS_  = 0;
  
  AOD_HLT_Mu17Mu8_isPS_          = 0;
  AOD_HLT_Mu17Mu8_Mass8_isPS_          = 0;
  AOD_HLT_Mu17Mu8_Mass3p8_isPS_          = 0;
  //AOD_HLT_Mu17TkMu8_isPS_        = 0;

  AOD_HLT_Mu17Mu8_noDZ_isPS_     = 0;
  //AOD_HLT_Mu17TkMu8_noDZ_isPS_   = 0;

  AOD_HLT_Mu8Ele23_DZ_isPS_          = 0;
  AOD_HLT_Mu8Ele23_noDZ_isPS_          = 0;
  AOD_HLT_Mu23Ele12_DZ_isPS_      = 0;
  AOD_HLT_Mu23Ele12_noDZ_isPS_         = 0;
  AOD_HLT_Mu12Ele23_DZ_isPS_      = 0;
  AOD_HLT_Mu12Ele23_noDZ_isPS_      = 0;

  if( !( e.getByToken(AODTriggerToken_, AODTriggerHandle_) && e.getByToken(AODTriggerEventToken_, AODTriggerEventHandle_) ) ){ return; }
  
  for(int i = 0; i < (int)hltConfig_.size(); i++){
    string name = hltConfig_.triggerName(i);
    //std::cout<<name<<"\n";
    
    // Double Electron
    int bitDoubleEle33 = -1;
    if      (name.find("HLT_DoubleEle33_CaloIdL_MW_v1")  != string::npos) bitDoubleEle33 = 0  ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v2")  != string::npos) bitDoubleEle33 = 1  ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v3")  != string::npos) bitDoubleEle33 = 2  ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v4")  != string::npos) bitDoubleEle33 = 3  ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v5")  != string::npos) bitDoubleEle33 = 4  ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v6")  != string::npos) bitDoubleEle33 = 5  ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v7")  != string::npos) bitDoubleEle33 = 6  ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v8")  != string::npos) bitDoubleEle33 = 7  ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v9")  != string::npos) bitDoubleEle33 = 8  ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v10") != string::npos) bitDoubleEle33 = 9  ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v11") != string::npos) bitDoubleEle33 = 10 ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v12") != string::npos) bitDoubleEle33 = 11 ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v13") != string::npos) bitDoubleEle33 = 12 ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v14") != string::npos) bitDoubleEle33 = 13 ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v15") != string::npos) bitDoubleEle33 = 14 ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v16") != string::npos) bitDoubleEle33 = 15 ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v17") != string::npos) bitDoubleEle33 = 16 ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v18") != string::npos) bitDoubleEle33 = 17 ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v19") != string::npos) bitDoubleEle33 = 18 ;
    else if (name.find("HLT_DoubleEle33_CaloIdL_MW_v20") != string::npos) bitDoubleEle33 = 19 ;
    
    int bitEle23Ele12 = -1;
    if      (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v1")  != string::npos) bitEle23Ele12 = 0  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v2")  != string::npos) bitEle23Ele12 = 1  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3")  != string::npos) bitEle23Ele12 = 2  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4")  != string::npos) bitEle23Ele12 = 3  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v5")  != string::npos) bitEle23Ele12 = 4  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v6")  != string::npos) bitEle23Ele12 = 5  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v7")  != string::npos) bitEle23Ele12 = 6  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8")  != string::npos) bitEle23Ele12 = 7  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v9")  != string::npos) bitEle23Ele12 = 8  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v10") != string::npos) bitEle23Ele12 = 9  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v11") != string::npos) bitEle23Ele12 = 10 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v12") != string::npos) bitEle23Ele12 = 11 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v13") != string::npos) bitEle23Ele12 = 12 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v14") != string::npos) bitEle23Ele12 = 13 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v15") != string::npos) bitEle23Ele12 = 14 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v16") != string::npos) bitEle23Ele12 = 15 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v17") != string::npos) bitEle23Ele12 = 16 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v18") != string::npos) bitEle23Ele12 = 17 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v19") != string::npos) bitEle23Ele12 = 18 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v20") != string::npos) bitEle23Ele12 = 19 ;
    
    int bitEle23Ele12_noDZ = -1;
    if      (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v1")  != string::npos) bitEle23Ele12_noDZ = 0  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v2")  != string::npos) bitEle23Ele12_noDZ = 1  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v3")  != string::npos) bitEle23Ele12_noDZ = 2  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v4")  != string::npos) bitEle23Ele12_noDZ = 3  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v5")  != string::npos) bitEle23Ele12_noDZ = 4  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v6")  != string::npos) bitEle23Ele12_noDZ = 5  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v7")  != string::npos) bitEle23Ele12_noDZ = 6  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v8")  != string::npos) bitEle23Ele12_noDZ = 7  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v9")  != string::npos) bitEle23Ele12_noDZ = 8  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v10") != string::npos) bitEle23Ele12_noDZ = 9  ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v11") != string::npos) bitEle23Ele12_noDZ = 10 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v12") != string::npos) bitEle23Ele12_noDZ = 11 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v13") != string::npos) bitEle23Ele12_noDZ = 12 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v14") != string::npos) bitEle23Ele12_noDZ = 13 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v15") != string::npos) bitEle23Ele12_noDZ = 14 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v16") != string::npos) bitEle23Ele12_noDZ = 15 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v17") != string::npos) bitEle23Ele12_noDZ = 16 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v18") != string::npos) bitEle23Ele12_noDZ = 17 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v19") != string::npos) bitEle23Ele12_noDZ = 18 ;
    else if (name.find("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v20") != string::npos) bitEle23Ele12_noDZ = 19 ;
    // Double Iso Mui   HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8
    int bitMu17Mu8   = -1;
    if      (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v1")  != string::npos) bitMu17Mu8 = 0  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v2")  != string::npos) bitMu17Mu8 = 1  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v3")  != string::npos) bitMu17Mu8 = 2  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v4")  != string::npos) bitMu17Mu8 = 3  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v5")  != string::npos) bitMu17Mu8 = 4  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v6")  != string::npos) bitMu17Mu8 = 5  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v7")  != string::npos) bitMu17Mu8 = 6  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v8")  != string::npos) bitMu17Mu8 = 7  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v9")  != string::npos) bitMu17Mu8 = 8  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v10") != string::npos) bitMu17Mu8 = 9  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v11") != string::npos) bitMu17Mu8 = 10 ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v12") != string::npos) bitMu17Mu8 = 11 ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v13") != string::npos) bitMu17Mu8 = 12 ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v14") != string::npos) bitMu17Mu8 = 13 ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v15") != string::npos) bitMu17Mu8 = 14 ;
    
    int bitMu17Mu8_Mass8   = -1;
    if      (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_v1")  != string::npos) bitMu17Mu8_Mass8 = 0  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_v2")  != string::npos) bitMu17Mu8_Mass8 = 1  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_v3")  != string::npos) bitMu17Mu8_Mass8 = 2  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_v4")  != string::npos) bitMu17Mu8_Mass8 = 3  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_v5")  != string::npos) bitMu17Mu8_Mass8 = 4  ;
    
    int bitMu17Mu8_Mass3p8   = -1;
    if      (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v1")  != string::npos) bitMu17Mu8_Mass3p8 = 0  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v2")  != string::npos) bitMu17Mu8_Mass3p8 = 1  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v3")  != string::npos) bitMu17Mu8_Mass3p8 = 2  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v4")  != string::npos) bitMu17Mu8_Mass3p8 = 3  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v5")  != string::npos) bitMu17Mu8_Mass3p8 = 4  ;
    
    //int bitMu17TkMu8 = -1;
    //if      (name.find("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1") != string::npos) bitMu17TkMu8 = 0 ;                   
    //else if (name.find("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v2") != string::npos) bitMu17TkMu8 = 1 ;                   
    //else if (name.find("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v3") != string::npos) bitMu17TkMu8 = 2 ;                   
    //else if (name.find("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v4") != string::npos) bitMu17TkMu8 = 3 ;                   
    //else if (name.find("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v5") != string::npos) bitMu17TkMu8 = 4 ;                   
    //else if (name.find("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v6") != string::npos) bitMu17TkMu8 = 5 ;                   

    int bitMu17Mu8_noDZ   = -1;
    if      (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v1")  != string::npos) bitMu17Mu8_noDZ = 0  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v2")  != string::npos) bitMu17Mu8_noDZ = 1  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v3")  != string::npos) bitMu17Mu8_noDZ = 2  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v4")  != string::npos) bitMu17Mu8_noDZ = 3  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v5")  != string::npos) bitMu17Mu8_noDZ = 4  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v6")  != string::npos) bitMu17Mu8_noDZ = 5  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v7")  != string::npos) bitMu17Mu8_noDZ = 6  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v8")  != string::npos) bitMu17Mu8_noDZ = 7  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v9")  != string::npos) bitMu17Mu8_noDZ = 8  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v10") != string::npos) bitMu17Mu8_noDZ = 9  ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v11") != string::npos) bitMu17Mu8_noDZ = 10 ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v12") != string::npos) bitMu17Mu8_noDZ = 11 ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v13") != string::npos) bitMu17Mu8_noDZ = 12 ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v14") != string::npos) bitMu17Mu8_noDZ = 13 ;
    else if (name.find("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v15") != string::npos) bitMu17Mu8_noDZ = 14 ;
    
    
    //int bitMu17TkMu8_noDZ = -1;
    //if      (name.find("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v1") != string::npos) bitMu17TkMu8_noDZ = 0 ;                   
    //else if (name.find("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v2") != string::npos) bitMu17TkMu8_noDZ = 1 ;                   
    //else if (name.find("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v3") != string::npos) bitMu17TkMu8_noDZ = 2 ;                   
    //else if (name.find("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v4") != string::npos) bitMu17TkMu8_noDZ = 3 ;                   
    //else if (name.find("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v5") != string::npos) bitMu17TkMu8_noDZ = 4 ;                   

    //Mu - EG
    int bitMu8Ele23_DZ = -1;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v1")  != string::npos) bitMu8Ele23_DZ = 0  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v2")  != string::npos) bitMu8Ele23_DZ = 1  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v3")  != string::npos) bitMu8Ele23_DZ = 2  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v4")  != string::npos) bitMu8Ele23_DZ = 3  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v5")  != string::npos) bitMu8Ele23_DZ = 4  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v6")  != string::npos) bitMu8Ele23_DZ = 5  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v7")  != string::npos) bitMu8Ele23_DZ = 6  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v8")  != string::npos) bitMu8Ele23_DZ = 7  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v9")  != string::npos) bitMu8Ele23_DZ = 8  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v10") != string::npos) bitMu8Ele23_DZ = 9  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v11") != string::npos) bitMu8Ele23_DZ = 10 ; 
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v12") != string::npos) bitMu8Ele23_DZ = 11 ; 

    int bitMu8Ele23_noDZ = -1;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v1")  != string::npos) bitMu8Ele23_noDZ = 0  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v2")  != string::npos) bitMu8Ele23_noDZ = 1  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v3")  != string::npos) bitMu8Ele23_noDZ = 2  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v4")  != string::npos) bitMu8Ele23_noDZ = 3  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v5")  != string::npos) bitMu8Ele23_noDZ = 4  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v6")  != string::npos) bitMu8Ele23_noDZ = 5  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v7")  != string::npos) bitMu8Ele23_noDZ = 6  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v8")  != string::npos) bitMu8Ele23_noDZ = 7  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v9")  != string::npos) bitMu8Ele23_noDZ = 8  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v10") != string::npos) bitMu8Ele23_noDZ = 9  ;
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v11") != string::npos) bitMu8Ele23_noDZ = 10 ; 
    if      (name.find("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v12") != string::npos) bitMu8Ele23_noDZ = 11 ; 

    int bitMu23Ele12_DZ = -1;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v1")  != string::npos) bitMu23Ele12_DZ = 0;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v2")  != string::npos) bitMu23Ele12_DZ = 1;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v3")  != string::npos) bitMu23Ele12_DZ = 2;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v4")  != string::npos) bitMu23Ele12_DZ = 3;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v5")  != string::npos) bitMu23Ele12_DZ = 4;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v6")  != string::npos) bitMu23Ele12_DZ = 5;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v7")  != string::npos) bitMu23Ele12_DZ = 6;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v8")  != string::npos) bitMu23Ele12_DZ = 7;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v9")  != string::npos) bitMu23Ele12_DZ = 8;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v10") != string::npos) bitMu23Ele12_DZ = 9;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v11") != string::npos) bitMu23Ele12_DZ = 10;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v12") != string::npos) bitMu23Ele12_DZ = 11;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v13") != string::npos) bitMu23Ele12_DZ = 12;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v14") != string::npos) bitMu23Ele12_DZ = 13;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v15") != string::npos) bitMu23Ele12_DZ = 14;
    
    int bitMu23Ele12_noDZ = -1;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v1") != string::npos)  bitMu23Ele12_noDZ = 0;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v2") != string::npos)  bitMu23Ele12_noDZ = 1;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v3") != string::npos)  bitMu23Ele12_noDZ = 2;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v4") != string::npos)  bitMu23Ele12_noDZ = 3;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v5") != string::npos)  bitMu23Ele12_noDZ = 4;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v6") != string::npos)  bitMu23Ele12_noDZ = 5;
    if     (name.find("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v7") != string::npos)  bitMu23Ele12_noDZ = 6;

    int bitMu12Ele23_DZ = -1;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v1")  != string::npos)  bitMu12Ele23_DZ = 0;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v2")  != string::npos)  bitMu12Ele23_DZ = 1;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v3")  != string::npos)  bitMu12Ele23_DZ = 2;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v4")  != string::npos)  bitMu12Ele23_DZ = 3;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v5")  != string::npos)  bitMu12Ele23_DZ = 4;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v6")  != string::npos)  bitMu12Ele23_DZ = 5;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v7")  != string::npos)  bitMu12Ele23_DZ = 6;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v8")  != string::npos)  bitMu12Ele23_DZ = 7;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v9")  != string::npos)  bitMu12Ele23_DZ = 8;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v10") != string::npos)  bitMu12Ele23_DZ = 9;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v11") != string::npos)  bitMu12Ele23_DZ = 10;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v12") != string::npos)  bitMu12Ele23_DZ = 11;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v13") != string::npos)  bitMu12Ele23_DZ = 12;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v14") != string::npos)  bitMu12Ele23_DZ = 13;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v15") != string::npos)  bitMu12Ele23_DZ = 14;

    int bitMu12Ele23_noDZ = -1;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v1")  != string::npos)  bitMu12Ele23_noDZ = 0;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v2")  != string::npos)  bitMu12Ele23_noDZ = 1;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v3")  != string::npos)  bitMu12Ele23_noDZ = 2;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v4")  != string::npos)  bitMu12Ele23_noDZ = 3;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v5")  != string::npos)  bitMu12Ele23_noDZ = 4;
    if     (name.find("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v6")  != string::npos)  bitMu12Ele23_noDZ = 5;
    
    //printf(" Reading trigger: %s\n" , name.c_str()  );
    //printf(" bitEle23Loose      %d \n", bitEle23Loose      ); 
    //printf(" bitEle27Tight      %d \n", bitEle27Tight      ); 
    //printf(" bitEle17Ele12      %d \n", bitEle17Ele12      ); 
    //printf(" bitEle23Ele12      %d \n", bitEle23Ele12      ); 
    //printf(" bitIsoMu22         %d \n", bitIsoMu22         ); 
    //printf(" bitIsoTkMu22       %d \n", bitIsoTkMu22       ); 
    //printf(" bitMu17Mu8         %d \n", bitMu17Mu8         ); 
    //printf(" bitMu17TkMu8       %d \n", bitMu17TkMu8       ); 
    
    // indicates prescaling and whether trigger was fired or not
    unsigned int isPrescaled = (hltPrescale_.prescaleValue(e,es,name)) != 1;
    const unsigned int triggerIndex = hltConfig_.triggerIndex(name);
    unsigned int isFired     = AODTriggerHandle_->accept(triggerIndex);
    //cout << "was run " << AODTriggerHandle_->wasrun(triggerIndex) << endl; //check, doesnt seem to work, but same behavior as in 2016 version
    //std::cout<<name<<"   isPrescaled:"<<isPrescaled<<"    isFired:"<<isFired<<std::endl;
    // if statement checks if trigger was present (any version XXX_vN)
    // set the bit N of our trigger variable to 1 or 0 based on isFired
    // DoubleEle
    if ( bitDoubleEle33           >= 0 ){     
      AOD_HLT_DoubleEle33_            |= (isFired     << bitDoubleEle33      );
      AOD_HLT_DoubleEle33_isPS_       |= (isPrescaled << bitDoubleEle33      );
    }
    if ( bitEle23Ele12           >= 0 ){     
      AOD_HLT_Ele23Ele12_            |= (isFired     << bitEle23Ele12      );
      AOD_HLT_Ele23Ele12_isPS_       |= (isPrescaled << bitEle23Ele12      );
    }
    if ( bitEle23Ele12_noDZ      >= 0 ){     
      AOD_HLT_Ele23Ele12_noDZ_       |= (isFired     << bitEle23Ele12_noDZ      );
      AOD_HLT_Ele23Ele12_noDZ_isPS_  |= (isPrescaled << bitEle23Ele12_noDZ      );
    }
    // Double Mu
    if ( bitMu17Mu8              >= 0 ){   
      AOD_HLT_Mu17Mu8_               |= (isFired     << bitMu17Mu8         );
      AOD_HLT_Mu17Mu8_isPS_          |= (isPrescaled << bitMu17Mu8         );
    }
    if ( bitMu17Mu8_Mass8              >= 0 ){   
      AOD_HLT_Mu17Mu8_Mass8_               |= (isFired     << bitMu17Mu8_Mass8         );
      AOD_HLT_Mu17Mu8_Mass8_isPS_          |= (isPrescaled << bitMu17Mu8_Mass8         );
    }
    if ( bitMu17Mu8_Mass3p8              >= 0 ){   
      AOD_HLT_Mu17Mu8_Mass3p8_               |= (isFired     << bitMu17Mu8_Mass3p8         );
      AOD_HLT_Mu17Mu8_Mass3p8_isPS_          |= (isPrescaled << bitMu17Mu8_Mass3p8         );
    }
   // if ( bitMu17TkMu8            >= 0 ){     
   //   AOD_HLT_Mu17TkMu8_             |= (isFired     << bitMu17TkMu8       );
   //   AOD_HLT_Mu17TkMu8_isPS_        |= (isPrescaled << bitMu17TkMu8       );
   // }
    if ( bitMu17Mu8_noDZ         >= 0 ){   
      AOD_HLT_Mu17Mu8_noDZ_          |= (isFired     << bitMu17Mu8_noDZ    );
      AOD_HLT_Mu17Mu8_noDZ_isPS_     |= (isPrescaled << bitMu17Mu8_noDZ    );
    }
   // if ( bitMu17TkMu8_noDZ       >= 0 ){     
   //   AOD_HLT_Mu17TkMu8_noDZ_        |= (isFired     << bitMu17TkMu8_noDZ  );
   //   AOD_HLT_Mu17TkMu8_noDZ_isPS_   |= (isPrescaled << bitMu17TkMu8_noDZ  );
   // }
    // EMU/MuE
    if ( bitMu8Ele23_DZ >= 0 ){
      AOD_HLT_Mu8Ele23_DZ_       |= (isFired     << bitMu8Ele23_DZ );
      AOD_HLT_Mu8Ele23_DZ_isPS_  |= (isPrescaled << bitMu8Ele23_DZ );
    }
    if ( bitMu8Ele23_noDZ >= 0 ){
      AOD_HLT_Mu8Ele23_noDZ_       |= (isFired     << bitMu8Ele23_noDZ );
      AOD_HLT_Mu8Ele23_noDZ_isPS_  |= (isPrescaled << bitMu8Ele23_noDZ );
    }
    if ( bitMu23Ele12_DZ >= 0 ){
      AOD_HLT_Mu23Ele12_DZ_       |= (isFired     << bitMu23Ele12_DZ );
      AOD_HLT_Mu23Ele12_DZ_isPS_  |= (isPrescaled << bitMu23Ele12_DZ );
    }
    if ( bitMu23Ele12_noDZ >= 0 ){
      AOD_HLT_Mu23Ele12_noDZ_       |= (isFired     << bitMu23Ele12_noDZ );
      AOD_HLT_Mu23Ele12_noDZ_isPS_  |= (isPrescaled << bitMu23Ele12_noDZ );
    }
    if ( bitMu12Ele23_DZ >= 0 ){
      AOD_HLT_Mu12Ele23_DZ_       |= (isFired     << bitMu12Ele23_DZ );
      AOD_HLT_Mu12Ele23_DZ_isPS_  |= (isPrescaled << bitMu12Ele23_DZ );
    }
    if ( bitMu12Ele23_noDZ >= 0 ){
      AOD_HLT_Mu12Ele23_noDZ_       |= (isFired     << bitMu12Ele23_noDZ );
      AOD_HLT_Mu12Ele23_noDZ_isPS_  |= (isPrescaled << bitMu12Ele23_noDZ );
    }
    
  }//hltConfig loop
  
}//fillAODTrigger
