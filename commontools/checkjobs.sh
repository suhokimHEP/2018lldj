#!/bin/bash

# just calls the checker scripts automatically generated
# submission time in ${basedir}/submitters/gitignore/${aversion}/${sample}/checker.sh

printf "Files checked for completion after condor submition : \n"
printf "%50s %4s %4s \n" Sample Tot  Left

samples=( \
# "Data_DoubleMuon_A"         \
# "Data_DoubleMuon_B"         \
# "Data_DoubleMuon_C"         \
# "Data_DoubleMuon_D"         \
# "Data_EGamma_A"         \
# "Data_EGamma_B"         \
# "Data_EGamma_C"         \
# "Data_EGamma_D"         \
# "Data_MuonEG_A"         \
# "Data_MuonEG_B"         \
# "Data_MuonEG_C"         \
# "Data_MuonEG_D"         \
# "QCD_HT100to200"        \
# "QCD_HT200to300"        \
# "QCD_HT300to500"        \
# "QCD_HT500to700"        \
# "QCD_HT700to1000"       \
# "QCD_HT1000to1500"      \
# "QCD_HT1500to2000"      \
# "QCD_HT2000toInf"       \
# "DYJetsToLL_M-50"            \
# "mad_DYJetsToLL_M-50"            \
# "WJetsToLNu"     \
# "TTtoLL"          \
# "TTtoLL_mad"          \
# "TTJets"          \
# "mad_TTJets"          \
# "ST_s-channel_4f_leptonDecays"             \
# "ST_t-channel_antitop_4f_inclusiveDecays"  \
# "ST_t-channel_top_4f_inclusiveDecays"      \
# "ST_tW_antitop_5f_NoFullyHadronicDecays"   \
# "ST_tW_top_5f_NoFullyHadronicDecays"        \
# "WW"                 \
# "WZ"                 \
# "ZZ"                 \
# "WGToLNuG"              \
# "ZH_HToBB_ZToLL" 		\
# "ggZH_HToBB_ZToLL"		\
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-3"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-30"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-300"    \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-3"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-30"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-300"    \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-3"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-30"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-300"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-3"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-30"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-300"  \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-3"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-30"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-300"  \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-3"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-30"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-300"  \                                             
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"    \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"    \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"    \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"  \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000" \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"  \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000" \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"  \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000" \
)

totin=0
totleft=0

for sample in ${samples[@]}
do

 left=$(bash "${basedir}/submitters/gitignore/${aversion}/${sample}/checker.sh" | wc -l )
 lc=$( cat "${basedir}/submitters/gitignore/${aversion}/${sample}/checker.sh" | wc -l )

 totin=$(($totin+$lc))
 totleft=$(($totleft+$left))

 printf "%50s %4s %4s \n" ${sample} ${lc}  ${left}
 
done
 printf " --------------------------------------------------\n"
 printf "%50s %4s %4s \n" Total  $totin $totleft
