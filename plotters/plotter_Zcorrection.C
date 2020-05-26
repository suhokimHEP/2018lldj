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

void plotter_Zcorrection(TString region, TString varname, Bool_t dolog)
{

 // Setup running configuration: IO, naming, SFs, ..
 /////////////////////////////////////////////////////

 TString inpath  = TString("../plots/");
 TString outpath = TString("../plots/");
 TString aversion = TString(getenv("aversion"));

 inpath = inpath+aversion+"/"+region+"/log/";
 outpath = outpath+aversion+"/"+region+"/log/";

 Float_t lumiABCD = 45670. ;

 Int_t rebin=1;

 TString eraname = "";

 TString extraname = "";
 if(dolog){
  extraname+="_log";
 }

 TString infilename = region+"_"+varname+eraname+"_log";
 // std::cout<<"name: "<<inpath<<" "<<infilename<<std::endl;

 // canvas and text attributes
 int canx = 1100;
 int cany = 1200;
 float lmarg = 0.12;
 float rmarg = 0.05;
 

 // initialize histogram file / histograms
 TFile* file_input       ; 
 TH1F* h_DY     ;
 TH1F* h_GJets  ;
 TH1F* h_ST     ;
 TH1F* h_VV     ;
 TH1F* h_VG     ;
 TH1F* h_QCD    ;
 TH1F* h_ZH     ;
 TH1F* h_TT     ;
 TH1F* h_WJetsToLNu;
 TH1F* h_bkgtotal ;
 TH1F* h_altDY ;
 TH1F* h_altVV ;
 TH1F* h_altTT ;
 TH1F* h_Sig ;
 TH1F* h_Sig40 ;
 TH1F* h_Data   ;
 TH1F* bgstack;

 TH1F* h_DataInt;
 TH1F* h_MCInt;

 TH1F* hZsf;

 // load common histogram files / histograms
 file_input = new TFile( inpath + infilename + ".root"               ) ; 
 h_DY             = (TH1F*)file_input->Get("DY"            )->Clone("DY"            )  ;
 h_WJetsToLNu     = (TH1F*)file_input->Get("WJetsToLNu"    )->Clone("WJetsToLNu"    )  ;
 h_ST             = (TH1F*)file_input->Get("ST"            )->Clone("ST"            )  ;
 h_VV             = (TH1F*)file_input->Get("VV"            )->Clone("VV"            )  ;
 h_VG             = (TH1F*)file_input->Get("VG"            )->Clone("VG"            )  ;
 h_QCD            = (TH1F*)file_input->Get("QCD"           )->Clone("QCD"           )  ;
 h_ZH             = (TH1F*)file_input->Get("ZH"            )->Clone("ZH"            )  ;
 h_TT             = (TH1F*)file_input->Get("TT"            )->Clone("TT"            )  ;
 h_altDY          = (TH1F*)file_input->Get("altDY"         )->Clone("altDY"         )  ;
 h_altVV          = (TH1F*)file_input->Get("altVV"         )->Clone("altVV"         )  ;
 h_altTT          = (TH1F*)file_input->Get("altTT"         )->Clone("altTT"         )  ;
 h_Data           = (TH1F*)file_input->Get("Data"          )->Clone("Data"          )  ;



   TString outname = region+"_"+varname+eraname+extraname;
   outname = outpath + outname;
   //std::cout<<outname<<std::endl;


   h_bkgtotal       = (TH1F*)file_input->Get("bkgtotal"      )->Clone("bkgtotal"      )  ;

   //THStack *bgstack = new THStack("bgstack","");
   bgstack = new TH1F();
   TString outhistname = "Zsf_"+varname;
   
   hZsf = new TH1F(outhistname,outhistname,100,0,200);
   //bgstack->Add(h_DY         );
   bgstack->Add(h_ST         );
   bgstack->Add(h_TT         );
   bgstack->Add(h_WJetsToLNu ); 
   //bgstack->Add(h_altVV         );
   bgstack->Add(h_VV         );
   bgstack->Add(h_VG         );
   bgstack->Add(h_QCD        );
   bgstack->Add(h_ZH         );
   // make legend
  
  

   h_DataInt  = (TH1F*)h_Data->Clone("h_DataInt"     );
   h_MCInt    = (TH1F*)h_bkgtotal->Clone("h_MCInt" );

   int nbins = h_DataInt->GetNbinsX();
   //std::cout<<" nbins data "<<nbins<<" mc"<<h_MCInt->GetNbinsX()<<std::endl;
   for( int j=1; j<nbins+1; ++j){
    float databinint = h_Data->GetBinContent(j);
    float lowedgeint = h_Data->GetBinLowEdge(j);
    float mcbinint = bgstack->GetBinContent(j);
    float DYbinint = h_DY->GetBinContent(j);
    //std::cout<<"bin number:"<<j<<" with Lowedge:"<<lowedgeint<<endl;
    //std::cout<<"  datacontent "<<databinint<<endl;
    //std::cout<<" MCcontent "<<mcbinint<<std::endl;
    //std::cout<<" DYcontent "<<DYbinint<<std::endl;
    float Zsf = (databinint-mcbinint)/DYbinint;
    //std::cout<<" ratio "<<(databinint-mcbinint)/DYbinint<<endl;
    hZsf->Fill(lowedgeint,Zsf);
    //std::cout<<"-------------"<<endl;
   // datasum = datasum + databinint;
   // mcsum = mcsum + mcbinint;
   // h_DataInt->SetBinContent(j,datasum);
   // h_MCInt->SetBinContent(j,mcsum);
   }
   TString outrootname = "Zsf_"+varname;
   TFile *newfile = new TFile(outrootname+".root","recreate");
   hZsf->Write();



      

}
