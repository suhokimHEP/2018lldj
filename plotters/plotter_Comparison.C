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

void plotter_Comparison(TString region, TString varname, Bool_t dolog)
{

 // Setup running configuration: IO, naming, SFs, ..
 /////////////////////////////////////////////////////

 TString inpath  = TString("../plots/");
 TString outpath = TString("../Compplots/");
 TString aversion = TString(getenv("aversion"));
 TString version1 = "byJetnum_forZpt_noShift_noJet_newbin_JEC_InclusiveZ";
 TString version2 = "byJetnum_forZpt_noShift_noJet_newbin_InclusiveZ";
 TString inpath_one = inpath+version1+"/"+region+"/log/";
 TString inpath_two = inpath+version2+"/"+region+"/log/";
 //outpath = outpath+region+"/log/";
 if (varname =="nSelectedAODCaloJet"||varname=="nSelectedAODCaloJetTag") {dolog=true;}
 outpath = outpath;

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
 int cany = 900;
 float lmarg = 0.12;
 float rmarg = 0.05;

 //TCanvas* canvas = new TCanvas("canvas","canvas",canx,cany); 

 //gStyle->SetOptStat(0);
 //gPad->SetLogy();
 //gPad->SetTickx();
 //gPad->SetTicky();
 //gStyle->SetLineWidth(3);
 //gStyle->SetPalette(kBird);

 //canvas->Clear();
 //canvas->cd();

 //float pad_bottom = 0;
 //TPad *plotpad  = new TPad("plotpad", "plotpad", 0, pad_bottom, 1, 1);
 //plotpad->SetBottomMargin(0.12);
 //plotpad->SetLeftMargin(0.13);
 //plotpad->SetFrameLineWidth(3);
 //plotpad->SetLogy();
 //plotpad->Draw();

 //canvas->cd();

 TText* title = new TText(1,1,"") ;
 title->SetTextSize(0.045);
 title->SetTextColor(kBlack);
 title->SetTextAlign(11);
 title->SetTextFont(62);
 
 TText* extra = new TText(1,1,"") ;
 extra->SetTextSize(0.03);
 extra->SetTextColor(kBlack);
 extra->SetTextAlign(11);
 extra->SetTextFont(52);
 
 TLatex* extra2 = new TLatex(1,1,"") ;
 extra2->SetTextSize(0.025);
 extra2->SetTextColor(kBlack);
 extra2->SetTextAlign(11);
 extra2->SetTextFont(62);
 
 // initialize histogram file / histograms
 TFile* file_one_input       ; 
 TH1F* h_one_DY     ;
 TH1F* h_one_GJets  ;
 TH1F* h_one_ST     ;
 TH1F* h_one_VV     ;
 TH1F* h_one_VG     ;
 TH1F* h_one_QCD    ;
 TH1F* h_one_ZH     ;
 TH1F* h_one_TT     ;
 TH1F* h_one_WJetsToLNu;
 TH1F* h_one_bkgtotal ;
 TH1F* h_one_altDY ;
 TH1F* h_one_altVV ;
 TH1F* h_one_altTT ;
 TH1F* h_one_Sig ;
 TH1F* h_one_Sig_MS55ct100 ;
 TH1F* h_one_Data   ;
 TFile* file_two_input       ; 
 TH1F* h_two_DY     ;
 TH1F* h_two_GJets  ;
 TH1F* h_two_ST     ;
 TH1F* h_two_VV     ;
 TH1F* h_two_VG     ;
 TH1F* h_two_QCD    ;
 TH1F* h_two_ZH     ;
 TH1F* h_two_TT     ;
 TH1F* h_two_WJetsToLNu;
 TH1F* h_two_bkgtotal ;
 TH1F* h_two_altDY ;
 TH1F* h_two_altVV ;
 TH1F* h_two_altTT ;
 TH1F* h_two_Sig ;
 TH1F* h_two_Sig_MS55ct100 ;
 TH1F* h_two_Data   ;
   TString outname = region+"_"+varname+eraname+extraname;
   outname = outpath + outname;
   //std::cout<<outname<<std::endl;

 // load common histogram files / histograms
 file_one_input = new TFile( inpath_one + infilename + ".root"               ) ; 
 h_one_Data           = (TH1F*)file_one_input->Get("Data"          )->Clone("Data"          )  ;
 h_one_bkgtotal       = (TH1F*)file_one_input->Get("bkgtotal"      )->Clone("bkgtotal"      )  ;
 h_one_Sig_MS55ct100       = (TH1F*)file_one_input->Get("Sig_MS55ct100"      )->Clone("Sig_MS55ct100"      )  ;
 file_two_input = new TFile( inpath_two + infilename + ".root"               ) ; 
 h_two_Data           = (TH1F*)file_two_input->Get("Data"          )->Clone("Data"          )  ;
 h_two_bkgtotal       = (TH1F*)file_two_input->Get("bkgtotal"      )->Clone("bkgtotal"      )  ;
 h_two_Sig_MS55ct100       = (TH1F*)file_two_input->Get("Sig_MS55ct100"      )->Clone("Sig_MS55ct100"      )  ;

 h_one_Data     ->SetLineColor(kRed); 
 h_one_bkgtotal     ->SetLineColor(kRed); 
 h_one_Sig_MS55ct100     ->SetLineColor(kRed); 
 h_two_Data     ->SetLineColor(kBlack); 
 h_two_bkgtotal     ->SetLineColor(kBlack); 
 h_two_Sig_MS55ct100     ->SetLineColor(kBlack);

 TCanvas* c1 = new TCanvas("canvas","canvas",200,10,700,900); 


 c1->SetGrid();
 gPad->SetLeftMargin(0.13);
 gPad->SetBottomMargin(0.12);
 if(dolog){gPad->SetLogy();}
 gPad->SetTickx();
 gPad->SetTicky();
 gStyle->SetOptStat(0);
 gStyle->SetLineWidth(3);
 gStyle->SetHistLineWidth(3);
 c1->cd();

 h_one_bkgtotal     ->Draw("HIST"); 
 h_two_bkgtotal     ->Draw("HIST SAME"); 
      
     TLegend *legend;
legend = new TLegend(0.65,0.55,0.85,0.75); 		
legend->SetBorderSize(0);
//legend->SetNColumns(2);
legend->SetFillColor(kWhite);
legend->AddEntry(h_one_bkgtotal,"bkgtotal_JEC","l");
legend->AddEntry(h_two_bkgtotal,"bkgtotal_NoJEC","l");
legend->SetTextSize(0.025);
legend->Draw();

title->DrawTextNDC(0.2,0.91,"CMS");
extra->DrawTextNDC(0.3,0.91,"Preliminary");
extra2->DrawLatexNDC(0.55,0.91,"2018 No JEC v. JEC");
c1->Modified();
c1->Update();
//c1->SaveAs(outpath+version1+"_vs_"+version2+"_"+varname+".png");
c1->SaveAs(outpath+region+"_"+varname+"_bkgtotal.png");

 TCanvas* c2 = new TCanvas("canvas","canvas",200,10,700,900); 


 c2->SetGrid();
 gPad->SetLeftMargin(0.13);
 gPad->SetBottomMargin(0.12);
 if(dolog){gPad->SetLogy();}
 gPad->SetTickx();
 gPad->SetTicky();
 gStyle->SetOptStat(0);
 gStyle->SetLineWidth(3);
 gStyle->SetHistLineWidth(3);
 c2->cd();

 h_one_Data     ->Draw("HIST"); 
 h_two_Data     ->Draw("HIST SAME"); 
      
     TLegend *legend2;
legend2 = new TLegend(0.65,0.55,0.85,0.75); 		
legend2->SetBorderSize(0);
//legend2->SetNColumns(2);
legend2->SetFillColor(kWhite);
legend2->AddEntry(h_one_Data,"DoubleMu_JEC","l");
legend2->AddEntry(h_two_Data,"DoubleMu_NoJEC","l");
legend2->SetTextSize(0.025);
legend2->Draw();

title->DrawTextNDC(0.2,0.91,"CMS");
extra->DrawTextNDC(0.3,0.91,"Preliminary");
extra2->DrawLatexNDC(0.55,0.91,"2018 No JEC v. JEC");
c2->Modified();
c2->Update();
//c2->SaveAs(outpath+version1+"_vs_"+version2+"_"+varname+".png");
c2->SaveAs(outpath+region+"_"+varname+"_DoubleMu.png");

 TCanvas* c3 = new TCanvas("canvas","canvas",200,10,700,900); 


 c3->SetGrid();
 gPad->SetLeftMargin(0.13);
 gPad->SetBottomMargin(0.12);
 if(dolog){gPad->SetLogy();}
 gPad->SetTickx();
 gPad->SetTicky();
 gStyle->SetOptStat(0);
 gStyle->SetLineWidth(3);
 gStyle->SetHistLineWidth(3);
 c3->cd();

 h_one_Sig_MS55ct100     ->Draw("HIST"); 
 h_two_Sig_MS55ct100     ->Draw("HIST SAME"); 
      
     TLegend *legend3;
legend3 = new TLegend(0.65,0.55,0.85,0.75); 		
legend3->SetBorderSize(0);
//legend3->SetNColumns(2);
legend3->SetFillColor(kWhite);
legend3->AddEntry(h_one_Data,"MS55ct100_JEC","l");
legend3->AddEntry(h_two_Data,"MS55ct100_NoJEC","l");
legend3->SetTextSize(0.025);
legend3->Draw();

title->DrawTextNDC(0.2,0.91,"CMS");
extra->DrawTextNDC(0.3,0.91,"Preliminary");
extra2->DrawLatexNDC(0.55,0.91,"2018 No JEC v. JEC");
c3->Modified();
c3->Update();
//c3->SaveAs(outpath+version1+"_vs_"+version2+"_"+varname+".png");
c3->SaveAs(outpath+region+"_"+varname+"_Sig.png");




}
