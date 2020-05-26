#include <iostream>
#include "TString.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TLegend.h"
#include "TPad.h"
#include "TStyle.h"
#include "TText.h"
#include "TFile.h"
#include <stdio.h>
#include <cstdlib> /* mkdir */

#include <stdlib.h>     /* getenv */

//using namespace std;

void plotter_binshift(TString region, TString varname, Bool_t dolog)
{

 // Setup running configuration: IO, naming, SFs, ..
 /////////////////////////////////////////////////////

 TString inpath  = TString("../roots/");
 TString outpath = TString("../plots/");
 TString aversion = TString(getenv("aversion"));

 if(useEOS){
  inpath = "root://cmsxrootd.fnal.gov/"+depot+"/"+nversion+"/analyzed/"; 
}
 inpath = inpath+aversion+"/";
 outpath = outpath+aversion+"/"+region+"/";

 Float_t lumiABCD = 45670. ;

 Int_t rebin=1;

 TString eraname = "";

 TString extraname = "";
 if(dolog){
  extraname+="_log";
 }

 // canvas and text attributes
 std::vector<TString> Samples;
 Samples.push_back("DYJetsToLL_M-50"); 
 std::vector<string> Shift_index;
 Shift_index.push_back("1"); 

 for(unsigned int i=0; i<Samples.size(); ++i){
TString sample = Samples.at(i);
 for(unsigned int j=0; j<Samples.size(); ++j){
TString index = Shift_index.at(j);
 // initialize histogram file / histograms
 TFile* file_input       ; 
 TH1F* h_Data   ;
 TH1F* bgstack;

 TH1F* h_DataInt;
 TH1F* h_MCInt;
TString hname_AODCaloJetAlphaMax                      = "h_"+region+"_Shift_"+index+"AllJets_AODCaloJetAlphaMax"; 
TString hname_AODCaloJetMedianLog10IPSig              = "h_"+region+"_Shift_"+index+"AllJets_AODCalojetMedianLog10IPSig"; 
TString hname_AODCaloJetMedianLog10TrackAngle         = "h_"+region+"_Shift_"+index+"AllJets_AODCaloJetMedianLog10TrackAngle"; 
h_AODCaloJetAlphaMax              = new TH1F( hname_AODCaloJetAlphaMax                       , hname_AODCaloJetAlphaMax             , 120, 0, 1.2  ); 
h_AODCaloJetMedianLog10IPSig      = new TH1F( hname_AODCaloJetMedianLog10IPSig               , hname_AODCaloJetMedianLog10IPSig     , 100, -3, 4 ); 
h_AODCaloJetMedianLog10TrackAngle = new TH1F( hname_AODCaloJetMedianLog10TrackAngle          , hname_AODCaloJetMedianLog10TrackAngle, 100, -5, 2 ); 


 // load common histogram files / histograms
 file_input                    = TFile::Open( inpath + sample +"_"+region+"_histograms.root"                 ) ;
 searchname = region+"_"+varname;
 h_AM             = (TH1F*)file_input->Get("h_"+searchname            )->Clone("AM"            )  ;
 h_IPSig             = (TH1F*)file_input->Get("h_"+searchname            )->Clone("IPSig"            )  ;
 h_TA             = (TH1F*)file_input->Get("h_"+searchname            )->Clone("TA"            )  ;



   int AMbins = h_AM->GetNbinsX();
   int IPSigbins = h_IPSig->GetNbinsX();
   int TAbins = h_TA->GetNbinsX();
   for( int k=1; k<AMbins+1; ++k){
    float binvalue = h_AM->GetBinContent(k);
    h_AODCaloJetAlphaMax->Fill(k-1,binvalue);
   }
   for( int l=1; l<IPSigbins+1; ++l){
    float binvalue = h_IPSig->GetBinContent(l);
    h_AODCaloJetMedianLog10IPSig->Fill(l-1,binvalue);
   }
   for( int m=1; m<TAbins+1; ++m){
    float binvalue = h_TA->GetBinContent(l);
    h_AODCaloJetMedianLog10TrackAngle->Fill(m-1,binvalue);
   }

    h_AODCaloJetAlphaMax->Write();
    h_AODCaloJetMedianLog10IPSig->Write();
    h_AODCaloJetMedianLog10TrackAngle->Write();


}
}      

}
