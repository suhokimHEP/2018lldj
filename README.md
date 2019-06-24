##2018lldj
 For 2018 data
## Overview, History, and Introduction
```
 #This 2018lldj repo is DisplacedHiggs/LLDJstandalones customed to 2018 version.
 #2017lldj had a major overhaul in eliminating PFJets,PFchJets,slimmedJets, all photonID variables. 
 #2018lldj does not have as much major overhaul, but just an adapted version for Run2 2018.
```
## Set up the area
```
# Fermilab uses tcsh by default even though it has bash!
# This framework is based in bash and
# technically maybe you don't need this,
# but tcshers be warned

  bash --login

# Set up the area
export SCRAM_ARCH=slc6_amd64_gcc700;
scram pro -n 2018-LLDJ_slc6_700_CMSSW_10_2_15 CMSSW CMSSW_10_2_15;
cd 2018-LLDJ_slc6_700_CMSSW_10_2_15/src;
cmsenv;
```

## CMSSW imports and customizations
```
git cms-init;
git cms-merge-topic cms-egamma:EgammaID_1023; #if you want the V2 IDs, otherwise skip  
git cms-merge-topic cms-egamma:EgammaPostRecoTools; #just adds in an extra file to have a setup function to make things  easier
scramv1 build -j 4;
```

## LLDJstandalones Framework checkout
```
 first fork the repository to make your own workspace

git clone https://github.com/<mygithubusername>/2018lldj.git;
pushd 2018lldj;
```

## If you want to check out a specific branch
```
  git fetch origin
  git branch -v -a # list branches available, find yours
  git checkout -b NAMEOFBRANCH origin/NAMEOFBRANCH
```  
## add DisplacedHiggs as upstream
```
  git remote add upstream https://github.com/DisplacedHiggs/2018lldj.git
```
##-----Compile a clean area
```
  cd 2018lldj
  scramv1 build -j 4;
```
##-----Every time you log in
```
  #set up some environment variables (bash)
  source 2018lldj/setup.sh
  #Set nversion to 2018_LLDJ for official version of ntuples

```
