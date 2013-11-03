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
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(2000) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
#        '/store/relval/CMSSW_3_1_0_pre10/RelValCosmics/RECO/CRAFT_31X-test_v4/0000/BE2303B3-955B-DE11-9F37-000423D9A2AE.root'
    '/store/express/Commissioning09/StreamExpress/ALCARECO/v5/000/108/265/6E84D731-D477-DE11-9AD6-000423D98920.root'    
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

#process.l1RpcEmulDigis.label = cms.string('muonRPCDigis')

process.DQMStore = cms.Service("DQMStore")
process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string('RPCNoiseOffline_new.root')
                                   )

process.demo = cms.EDAnalyzer('RPCOffLineNoise',
                              MuonServiceProxy,
                              Debug = cms.untracked.bool(False),
                              Verbose = cms.untracked.bool(False),
                              RPCRecHits = cms.InputTag("rpcRecHits"),
                              DT4DSegments = cms.InputTag("dt4DSegments"),
                              CSCSegments = cms.InputTag("csc4DSegments"),
                              RPCDigis = cms.InputTag("muonRPCDigis"),
                              Tracks = cms.InputTag("cosmicMuons"),
                              Propagator = cms.string("StraightLinePropagator"),
                              segmentsDt = cms.untracked.InputTag("dt4DSegments"),
                              minimumNumberOfHits = cms.untracked.int32(11),
                              minimumNumberOfRPCHits =cms.untracked.int32(0),
                              root_file_name = cms.untracked.string("RPCOffLineNoise.root"),
                              GMTInputTag = cms.InputTag("muonRPCDigis"),
                              labelDT = cms.untracked.string("muonDTDigis"),
#                              bins = cms.untracked.int32(10000),
                              noise = cms.untracked.bool(True),   ##### Want to run over the noise limit or over all the digis?
                              limit = cms.untracked.int32(100),   ########## Limit of Noise events
                              bins = cms.untracked.int32(20000),  ### How many bins in the run, one bin is 10000 events
                              SegmentsTrackAssociatorParameters = cms.PSet(
                                  segmentsDT = cms.InputTag("dt4DSegments"),
                                  SelectedSegments = cms.untracked.InputTag("SelectedSegments"),
                                  segmentsCSC = cms.InputTag("cscSegments")
                              )

)

process.p1 = cms.Path(process.offlineBeamSpot*process.CosmicMuonSeed*process.cosmicMuons*process.rpcRecHits*process.demo)
#process.p = cms.Path(process.*process.demo)
#process.p = cms.Path(process.l1RpcEmulDigis*process.demo)

