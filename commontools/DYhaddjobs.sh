#!/bin/bash

# just calls the hadd scripts automatically generated
# submission time in ${basedir}/submitters/gitignore/${aversion}/${sample}/haddit.sh

samples=( \
 "DYJetsToLL_M-50"            \
)

for sample in ${samples[@]}
do

 chmod +x "${basedir}/commontools/${aversion}/haddit_OPTtree.sh"
 chmod +x "${basedir}/commontools/${aversion}/haddit_TwoEleDY_histograms.sh"    
 chmod +x "${basedir}/commontools/${aversion}/haddit_TwoMuDY_histograms.sh"    
 chmod +x "${basedir}/commontools/${aversion}/haddit_TwoEleZH_histograms.sh"    
 chmod +x "${basedir}/commontools/${aversion}/haddit_TwoMuZH_histograms.sh"    
 chmod +x "${basedir}/commontools/${aversion}/haddit_EleMuOSOF_histograms.sh"    
 chmod +x "${basedir}/commontools/${aversion}/haddit_EleMuOSOFL_histograms.sh"    


 bash "${basedir}/commontools/${aversion}/haddit_OPTtree.sh"
 bash "${basedir}/commontools/${aversion}/haddit_TwoEleDY_histograms.sh"    
 bash "${basedir}/commontools/${aversion}/haddit_TwoMuDY_histograms.sh"    
 bash "${basedir}/commontools/${aversion}/haddit_TwoEleZH_histograms.sh"    
 bash "${basedir}/commontools/${aversion}/haddit_TwoMuZH_histograms.sh"    
 bash "${basedir}/commontools/${aversion}/haddit_EleMuOSOF_histograms.sh"    
 bash "${basedir}/commontools/${aversion}/haddit_EleMuOSOFL_histograms.sh"    

done
