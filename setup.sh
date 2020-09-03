#!/bin/bash

export depot="/eos/uscms/store/group/lpchbb/LLDJntuples"
export depot2="/store/group/lpchbb/LLDJntuples"
export FWVersion="2018lldj"
export nversion="2016_LLDJ_V3p0"
#export aversion="2017Comparisons_noPUWeights_simTrig"
#export aversion="DanielTag_wShift_16AMFull"
#export aversion="DanielTag_wShift_16AM"
export aversion="InclusiveZ"

#-- Where Daniel Keeps ZDark and ZH stuff for AN Apr. 2020; 
#export nversion="2018_LLDJ"
#export aversion="PUWeights_Shifts_ZDark_ZPt100_mainh500" #
#export aversion="PUWeights_Shifts_ZDark_ZPt50_mainh150" #

pushd `dirname ${BASH_SOURCE[0]}` > /dev/null
export basedir=`pwd`
popd > /dev/null

export listdir="${basedir}/lists"
export rootdir="${basedir}/roots"
export plotdir="${basedir}/plots"
#export andir="${basedir}/analysis"

export subdir="${basedir}/ntuples/config"
export asubdir="${basedir}/submitters"
