2018lldj

# Set up the area
export SCRAM_ARCH=slc6_amd64_gcc700;
scram pro -n LLDJ_slc6_700_CMSSW_10_2_15 CMSSW CMSSW_10_2_15;
cd LLDJ_slc6_530_CMSSW_10_2_15/src;
cmsenv;


## CMSSW imports and customizations
git cms-init;
git cms-merge-topic cms-egamma:EgammaID_1023; #if you want the V2 IDs, otherwise skip  
git cms-merge-topic cms-egamma:EgammaPostRecoTools; #just adds in an extra file to have a setup function to make things  easier

scramv1 build -j 4;

## LLDJstandalones Framework checkout

# first fork the repository to make your own workspace
git clone https://github.com/<mygithubusername>/2018lldj.git;
pushd 2018lldj;
