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
process.GlobalTag.globaltag = 'MC_3XY_V26::All'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.source = cms.Source(
    "PoolSource",
    fileNames = cms.untracked.vstring(
    'rfio:/castor/cern.ch/cms/store/relval/CMSSW_3_1_4/RelValZEE/GEN-SIM-RECO/MC_31X_V3-v1/0005/0498BA50-86B0-DE11-A75E-001D09F29619.root'
      )
)

process.dump = cms.EDAnalyzer("EventContentAnalyzer")

process.load("Configuration.EventContent.EventContent_cff")

process.out = cms.OutputModule("PoolOutputModule",
    process.RECOSIMEventContent,
    fileName = cms.untracked.string('PfReReco.root')
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

process.MessageLogger.cerr.FwkReport.reportEvery = 1000
