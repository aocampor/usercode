import FWCore.ParameterSet.Config as cms
process = cms.Process("Demo")

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.connect = "frontier://PromptProd/CMS_COND_31X_GLOBALTAG"
process.GlobalTag.globaltag = "GR09_31X_V1P::All"
process.prefer("GlobalTag")

process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.StandardSequences.ReconstructionCosmics_cff")
process.load("Configuration.StandardSequences.MagneticField_38T_cff")
process.load("RecoLocalMuon.RPCRecHit.rpcRecHits_cfi")

##------------ Cosmics ----------------------------------------------------
from RecoMuon.MuonSeedGenerator.CosmicMuonSeedProducer_cfi import *
process.load("RecoVertex.BeamSpotProducer.BeamSpot_cfi")
process.load("RecoLocalMuon.Configuration.RecoLocalMuonCosmics_cff")
process.load("RecoMuon.Configuration.RecoMuonCosmics_cff")
process.load("RecoMuon.MuonSeedGenerator.CosmicMuonSeedProducer_cfi")
process.load("RecoMuon.CosmicMuonProducer.cosmicMuons_cfi")
process.cosmicMuons.TrajectoryBuilderParameters.EnableRPCMeasurement = False
##--------------------------------------------------------------------------
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        '----input_file----'
    )
)

from RecoMuon.TrackingTools.MuonServiceProxy_cff import *
from RecoMuon.TrackingTools.MuonTrackLoader_cff import *

process.load("DQMServices.Components.MEtoEDMConverter_cfi")
process.load("DQMServices.Core.DQM_cfg")

process.load("TrackPropagation.SteppingHelixPropagator.SteppingHelixPropagator_cfi")
process.load("TrackPropagation.SteppingHelixPropagator.SteppingHelixPropagatorOpposite_cfi")

AnalyticalPropagator = cms.ESProducer("AnalyticalPropagatorESProducer",
                                      MaxDPhi = cms.double(0.),
                                      ComponentName = cms.string('AnalyticalPropagator'),
                                      PropagationDirection = cms.string('oppositeToMomentum')
                                      )

process.load("TrackingTools.GeomPropagators.AnyDirectionAnalyticalPropagator_cfi")
process.load("TrackingTools.GeomPropagators.SmartPropagator_cfi")

StraightLinePropagator = cms.ESProducer("StraightLinePropagatorESProducer",
                                        ComponentName = cms.string('StraightLinePropagator'),
                                        PropagationDirection = cms.string('alongMomentum')
                                        )
process.load("TrackingTools.GeomPropagators.StraightLinePropagator_cfi")

#Carillo's code
process.load("DQM.RPCMonitorDigi.RPCEfficiencyMonitoring_cfi")

process.DQMStore = cms.Service("DQMStore")
process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string('----output_file----')
                                   )
process.load("UserCode/RPCDigiCleaning/rpcdigicleaning_cfi")
process.demo = cms.EDAnalyzer('RPCOffLineNoise',
                              MuonServiceProxy,
                              Debug = cms.untracked.bool(False),
                              Verbose = cms.untracked.bool(False),
                              RPCRecHits = cms.InputTag("rpcRecHits"),
                              DT4DSegments = cms.InputTag("dt4DSegments"),
                              CSCSegments = cms.InputTag("cscSegments"),
                              RPCDigis = cms.InputTag("muonRPCDigisClean"),
                              Tracks = cms.InputTag("cosmicMuons"),
                              Propagator = cms.string("StraightLinePropagator"),
                              segmentsDt = cms.untracked.InputTag("dt4DSegments"),
                              minimumNumberOfHits = cms.untracked.int32(11),
                              minimumNumberOfRPCHits =cms.untracked.int32(0),
                              root_file_name = cms.untracked.string("----output_file----"),
                              GMTInputTag = cms.InputTag("muonRPCDigisClean"),
                              labelDT = cms.untracked.string("muonDTDigis"),
                              bins = cms.untracked.int32(20000),
                              noise = cms.untracked.bool(True),   ##### Want to run over the noise limit or over all the digis?
                              limit = cms.untracked.int32(100),   ########## Limit of Noise events
                              hours = cms.untracked.int32(5),  ### How many hours does the run takes
                              SegmentsTrackAssociatorParameters = cms.PSet(
                                  segmentsDT = cms.InputTag("dt4DSegments"),
                                  SelectedSegments = cms.untracked.InputTag("SelectedSegments"),
                                  segmentsCSC = cms.InputTag("cscSegments")
                              )

)
process.rpcRecHits.rpcDigiLabel = "muonRPCDigisClean"
process.muonRPCDigisClean.GMTInputTag = "muonRPCDigis"
process.p1 = cms.Path(process.muonRPCDigisClean*process.offlineBeamSpot*process.CosmicMuonSeed*process.cosmicMuons*process.rpcRecHits*process.demo)




