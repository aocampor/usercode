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
#        'file:myfile.root'
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

#process.l1RpcEmulDigis.label = cms.string('muonRPCDigis')

process.DQMStore = cms.Service("DQMStore")

process.load("Geometry.MuonNumbering.muonNumberingInitialization_cfi")
process.load("UserCode/RPCDigiCleaning/rpcdigicleaning_cfi")
process.demo = cms.EDAnalyzer('RPCStripProfile',
                              MuonServiceProxy,
                              Debug = cms.untracked.bool(False),
                              Verbose = cms.untracked.bool(False),
                              RPCRecHits = cms.InputTag("rpcRecHits"),
                              DT4DSegments = cms.InputTag("dt4DSegments"),
                              CSCSegments = cms.InputTag("csc4DSegments"),
                              RPCDigis = cms.InputTag("muonRPCDigisClean"),
                              Tracks = cms.InputTag("cosmicMuons"),
                              Propagator = cms.string("StraightLinePropagator"),
                              segmentsDt = cms.untracked.InputTag("dt4DSegments"),
                              minimumNumberOfHits = cms.untracked.int32(11),
                              minimumNumberOfRPCHits =cms.untracked.int32(0),                                                            
                              GMTInputTag = cms.InputTag("muonRPCDigisClean"),
                              bins = cms.untracked.int32(15000),      ### How many Bins do the histograms have
                              region = cms.untracked.int32(---region---),      ### Endcaps +-1 and barrel 0
                              subregion = cms.untracked.int32(---wheel---),      ### ring or wheel depending if endcap or barrel
                              SegmentsTrackAssociatorParameters = cms.PSet(
                                  segmentsDT = cms.InputTag("dt4DSegments"),
                                  SelectedSegments = cms.untracked.InputTag("SelectedSegments"),
                                  segmentsCSC = cms.InputTag("cscSegments")
                                  )                              
)
process.muonRPCDigisClean.GMTInputTag = "muonRPCDigis"
process.TFileService = cms.Service("TFileService", fileName = cms.string('----strip----') )
process.p = cms.Path(process.muonRPCDigisClean*process.offlineBeamSpot*process.CosmicMuonSeed*process.cosmicMuons*process.rpcRecHits*process.demo)

