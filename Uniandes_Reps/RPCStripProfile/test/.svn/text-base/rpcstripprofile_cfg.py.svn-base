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
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
#        'file:myfile.root'
#              'rfio:/castor/cern.ch/user/c/ccmuon/RPC/minidaq/97715/digis.97715.0001.0000.root'
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
                                   fileName = cms.string('strips.root')
                                   )


process.load("Geometry.MuonNumbering.muonNumberingInitialization_cfi")

process.demo = cms.EDAnalyzer('RPCStripProfile',
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
                              GMTInputTag = cms.InputTag("muonRPCDigis"),
                              labelDT = cms.untracked.string("muonDTDigis"),                              
                              bins = cms.untracked.int32(15000),      ### How many hours does the run takes
                              region = cms.untracked.int32(0),      ### How many hours does the run takes
                              subregion = cms.untracked.int32(2),      ### How many hours does the run takes
                              SegmentsTrackAssociatorParameters = cms.PSet(
                                  segmentsDT = cms.InputTag("dt4DSegments"),
                                  SelectedSegments = cms.untracked.InputTag("SelectedSegments"),
                                  segmentsCSC = cms.InputTag("cscSegments")
                                  )
)

#process.copyAll = cms.OutputModule("PoolOutputModule", fileName = cms.untracked.string("prueba.root") )
#process.printEventNumber = cms.EDAnalyzer("AsciiOutputModule")
process.p = cms.Path(process.offlineBeamSpot*process.CosmicMuonSeed*process.cosmicMuons*process.rpcRecHits*process.demo)
#process.p = cms.Path(process.demo)
#process.out = cms.EndPath(process.copyAll + process.printEventNumber)
