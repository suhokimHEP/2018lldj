cp   /uscms_data/d3/skim2/CRAB_2018-LLDJ_slc7_700_CMSSW_10_2_15/src/2018lldj/ntuples/config/gitignore/2018_LLDJ/crabsubmits_2018_LLDJ/crab_Data_DoubleMuon_A/results/processedLumis.json                                               DoubleMuon_A.json    
cp   /uscms_data/d3/skim2/CRAB_2018-LLDJ_slc7_700_CMSSW_10_2_15/src/2018lldj/ntuples/config/gitignore/2018_LLDJ/crabsubmits_2018_LLDJ/crab_Data_DoubleMuon_B_auto/results/processedLumis.json                                          DoubleMuon_B.json    
cp   /uscms_data/d3/skim2/CRAB_2018-LLDJ_slc7_700_CMSSW_10_2_15/src/2018lldj/ntuples/config/gitignore/2018_LLDJ/crabsubmits_2018_LLDJ/crab_Data_DoubleMuon_C/results/processedLumis.json                                               DoubleMuon_C.json    
cp   /uscms_data/d3/skim2/CRAB_2018-LLDJ_slc7_700_CMSSW_10_2_15/src/2018lldj/ntuples/config/gitignore/2018_LLDJ/crabsubmits_2018_LLDJ/crab_Data_DoubleMuon_D/results/processedLumis.json                                               DoubleMuon_D.json    
cp   /uscms_data/d3/skim2/CRAB_2018-LLDJ_slc7_700_CMSSW_10_2_15/src/2018lldj/ntuples/config/gitignore/2018_LLDJ/crabsubmits_2018_LLDJ/crab_Data_EGamma_A/results/processedLumis.json                                               EGamma_A.json    
cp   /uscms_data/d3/skim2/CRAB_2018-LLDJ_slc7_700_CMSSW_10_2_15/src/2018lldj/ntuples/config/gitignore/2018_LLDJ/crabsubmits_2018_LLDJ/crab_Data_EGamma_B/results/processedLumis.json                                               EGamma_B.json    
cp   /uscms_data/d3/skim2/CRAB_2018-LLDJ_slc7_700_CMSSW_10_2_15/src/2018lldj/ntuples/config/gitignore/2018_LLDJ/crabsubmits_2018_LLDJ/crab_Data_EGamma_C_auto/results/processedLumis.json                                          EGamma_C.json    
cp   /uscms_data/d3/skim2/CRAB_2018-LLDJ_slc7_700_CMSSW_10_2_15/src/2018lldj/ntuples/config/gitignore/2018_LLDJ/crabsubmits_2018_LLDJ/crab_Data_EGamma_D_auto2/results/processedLumis.json                                          EGamma_D.json    
cp   /uscms_data/d3/skim2/CRAB_2018-LLDJ_slc7_700_CMSSW_10_2_15/src/2018lldj/ntuples/config/gitignore/2018_LLDJ/crabsubmits_2018_LLDJ/crab_Data_MuonEG_A/results/processedLumis.json                                               MuonEG_A.json    
cp   /uscms_data/d3/skim2/CRAB_2018-LLDJ_slc7_700_CMSSW_10_2_15/src/2018lldj/ntuples/config/gitignore/2018_LLDJ/crabsubmits_2018_LLDJ/crab_Data_MuonEG_B/results/processedLumis.json                                               MuonEG_B.json    
cp   /uscms_data/d3/skim2/CRAB_2018-LLDJ_slc7_700_CMSSW_10_2_15/src/2018lldj/ntuples/config/gitignore/2018_LLDJ/crabsubmits_2018_LLDJ/crab_Data_MuonEG_C/results/processedLumis.json                                               MuonEG_C.json    
cp   /uscms_data/d3/skim2/CRAB_2018-LLDJ_slc7_700_CMSSW_10_2_15/src/2018lldj/ntuples/config/gitignore/2018_LLDJ/crabsubmits_2018_LLDJ/crab_Data_MuonEG_D/results/processedLumis.json                                               MuonEG_D.json    




mergeJSON.py  DoubleMuon_A.json DoubleMuon_B.json DoubleMuon_C.json DoubleMuon_D.json --output=DoubleMuon.json
mergeJSON.py  EGamma_A.json EGamma_B.json EGamma_C.json EGamma_D.json --output=EGamma.json
mergeJSON.py  MuonEG_A.json MuonEG_B.json MuonEG_C.json MuonEG_D.json --output=MuonEG.json
#mergeJSON.py  SinglePhoton_G.json SinglePhoton_H_2.json SinglePhoton_H_3.json  --output=SinglePhoton.json



















