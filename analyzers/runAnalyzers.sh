#!/bin/bash

for sample in \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"  \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"  \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-1"  \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-1"  \

do
#  ./runanalyzer.exe -s ${sample} -l "20000" -x "" -e "-1" -i "../lists" -o "junk" -n 999999999 -a 1 -d -m
  ./runanalyzer.exe -s ${sample} -l "20000" -x "" -e "-1" -i "../lists" -o "junk" -n 1000 -a 1 -d -m

done #for sample in DY50..

#for sample in \
# "Data_MuonEG_D"    \
# "Data_DoubleMuon_D"    \
#
#do
#  ./runanalyzer.exe -s ${sample} -l "20000" -x "" -e "100000" -i "../lists" -o "junk" -n 10 -a 1 -d
#done # for datasample               
