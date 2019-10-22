import FWCore.ParameterSet.Config as cms

##########################################################################################
# Setup

# this is the process run by cmsRun
process = cms.Process('LLDJ')
process.options = cms.untracked.PSet( allowUnscheduled = cms.untracked.bool(True) )

#Setup FWK for multithreaded
process.options.numberOfThreads=cms.untracked.uint32(4)
process.options.numberOfStreams=cms.untracked.uint32(0)
#process.options.SkipEvent = cms.untracked.vstring('ProductNotFound')
process.load("RecoTracker.TkNavigation.NavigationSchoolESProducer_cfi")

# log output
process.load('FWCore.MessageLogger.MessageLogger_cfi')
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )  ## number of events -1 does all
process.MessageLogger.cerr.FwkReport.reportEvery = 100

# input files
process.source = cms.Source('PoolSource',
                            fileNames = cms.untracked.vstring(

#'root://cmsxrootd.fnal.gov//store/mc/RunIIAutumn18DRPremix/QCD_HT50to100_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/100000/4E581528-5A9D-5042-8B33-99BB0FF2F0DD.root'
'root://cmsxrootd.fnal.gov//store/mc/RunIIAutumn18DRPremix/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/90000/0EBE99B3-B9C8-1E4F-BF05-996F426C109B.root'
#'file://DD967656-BACC-DD40-BA44-7E309FF8D393.root'
 ),
)

# output name
process.TFileService = cms.Service('TFileService', fileName = cms.string('lldjntuple_mc_AOD.root'));


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
#process.GlobalTag.globaltag = '94X_mc2017_realistic_v12'
process.GlobalTag.globaltag = '102X_upgrade2018_realistic_v18'

## for AOD Photons
#from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
#dataFormat = DataFormat.AOD
#switchOnVIDPhotonIdProducer(process, dataFormat)
#my_id_modules = ['RecoEgamma.PhotonIdentification.Identification.cutBasedPhotonID_Spring16_V2p2_cff']
#for idmod in my_id_modules:
#    setupAllVIDIdsInModule(process,idmod,setupVIDPhotonSelection) 

## for AOD Electrons
#switchOnVIDElectronIdProducer(process, dataFormat)
#my_id_modules = ['RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_Summer16_80X_V1_cff']
#for idmod in my_id_modules:
#    setupAllVIDIdsInModule(process,idmod,setupVIDElectronSelection)

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

# pat for muons
process.load('PhysicsTools.PatAlgos.patSequences_cff')

from RecoEgamma.EgammaTools.EgammaPostRecoTools import setupEgammaPostRecoSeq
setupEgammaPostRecoSeq(process,
                       runVID=True,
                       era='2017-Nov17ReReco', 
		       isMiniAOD=False,
		       eleIDModules=['RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_Fall17_94X_V2_cff'],
		       phoIDModules=['RecoEgamma.PhotonIdentification.Identification.cutBasedPhotonID_Fall17_94X_V2_cff']
#		       phoIDModules=[]
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

 electronSrc               = cms.InputTag('selectedElectrons','','LLDJ'),
 rhoLabel                  = cms.InputTag('fixedGridRhoFastjetAll'),
 #eleVetoIdMap              = cms.InputTag('egmGsfElectronIDs:cutBasedElectronID-Summer17-94X-V2-veto'),
 #eleLooseIdMap             = cms.InputTag('egmGsfElectronIDs:cutBasedElectronID-Summer17-94X-V2-loose'),
 #eleMediumIdMap            = cms.InputTag('egmGsfElectronIDs:cutBasedElectronID-Summer17-94X-V2-medium'),
 #eleTightIdMap             = cms.InputTag('egmGsfElectronIDs:cutBasedElectronID-Summer17-94X-V2-tight'),
 eleHLTIdMap               = cms.InputTag('egmGsfElectronIDs:cutBasedElectronHLTPreselection-Summer17-V2'),

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
 #pfMETLabel                = cms.InputTag('slimmedMETs'),
 AODCaloMETlabel           = cms.InputTag('caloMet','','RECO'),    
 #AODpfChMETlabel           = cms.InputTag('pfChMet','','RECO'),    
 #AODpfMETlabel             = cms.InputTag('pfMet','','RECO'),  

 muonSrc                   = cms.InputTag('slimmedMuons'),
 muonAODSrc                = cms.InputTag('selectedPatMuons'),

 #photonSrc                 = cms.InputTag('selectedPhotons','','LLDJ'),
 #phoLooseIdMap             = cms.InputTag('egmPhotonIDs:cutBasedPhotonID-Spring15-25ns-V1-standalone-loose'),
 #phoMediumIdMap            = cms.InputTag('egmPhotonIDs:cutBasedPhotonID-Spring15-25ns-V1-standalone-medium'),
 #phoTightIdMap             = cms.InputTag('egmPhotonIDs:cutBasedPhotonID-Spring15-25ns-V1-standalone-tight'),
 #phoChargedIsolation       = cms.InputTag('photonIDValueMapProducer:phoChargedIsolation'),
 #phoNeutralHadronIsolation = cms.InputTag('photonIDValueMapProducer:phoNeutralHadronIsolation'),
 #phoPhotonIsolation        = cms.InputTag('photonIDValueMapProducer:phoPhotonIsolation'),
 #phoWorstChargedIsolation  = cms.InputTag('photonIDValueMapProducer:phoWorstChargedIsolation'),

 #photonAODSrc              = cms.InputTag('selectedPatPhotons'),
 photonAODSrc              = cms.InputTag('gedPhotons'),
 #AOD_phoLooseIdMap  = cms.InputTag("egmPhotonIDs:cutBasedPhotonID-Spring16-V2p2-loose"),
 #AOD_phoMediumIdMap = cms.InputTag("egmPhotonIDs:cutBasedPhotonID-Spring16-V2p2-medium"),
 #AOD_phoTightIdMap  = cms.InputTag("egmPhotonIDs:cutBasedPhotonID-Spring16-V2p2-tight"),
 #AOD_phoChargedIsolationMap       = cms.InputTag("photonIDValueMapProducer", "phoChargedIsolation"),
 #AOD_phoNeutralHadronIsolationMap = cms.InputTag("photonIDValueMapProducer", "phoNeutralHadronIsolation"),
 #AOD_phoPhotonIsolationMap        = cms.InputTag("photonIDValueMapProducer", "phoPhotonIsolation"),
 #AOD_phoWorstChargedIsolationMap  = cms.InputTag("photonIDValueMapProducer", "phoWorstChargedIsolation"),

 electronAODSrc = cms.InputTag("gedGsfElectrons"),
 #AOD_eleIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronHLTPreselection-Summer16-V1"),#doesn't work with AOD
 AOD_eleLooseIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Fall17-94X-V2-loose"),
 AOD_eleMediumIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Fall17-94X-V2-loose"),
 AOD_eleTightIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Fall17-94X-V2-loose"),
 conversions  = cms.InputTag('allConversions'),                                    

 #genParticleSrc    = cms.InputTag("genParticles"),

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

    #process.egmPhotonIDSequence *
#process.ep = cms.EndPath(process.out)
#print process.dumpPython()
#print process.egmGsfElectronIDSequence.dumpPython()

