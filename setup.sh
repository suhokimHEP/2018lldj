#!/bin/bash

export depot="/eos/uscms/store/group/lpchbb/LLDJntuples"
export depot2="/store/group/lpchbb/LLDJntuples"
export FWVersion="2018lldj"
export nversion="2018_LLDJ"
#export aversion="2017Comparisons_noPUWeights_simTrig"
#export aversion="DanielTag_wShift_16AMFull"
#export aversion="DanielTag_wShift_16AM"
export aversion="TTOC"
#export aversion="DanielTag_noShift_16AM"

pushd `dirname ${BASH_SOURCE[0]}` > /dev/null
export basedir=`pwd`
popd > /dev/null

export listdir="${basedir}/lists"
export rootdir="${basedir}/roots"
export plotdir="${basedir}/plots"
#export andir="${basedir}/analysis"

export subdir="${basedir}/ntuples/config"
export asubdir="${basedir}/submitters"
