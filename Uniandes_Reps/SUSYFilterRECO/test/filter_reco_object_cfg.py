import FWCore.ParameterSet.Config as cms

process = cms.Process("FILTER")
#process.load("Configuration.StandardSequences.Reconstruction_cff")
#process.load("Configuration.StandardSequences.MagneticField_cff")
#process.load("Configuration.StandardSequences.Geometry_cff")
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')

from Configuration.PyReleaseValidation.autoCond import autoCond
#process.GlobalTag.globaltag = autoCond['mc']
# The above tool not always provides the newest tag.
# Fixed tag also better for consistency of next rereco (if any) 
process.GlobalTag.globaltag = 'MC_36Y_V6::All'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.source = cms.Source(
    "PoolSource",
    fileNames = cms.untracked.vstring(
'/store/mc/Summer10/JPsiToEE_EPtEtaFilter_7TeV-pythia6/GEN-SIM-RECODEBUG/START36_V10_TP-v1/0010/30D05392-A67D-DF11-B2A3-0030487CAF4B.root'
    )
)

process.dump = cms.EDAnalyzer("EventContentAnalyzer")

process.load("Configuration.EventContent.EventContent_cff")
process.load("SUSY.SUSYEVFILT.SUSYEVFILT_cfi")
process.out = cms.OutputModule("PoolOutputModule",
                               #    process.RECOSIMEventContent,
                               SelectEvents = cms.untracked.PSet( SelectEvents = cms.vstring('p') ),
                               outputCommands = cms.untracked.vstring(
    'keep *_*_*_RECO',
    'keep *_*_*_HLT',
    'keep *_*_*_HLT8E29',
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
                               fileName = cms.untracked.string('OUTPUT.root')
                               )
process.p = cms.Path(
    process.leptonfilter
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
