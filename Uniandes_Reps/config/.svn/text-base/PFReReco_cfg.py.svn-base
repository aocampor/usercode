import FWCore.ParameterSet.Config as cms

process = cms.Process("RERECO")

process.load("Configuration.StandardSequences.Reconstruction_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.Geometry_cff")
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')

from Configuration.PyReleaseValidation.autoCond import autoCond
#process.GlobalTag.globaltag = autoCond['mc']
# The above tool not always provides the newest tag.
# Fixed tag also better for consistency of next rereco (if any) 
process.GlobalTag.globaltag = 'MC_36Y_V6::All'


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

process.source = cms.Source(
    "PoolSource",
    fileNames = cms.untracked.vstring(
'/store/mc/Summer09/ppMuMuX/GEN-SIM-RECO/MC_31X_V3_7TeV_SD_DoubleMu-v1/0004/DE795496-47B3-DE11-9611-001D0967DF26.root'
    )
)

process.dump = cms.EDAnalyzer("EventContentAnalyzer")

process.load("Configuration.EventContent.EventContent_cff")

process.out = cms.OutputModule("PoolOutputModule",
#    process.RECOSIMEventContent,
                                                              outputCommands = cms.untracked.vstring(
        'drop *_*_*_RECO',
            'keep *_*_*_HLT',
            'keep *_logErrorHarvester_*_*',
            'keep *_selectDigi_*_*',
            'keep *_hcalnoise_*_*',
            'keep *_gtDigis_*_*',
            'keep *_jetBProbabilityBJetTags_*_*',
            'keep *_simpleSecondaryVertexBJetTags_*_*',
            'keep *_siStripDigis_*_*',
            'keep *_cosmicMuons_*_*',
            'keep *_cosmicMuons1Leg_*_*',
            'keep *_globalCosmicMuons_*_*',
            'keep *_globalCosmicMuons1Leg_*_*',
            'keep *_csc2DRecHits_*_*',
            'keep *_cscSegments_*_*',
            'keep *_dt4DSegments_*_*',
            'keep *_dt1DRecHits_*_*',
            'keep *_rpcRecHits_*_*',
            'keep *_castorreco_*_*',
            'keep *_ecalDigis_*_*',
            'keep *_reducedEcalRecHitsEB_*_*',
            'keep *_reducedEcalRecHitsEE_*_*',
            'keep *_ecalRecHit_*_*',
            'keep *_ecalPreshowerRecHit_*_*',
            'keep *_hbhereco_*_*',
            'keep *_hfreco_*_*',
            'keep *_horeco_*_*',
            'keep *_hcalDigis_*_*',
            'keep *_zdcreco_*_*',
            'keep *_siPixelClusters_*_*',
            'keep *_scalersRawToDigi_*_*',
            'keep *_gctDigis_*_*',
            'keep *_CosmicMuonSeed_*_*',
            'keep *_SETMuonSeed_*_*',
            'keep *_ancientMuonSeed_*_*',
            'keep *_logErrorHarvester_*_*',
            'keep *_l1extraParticles_*_*',
            'keep *_CastorClusterRecoAntiKt07_*_*',
            'keep *_CastorJetEgammaRecoAntiKt07_*_*',
            'keep *_CastorTowerReco_*_*',
            'keep *_softPFElectrons_*_*',
            'keep *_hcalnoise_*_*',
            'keep *_htMetSC5_*_*',
            'keep *_htMetSC7_*_*',
            'keep *_muonsFromCosmics_*_*',
            'keep *_muonsFromCosmics1Leg_*_*',
            'keep *_cosmicMuons_*_*',
            'keep *_cosmicMuons1Leg_*_*',
            'keep *_globalCosmicMuons_*_*',
            'keep *_globalCosmicMuons1Leg_*_*',
            'keep *_*_*_RERECO'),       
    fileName = cms.untracked.string('bb7TeV_rereco.root')
)

# Local re-reco: Produce tracker rechits, pf rechits and pf clusters
process.localReReco = cms.Sequence(process.siPixelRecHits+
                                   process.siStripMatchedRecHits+
                                   process.particleFlowCluster)

# Track re-reco
process.globalReReco =  cms.Sequence(process.offlineBeamSpot+
                                     process.recopixelvertexing+
                                     process.ckftracks+
                                     process.ecalClusters+ #MB
                                     process.caloTowersRec+
                                     process.vertexreco+
                                     process.recoJets+
                                     process.recoJetIds+process.recoTrackJets+ #MB
                                     process.muonrecoComplete+
                                     process.electronGsfTracking+
                                     process.metreco)
# High Level ReReco w/o PFlow (MB)
process.highLevelReReco_NoPF = cms.Sequence(process.recoJetAssociations*
                                            process.tautagging*
                                            process.btagging)

# Particle Flow re-processing
process.pfReReco = cms.Sequence(process.particleFlowReco+
                                process.recoPFJets+
                                process.recoPFMET+
                                process.PFTau)

                                
# Gen Info re-processing
process.load("PhysicsTools.HepMCCandAlgos.genParticles_cfi")
process.load("RecoJets.Configuration.GenJetParticles_cff")
process.load("RecoJets.Configuration.RecoGenJets_cff")
process.load("RecoMET.Configuration.GenMETParticles_cff")
process.load("RecoMET.Configuration.RecoGenMET_cff")
process.load("RecoParticleFlow.PFProducer.particleFlowSimParticle_cff")
process.load("RecoParticleFlow.Configuration.HepMCCopy_cfi")
process.genReReco = cms.Sequence(process.generator+
                                 process.genParticles+
                                 process.genJetParticles+
                                 process.recoGenJets+
                                 process.genMETParticles+
                                 process.recoGenMET+
                                 process.particleFlowSimParticle)

# E/gamma re-processing
process.load("RecoEgamma.Configuration.RecoEgamma_cff")

# The complete reprocessing
process.reRecoFull = cms.Sequence(
    process.localReReco
    + process.globalReReco
    + process.highLevelReReco_NoPF #MB
    + process.pfReReco
    + process.egammarecoFull
    #+ process.genReReco
    + process.genJetParticles*process.recoGenJets #MB (change name convention for jets)
    )

# Run it
process.p = cms.Path(
    process.reRecoFull
    )

# Add the output
process.outpath = cms.EndPath(process.out)

# The logger
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.options = cms.untracked.PSet(
    makeTriggerResults = cms.untracked.bool(False),
    wantSummary = cms.untracked.bool(True),
    Rethrow = cms.untracked.vstring('Unknown', 
        'ProductNotFound', 
        'DictionaryNotFound', 
        'InsertFailure', 
        'Configuration', 
        'LogicError', 
        'UnimplementedFeature', 
        'InvalidReference', 
        'NullPointerError', 
        'NoProductSpecified', 
        'EventTimeout', 
        'EventCorruption', 
        'ModuleFailure', 
        'ScheduleExecutionFailure', 
        'EventProcessorFailure', 
        'FileInPathError', 
        'FatalRootError', 
        'NotFound')
)

process.MessageLogger.cerr.FwkReport.reportEvery = 1
