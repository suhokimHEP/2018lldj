import FWCore.ParameterSet.Config as cms

##########################################################################################
# Setup

# this is the process run by cmsRun
process = cms.Process('LLDJ')
process.options = cms.untracked.PSet( allowUnscheduled = cms.untracked.bool(True) )

#Setup FWK for multithreaded
process.options.numberOfThreads=cms.untracked.uint32(4)
process.options.numberOfStreams=cms.untracked.uint32(0)

process.load("RecoTracker.TkNavigation.NavigationSchoolESProducer_cfi")

# log output
process.load('FWCore.MessageLogger.MessageLogger_cfi')
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )  ## number of events -1 does all
process.MessageLogger.cerr.FwkReport.reportEvery = 100
#process.MessageLogger.cerr.FwkReport.reportEvery = 1
#process.Tracer = cms.Service('Tracer')

# input files
process.source = cms.Source('PoolSource',
                            fileNames = cms.untracked.vstring(
#'file:MuEG.root'
#'root://cms-xrd-global.cern.ch//store/data/Run2016G/SingleElectron/AOD/23Sep2016-v1/100000/62B0D6B4-D58A-E611-9F51-002590AC4B5C.root'
#'root://cms-xrd-global.cern.ch//store/data/Run2018A/MuonEG/AOD/17Sep2018-v1/90000/4B3CE728-3432-BF47-9B44-8D65A8D5762A.root'	
'root://cms-xrd-global.cern.ch//store/data/Run2018C/DoubleMuon/AOD/17Sep2018-v1/60001/FA54390B-F3F9-7846-B02A-7F0CF2D8E684.root'	
#'file:/uscms/home/ddiaz/nobackup/DataSP.root'
 ),
)

# output name
process.TFileService = cms.Service('TFileService', fileName = cms.string('lldjntuple_data_AOD.root'));

# cms geometry
#process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
#process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')

# In EGamma POG PostRecoTools twiki, instead of two above
process.load("Configuration.Geometry.GeometryRecoDB_cff")
process.load("Configuration.StandardSequences.Services_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Geometry.CaloEventSetup.CaloTowerConstituents_cfi")

# global tag
process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = '102X_dataRun2_Sep2018ABC_v2'

##from old config for 2016
###########################################################################################
process.load( 'PhysicsTools.PatAlgos.producersLayer1.patCandidates_cff' )
process.load( 'PhysicsTools.PatAlgos.triggerLayer1.triggerProducer_cff' )
process.load('PhysicsTools.PatAlgos.patSequences_cff')
##########################################################################################


# for AOD Photons
#from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
#dataFormat = DataFormat.AOD
#switchOnVIDPhotonIdProducer(process, dataFormat)
#my_id_modules = ['RecoEgamma.PhotonIdentification.Identification.cutBasedPhotonID_Fall17_94X_V1_TrueVtx_cff']
#for idmod in my_id_modules:
#    setupAllVIDIdsInModule(process,idmod,setupVIDPhotonSelection) 

# for JEC
# Load the corrections
process.load('JetMETCorrections.Configuration.JetCorrectors_cff')

# Produce corrected jets collection
process.ak4CaloCorrectedJets   = cms.EDProducer('CorrectedCaloJetProducer',
    src         = cms.InputTag('ak4CaloJets'),
    #L1(PU), L2L3(MCTruth), L2L3Residuals
    correctors  = cms.VInputTag('ak4CaloL1FastL2L3ResidualCorrector')
    #correctors  = cms.VInputTag('ak4CaloL1FastjetCorrector', 'ak4CaloL2L3Corrector', 'ak4CaloL2L3ResidualCorrector')
    #correctors  = cms.VInputTag('ak4CaloL2L3Corrector')
    )

# pat for trigger
process.load( 'PhysicsTools.PatAlgos.triggerLayer1.triggerProducer_cff' )

# load the coreTools of PAT
from PhysicsTools.PatAlgos.tools.jetTools import *

# pat for muons
#process.load('PhysicsTools.PatAlgos.patSequences_cff')

from PhysicsTools.PatAlgos.tools.coreTools import *
runOnData( process, names=['All'], outputModules = [])

#### import skeleton process
###from PhysicsTools.PatAlgos.patTemplate_cfg import *
#process.load("PhysicsTools.PatAlgos.producersLayer1.patCandidates_cff")
#patAlgosToolsTask.add(process.patCandidatesTask)

#process.load("PhysicsTools.PatAlgos.selectionLayer1.selectedPatCandidates_cff")
#patAlgosToolsTask.add(process.selectedPatCandidatesTask)



###########----Test Area
# 2017 AOD Electron ID: https://twiki.cern.ch/twiki/bin/view/CMS/EgammaPostRecoRecipes#Running_on_2016_2017_AOD
# 2017 ID recommendations: https://twiki.cern.ch/twiki/bin/view/CMS/EgammaRunIIRecommendations#Fall17v1 
## for AOD Electrons
from RecoEgamma.EgammaTools.EgammaPostRecoTools import setupEgammaPostRecoSeq
setupEgammaPostRecoSeq(process,
                       runVID=True,
                       era='2017-Nov17ReReco', 
		       isMiniAOD=False,
		       eleIDModules=['RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_Fall17_94X_V2_cff'],
		       phoIDModules=['RecoEgamma.PhotonIdentification.Identification.cutBasedPhotonID_Fall17_94X_V2_cff']	
)



# For AOD Track variables
process.MaterialPropagator = cms.ESProducer('PropagatorWithMaterialESProducer',
    ComponentName = cms.string('PropagatorWithMaterial'),
    Mass = cms.double(0.105),
    MaxDPhi = cms.double(1.6),
    PropagationDirection = cms.string('alongMomentum'),
    SimpleMagneticField = cms.string(''),
    ptMin = cms.double(-1.0),
    useRungeKutta = cms.bool(False)
)

process.TransientTrackBuilderESProducer = cms.ESProducer('TransientTrackBuilderESProducer',
    ComponentName = cms.string('TransientTrackBuilder')
)


#NTuplizer
process.lldjNtuple = cms.EDAnalyzer('lldjNtuple',

 doAOD                     = cms.bool(True),
 doMiniAOD                 = cms.bool(False),

 rhoLabel                  = cms.InputTag('fixedGridRhoFastjetAll'),

 rhoCentralLabel           = cms.InputTag('fixedGridRhoFastjetCentralNeutral'),
 pileupCollection          = cms.InputTag('slimmedAddPileupInfo'),
 AODpileupCollection       = cms.InputTag('addPileupInfo', '', 'HLT'),
 VtxLabel                  = cms.InputTag('offlineSlimmedPrimaryVertices'),
 triggerResults            = cms.InputTag('TriggerResults', '', 'HLT'),

 AODTriggerInputTag           = cms.InputTag("TriggerResults","","HLT"),
 AODTriggerEventInputTag      = cms.InputTag("hltTriggerSummaryAOD","","HLT"),

 beamspotLabel_            = cms.InputTag('offlineBeamSpot'),

 #ak4JetSrc                 = cms.InputTag('slimmedJets'),
 AODak4CaloJetsSrc         = cms.InputTag('ak4CaloJets' , '', 'RECO'),
 #AODak4CorrCaloJetsSrc     = cms.InputTag('ak4CaloCorrectedJets'),
 #AODak4PFJetsSrc           = cms.InputTag('ak4PFJets'   , '', 'RECO'),
 #AODak4PFJetsCHSSrc        = cms.InputTag('ak4PFJetsCHS', '', 'RECO'),
 #selectedPatJetsSrc        = cms.InputTag('selectedPatJets'),                                   
 AODVertexSrc              = cms.InputTag('offlinePrimaryVertices', '', 'RECO'),
 AODTrackSrc               = cms.InputTag('generalTracks', '', 'RECO'),
 vertexFitterConfig = cms.PSet(
        finder = cms.string('avf'),
        sigmacut = cms.double(10.),
        Tini = cms.double(256.),
        ratio = cms.double(0.25),
        ),

 patTriggerResults         = cms.InputTag('TriggerResults', '', 'PAT'),
 BadChargedCandidateFilter = cms.InputTag('BadChargedCandidateFilter'),
 BadPFMuonFilter           = cms.InputTag('BadPFMuonFilter'),
 #pfMETLabel                = cms.InputTag('slimmedMETsMuEGClean', '', 'LLDJ'),
 AODCaloMETlabel           = cms.InputTag('caloMet','','RECO'),    
 #AODpfChMETlabel           = cms.InputTag('pfChMet','','RECO'),    
 #AODpfMETlabel             = cms.InputTag('pfMet','','RECO'),  

 muonSrc                   = cms.InputTag('slimmedMuons'),
 muonAODSrc                = cms.InputTag('selectedPatMuons'),
 #muonAODSrc                = cms.InputTag('muons' , '', 'RECO'),

 #photonSrc                 = cms.InputTag('selectedPhotons','','LLDJ'),
 photonAODSrc              = cms.InputTag('gedPhotons'),

# AOD_phoLooseIdMap  = cms.InputTag("egmPhotonIDs:cutBasedPhotonID-Fall17-94X-V1-loose"),
# AOD_phoMediumIdMap = cms.InputTag("egmPhotonIDs:cutBasedPhotonID-Fall17-94X-V1-medium"),
# AOD_phoTightIdMap  = cms.InputTag("egmPhotonIDs:cutBasedPhotonID-Fall17-94X-V1-tight"),
# AOD_phoChargedIsolationMap       = cms.InputTag("photonIDValueMapProducer", "phoChargedIsolation"),
# AOD_phoNeutralHadronIsolationMap = cms.InputTag("photonIDValueMapProducer", "phoNeutralHadronIsolation"),
# AOD_phoPhotonIsolationMap        = cms.InputTag("photonIDValueMapProducer", "phoPhotonIsolation"),
# AOD_phoWorstChargedIsolationMap  = cms.InputTag("photonIDValueMapProducer", "phoWorstChargedIsolation"),

 electronAODSrc = cms.InputTag("gedGsfElectrons"),
 #AOD_eleIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronHLTPreselection-Summer16-V1"),#doesn't work with AOD
 AOD_eleLooseIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Fall17-94X-V2-loose"),
 AOD_eleMediumIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Fall17-94X-V2-loose"),
 AOD_eleTightIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Fall17-94X-V2-loose"),
 conversions  = cms.InputTag('allConversions'),

# genParticleSrc    = cms.InputTag("genParticles"),

 bits = cms.InputTag("TriggerResults","","HLT"),
 prescales = cms.InputTag("patTrigger"),
 objects = cms.InputTag("selectedPatTrigger"),

)

# Double check: this is to remove the OOT photons, which is causing a crash
process.patCandidates.remove(process.patCandidateSummary)
process.patCandidatesTask.remove(process.makePatOOTPhotonsTask)
process.selectedPatCandidates.remove(process.selectedPatCandidateSummary)
process.selectedPatCandidatesTask.remove(process.selectedPatOOTPhotons)
#process.cleanPatCandidates.remove(process.cleanPatCandidateSummary)


#builds Ntuple
process.p = cms.Path(
    process.egammaPostRecoSeq *
    process.ak4CaloCorrectedJets *
    process.ak4CaloL1FastL2L3ResidualCorrectorChain *
    process.particleFlowPtrs *
    process.patCandidates *
    process.selectedPatCandidates *
    process.lldjNtuple
    )
