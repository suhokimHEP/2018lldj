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
###QCD 
#makealist "QCD_HT50to100"      "/QCD_HT50to100_"
#makealist "QCD_HT100to200"      "/QCD_HT100to200_"
#makealist "QCD_HT200to300"      "/QCD_HT200to300_"
#makealist "QCD_HT300to500"      "/QCD_HT300to500_"
#makealist "QCD_HT500to700"      "/QCD_HT500to700_"
#makealist "QCD_HT700to1000"     "/QCD_HT700to1000_"
#makealist "QCD_HT1000to1500"    "/QCD_HT1000to1500_"
#makealist "QCD_HT1500to2000"    "/QCD_HT1500to2000_"
#makealist "QCD_HT2000toInf"     "/QCD_HT2000toInf_"
###GJets
#makealist "GJets_HT-40To100"       "/GJets_HT-40To100_"
#makealist "GJets_HT-100To200"      "/GJets_HT-100To200_"
#makealist "GJets_HT-200To400"      "/GJets_HT-200To400_"
#makealist "GJets_HT-400To600"      "/GJets_HT-400To600_"
#makealist "GJets_HT-600ToInf"      "/GJets_HT-600ToInf_"
### DY
makealist "DYJetsToLL"            "/DYJetsToLL_"
##what about DY50_1_amc, DY10to50, DY5to50?, DY Jet dependency?
##
### TTbar
#makealist "TTJets"          "/TTJets_TuneCP5"
##what about TTJets_amc?
##are the TTtoLL samples all inclusive?
##
### Single Top
#makealist "ST_t-channel_antitop_4f_inclusiveDecays"    "/ST_t-channel_antitop_4f_inclusiveDecays_"
#makealist "ST_tW_antitop_5f_NoFullyHadronicDecays"     "/ST_tW_antitop_5f_NoFullyHadronicDecays_"
#makealist "ST_s-channel_4f_leptonDecays"               "/ST_s-channel_4f_leptonDecays_"
#makealist "ST_t-channel_top_4f_inclusiveDecays"        "/ST_t-channel_top_4f_inclusiveDecays_"
#makealist "ST_tW_top_5f_NoFullyHadronicDecays"         "/ST_tW_top_5f_NoFullyHadronicDecays_"
##what about STs_4?
##what about STtW_3, STtbarW_3?
##what about STt(bar)W inclusive?
##
### WJets
#makealist "WJetsToLNu"      "/WJetsToLNu_"
### Diboson
#makealist "WW"                    "/WW_"
#makealist "WZ"                    "/WZ_"
#makealist "ZZ"                    "/ZZ_"
#makealist "WWToLNuQQ"                    "/WWToLNuQQ_"
#makealist "WWTo4Q"                    "/WWTo4Q_"
#makealist "WWTo2L2Nu"                    "/WWTo2L2Nu_"
#makealist "WWTo1L1Nu2Q"                    "/WWTo1L1Nu2Q_"
#makealist "WZTo3LNu"                    "/WZTo3LNu_"
#makealist "WZTo2L2Q"                    "/WZTo2L2Q_"
#makealist "ZZTo4L"                    "/ZZTo4L_"
#makealist "ZZTo2Q2Nu"                    "/ZZTo2Q2Nu_"
#makealist "ZZTo2L2Q"                    "/ZZTo2L2Q_"
#makealist "ZZTo2L2Nu"                    "/ZZTo2L2Nu_"
##
### VGamma
##makealist "ZGTo2LG"                "/ZGTo2LG_"
#makealist "WGToLNuG"               "/WGToLNuG_"
##
### ZH
#makealist "ggZH_HToBB_ZToLL"       "/ggZH_HToBB_ZToLL_"
#makealist "ZH_HToBB_ZToLL"         "/ZH_HToBB_ZToLL_M125_"
##what about ZH_HToBB_v2?
###Signal
##makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"       "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1_"
##makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"      "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10_"
##makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"     "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100_"
##makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000"    "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000_"
##makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"         "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1_"
##makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"        "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10_"
##makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"       "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100_"
##makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000"      "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000_"
##makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"       "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1_"
##makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"      "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10_"
##makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"     "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_"
##makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000"    "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000_"
##makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"         "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1_"
##makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"        "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10_"
##makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"       "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_"
##makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000"      "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000_"
##makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"       "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1_"
##makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"      "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10_"
##makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"     "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100_"
##makealist "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000"    "/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000_"
##makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"         "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1_"
##makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"        "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10_"
##makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"       "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100_"
##makealist "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000"      "/ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000_"
#
###
### Data
###
#makealist "Data_DoubleMuon_A"          "/DoubleMuon/crab_Data_DoubleMuon_A"
#makealist "Data_DoubleMuon_B"          "/DoubleMuon/crab_Data_DoubleMuon_B"
#makealist "Data_DoubleMuon_C"          "/DoubleMuon/crab_Data_DoubleMuon_C"
#makealist "Data_DoubleMuon_D"          "/DoubleMuon/crab_Data_DoubleMuon_D"
###
#makealist "Data_EGamma_A"          "/EGamma/crab_Data_EGamma_A"
#makealist "Data_EGamma_B"          "/EGamma/crab_Data_EGamma_B"
#makealist "Data_EGamma_C"          "/EGamma/crab_Data_EGamma_C"
#makealist "Data_EGamma_D"          "/EGamma/crab_Data_EGamma_D"
###
#makealist "Data_MuonEG_A"          "/MuonEG/crab_Data_MuonEG_A"
#makealist "Data_MuonEG_B"          "/MuonEG/crab_Data_MuonEG_B"
#makealist "Data_MuonEG_C"          "/MuonEG/crab_Data_MuonEG_C"
#makealist "Data_MuonEG_D"          "/MuonEG/crab_Data_MuonEG_D"

