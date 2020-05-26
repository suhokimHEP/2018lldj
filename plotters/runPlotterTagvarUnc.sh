#!/bin/bash

regions=( \ 
# "EleMuOSOF"     \   
# "OnePho"        \
# "TwoEleDY"      \   
 "TwoMuOffZ"       \
 "TwoMuZH"       \
 "TwoMuDY"       \
) 

variables=( \
  "AOD_dileptonNewB_Pt"			       \
  "AOD_dilepton_Mass"	\
  "AOD_dileptonNewB_Pt"	\
  "0Jet_AOD_dileptonNewB_Pt" 	\
  "1Jet_AOD_dileptonNewB_Pt" 	\
  "nJet_AOD_dileptonNewB_Pt" 	\
  "nSelectedAODCaloJet" 	\
  "nSelectedAODCaloJetTag" 	\
  "AllJets_AODCaloJetMedianLog10IPSig" 	\
  "AllJets_AODCaloJetMedianLog10TrackAngle" \
  "AllJets_AODCaloJetAlphaMax" \
  "AllJets_AODCaloJetPt"        \               
  "AllJets_AODCaloJetEta"        \               
  "AllJets_1Jet_AODCaloJetPt"     \                  
  "AllJets_1Jet_AODCaloJetEta"     \                  
  "AllJets_1Jet_AODCaloJetMedianLog10IPSig" \
  "AllJets_1Jet_AODCaloJetMedianLog10TrackAngle" \
  "AllJets_1Jet_AODCaloJetAlphaMax" \
  "AllJets_2Jet_AODCaloJetPt"        \               
  "AllJets_2Jet_AODCaloJetEta"        \               
  "AllJets_2Jet_AODCaloJetMedianLog10IPSig" \
  "AllJets_2Jet_AODCaloJetMedianLog10TrackAngle" \
  "AllJets_2Jet_AODCaloJetAlphaMax" \
  "AllJets_nJet_AODCaloJetPt"        \               
  "AllJets_nJet_AODCaloJetEta"        \               
  "AllJets_nJet_AODCaloJetMedianLog10IPSig" \
  "AllJets_nJet_AODCaloJetMedianLog10TrackAngle" \
  "AllJets_nJet_AODCaloJetAlphaMax" \
  "AOD_muPt"                    \
  "AOD_muEta"                   \
  "AOD_muPhi"                   \
  "0Jet_AOD_dileptonNewB_Pt"			       \
  "1Jet_AOD_dileptonNewB_Pt"			       \
  "nJet_AOD_dileptonNewB_Pt"			       \
 "AllJets_AODCaloJetMedianLog10IPSig"         \
 "AllJets_AODCaloJetMedianLog10TrackAngle"    \
 "AllJets_AODCaloJetAlphaMax"                 \
)

for region in ${regions[@]}
do
 for variable in ${variables[@]}
 do
  #root -l -b -q  'plotter_tagvarUnc.C('\""${region}"\"', '\""${variable}"\"' , kTRUE, kFALSE)'
  #root -l -b -q  'plotter_tagvarUnc.C('\""${region}"\"', '\""${variable}"\"' , kFALSE)'
  root -l -b -q  'plotter_Comparison.C('\""${region}"\"', '\""${variable}"\"' , kFALSE)'
  #root -l -b -q  'plotter_Zcorrection.C('\""${region}"\"', '\""${variable}"\"' , kFALSE)'
  #root -l -b -q  'plotter_binShift.C('\""${region}"\"', '\""${variable}"\"' , kFALSE)'

 done
done

