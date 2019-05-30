#!/bin/bash

# Makes a list of files in eos
# then greps through to separate into samples
# 
# output files are xxx/lists/<sample>.list
# formatted as one file per line: /store/group/xxx.root

# don't forget to source setup.sh (from xxx/LLDJstandalones)
mkdir -p "${listdir}"

makealist() {
 printf "Making %s\n" $1
 fullsamplename=$(grep -i "$2" ${listdir}/allfiles.masterlist)
 printf "%s\n"  ${fullsamplename} > ${listdir}/$1.list
 sed -i -e "s@/eos/uscms@@" ${listdir}/$1.list
}

### MC backgrounds
#
## DY
makealist "DYJetsToLL_M-50"            "/DYJetsToLL_M-50_"
#
## WJets
makealist "WJetsToLNu"      "/WJetsToLNu_"
#
## TTbar
makealist "TTJets"          "/TTJets_TuneCP5"
#
## Single Top
makealist "ST_t-channel_antitop_4f_inclusiveDecays"    "/ST_t-channel_antitop_4f_inclusiveDecays_"
makealist "ST_tW_antitop_5f_NoFullyHadronicDecays"     "/ST_tW_antitop_5f_NoFullyHadronicDecays_"
makealist "ST_s-channel_4f_leptonDecays"               "/ST_s-channel_4f_leptonDecays_"
makealist "ST_t-channel_top_4f_inclusiveDecays"        "/ST_t-channel_top_4f_inclusiveDecays_"
makealist "ST_tW_top_5f_NoFullyHadronicDecays"         "/ST_tW_top_5f_NoFullyHadronicDecays_"
#
## Diboson
makealist "WW"                    "/WW_"
makealist "WZ"                    "/WZ_"
makealist "ZZ"                    "/ZZ_"
#
## VGamma
#makealist "ZGTo2LG"                "/ZGTo2LG_"
makealist "WGToLNuG"               "/WGToLNuG_"
#
## ZH
#makealist "ggZH_HToBB_ZToLL"       "/ggZH_HToBB_ZToLL_"
#makealist "ZH_HToBB_ZToLL"         "/ZH_HToBB_ZToLL_M125_"
#
##QCD 
makealist "QCD_HT100to200"      "/QCD_HT100to200_"
makealist "QCD_HT200to300"      "/QCD_HT200to300_"
makealist "QCD_HT300to500"      "/QCD_HT300to500_"
makealist "QCD_HT500to700"      "/QCD_HT500to700_"
makealist "QCD_HT700to1000"     "/QCD_HT700to1000_"
makealist "QCD_HT1000to1500"    "/QCD_HT1000to1500_"
makealist "QCD_HT1500to2000"    "/QCD_HT1500to2000_"
makealist "QCD_HT2000toInf"     "/QCD_HT2000toInf_"
##
## Data
makealist "Data_DoubleMuon_B"          "/DoubleMuon/crab_Data_DoubleMuon_B"
makealist "Data_DoubleMuon_C"          "/DoubleMuon/crab_Data_DoubleMuon_C"
makealist "Data_DoubleMuon_D"          "/DoubleMuon/crab_Data_DoubleMuon_D"
makealist "Data_DoubleMuon_E"          "/DoubleMuon/crab_Data_DoubleMuon_E"
makealist "Data_DoubleMuon_F"          "/DoubleMuon/crab_Data_DoubleMuon_F"
##
makealist "Data_DoubleEG_B"          "/DoubleEG/crab_Data_DoubleEG_B"
makealist "Data_DoubleEG_C"          "/DoubleEG/crab_Data_DoubleEG_C"
makealist "Data_DoubleEG_D"          "/DoubleEG/crab_Data_DoubleEG_D"
makealist "Data_DoubleEG_E"          "/DoubleEG/crab_Data_DoubleEG_E"
makealist "Data_DoubleEG_F"          "/DoubleEG/crab_Data_DoubleEG_F"
##
makealist "Data_MuonEG_B"          "/MuonEG/crab_Data_MuonEG_B"
makealist "Data_MuonEG_C"          "/MuonEG/crab_Data_MuonEG_C"
makealist "Data_MuonEG_D"          "/MuonEG/crab_Data_MuonEG_D"
makealist "Data_MuonEG_E"          "/MuonEG/crab_Data_MuonEG_E"
makealist "Data_MuonEG_F"          "/MuonEG/crab_Data_MuonEG_F"


### Imported from 2016 version
#
## DY
#makealist "DYJetsToLL_M-5to50_HT-70to100"            "/DYJetsToLL_M-5to50_HT-70to100_"
#makealist "DYJetsToLL_M-5to50_HT-100to200"           "/DYJetsToLL_M-5to50_HT-100to200_"
#makealist "DYJetsToLL_M-5to50_HT-200to400"           "/DYJetsToLL_M-5to50_HT-200to400_"
#makealist "DYJetsToLL_M-5to50_HT-400to600"           "/DYJetsToLL_M-5to50_HT-400to600_"
#makealist "DYJetsToLL_M-5to50_HT-600toInf"           "/DYJetsToLL_M-5to50_HT-600toInf_"
#makealist "DYJetsToLL_M-10to50"                      "/DYJetsToLL_M-10to50_"
#makealist "DYJetsToLL_M-50"                          "/DYJetsToLL_M-50_"
#
## WJets
#makealist "WJetsToLNu"      "/WJetsToLNu_"
#
## TTbar
#makealist "TTJets"          "/TTJets_TuneCUETP8M"
#makealist "TTtoLL"          "/TTJets_DiLept_"
#makealist "TTtoLfromTbar"   "/TTJets_SingleLeptFromTbar_"
#makealist "TTtoLfromT"      "/TTJets_SingleLeptFromT_"
#
## Single Top
#makealist "ST_s-channel_4f_leptonDecays"               "/ST_s-channel_4f_leptonDecays_"
#makealist "ST_t-channel_antitop_4f_inclusiveDecays"    "/ST_t-channel_antitop_4f_inclusiveDecays_"
#makealist "ST_t-channel_top_4f_inclusiveDecays"        "/ST_t-channel_top_4f_inclusiveDecays_"
#makealist "ST_tW_antitop_5f_NoFullyHadronicDecays"     "/ST_tW_antitop_5f_NoFullyHadronicDecays_"
#makealist "ST_tW_top_5f_NoFullyHadronicDecays"         "/ST_tW_top_5f_NoFullyHadronicDecays_"
#
## GJets
#makealist "GJets_HT-40To100"       "/GJets_HT-40To100_"
#makealist "GJets_HT-100To200"      "/GJets_HT-100To200_"
#makealist "GJets_HT-200To400"      "/GJets_HT-200To400_"
#makealist "GJets_HT-400To600"      "/GJets_HT-400To600_"
#makealist "GJets_HT-600ToInf"      "/GJets_HT-600ToInf_"
#
## Diboson
#makealist "WW"                    "/WW_"
#makealist "WZ"                    "/WZ_"
#makealist "ZZ"                    "/ZZ_"
#makealist "WWTo2L2Nu"             "/WWTo2L2Nu_"
#makealist "WWToLNuQQ"             "/WWToLNuQQ_"
#makealist "WZTo1L3Nu"             "/WZTo1L3Nu_"
#makealist "WZTo3LNu"              "/WZTo3LNu_"
#makealist "WZToLNu2QorQQ2L"       "/WZToLNu2QorQQ2L_"
#makealist "ZZTo2L2Nu"             "/ZZTo2L2Nu_"
#makealist "ZZTo2L2Q"              "/ZZTo2L2Q_"
#makealist "ZZTo2Q2Nu"             "/ZZTo2Q2Nu_"
#makealist "ZZTo4L"                "/ZZTo4L_"
#
## VGamma
#makealist "ZGTo2LG"                "/ZGTo2LG_"
#makealist "WGToLNuG"               "/WGToLNuG_"
#
## ZH
#makealist "ggZH_HToBB_ZToLL"       "/ggZH_HToBB_ZToLL_"
#makealist "ZH_HToBB_ZToLL"         "/ZH_HToBB_ZToLL_M125_"
#
##QCD 
#makealist "QCD_HT100to200"      "/QCD_HT100to200_"
#makealist "QCD_HT200to300"      "/QCD_HT200to300_"
#makealist "QCD_HT300to500"      "/QCD_HT300to500_"
#makealist "QCD_HT500to700"      "/QCD_HT500to700_"
#makealist "QCD_HT700to1000"     "/QCD_HT700to1000_"
#makealist "QCD_HT1000to1500"    "/QCD_HT1000to1500_"
#makealist "QCD_HT1500to2000"    "/QCD_HT1500to2000_"
#makealist "QCD_HT2000toInf"     "/QCD_HT2000toInf_"
#
## Signal Samples
#makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"       "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1_"
#makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"      "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10_"
#makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"     "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100_"
#makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000"    "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000_"
#makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"         "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1_"
#makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"        "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10_"
#makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"       "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100_"
#makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000"      "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000_"
#makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"       "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1_"
#makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"      "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10_"
#makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"     "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_"
#makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000"    "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000_"
#makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"         "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1_"
#makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"        "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10_"
#makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"       "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_"
#makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000"      "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000_"
#makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"       "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1_"
#makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"      "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10_"
#makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"     "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100_"
#makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000"    "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000_"
#makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"         "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1_"
#makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"        "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10_"
#makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"       "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100_"
#makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000"      "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000_"
