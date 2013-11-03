import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")
process.load("CondCore.DBCommon.CondDBSetup_cfi")

#process.load("EventFilter.RPCRawToDigi.RPCUnpacking_cfi")

process.load("DQM.RPCMonitorDigi.RPCDigiMonitoring_cfi")

process.load("DQMServices.Core.DQM_cfg")

process.load("Geometry.MuonNumbering.muonNumberingInitialization_cfi")

#process.load("MagneticField.Engine.volumeBasedMagneticField_cfi")

process.load("Geometry.MuonCommonData.muonIdealGeometryXML_cfi")
process.load("EventFilter.RPCRawToDigi.RPCSQLiteCabling_cfi")
process.load("Geometry.RPCGeometry.rpcGeometry_cfi")

process.load("RecoLocalMuon.RPCRecHit.rpcRecHits_cfi")

process.load("Configuration.StandardSequences.MagneticField_cff")

#process.source = cms.Source("PoolSource",
#    moduleLogName = cms.untracked.string('source'),
 #   moduleLogName = cms.untracked.string('RPCDigiDQM'),                            
  #  fileNames = cms.untracked.vstring('file:digis.root')
#)

process.source = cms.Source("NewEventStreamFileReader",
         fileNames = cms.untracked.vstring(
    'rfio:/castor/cern.ch/user/c/ccmuon/RPC/minidaq/97003/PrivMuon.00097003.0001.A.storageManager.00.0000.dat'
    ))

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)
process.ModuleWebRegistry = cms.Service("ModuleWebRegistry")

process.LockService = cms.Service("LockService",
    labels = cms.untracked.vstring('source')
)

process.out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('RPCDQM.root')
)

process.rpcunpacker = cms.EDFilter("RPCUnpackingModule",
           InputLabel = cms.untracked.InputTag("source"),
           doSynchro = cms.bool(False)
)

#process.p = cms.Path(process.rpcRecHits*process.rpcdigidqm)
process.p = cms.Path(process.rpcunpacker*process.rpcRecHits*process.rpcdigidqm)
process.rpcdigidqm.DigiEventsInterval = 100
process.rpcdigidqm.DigiDQMSaveRootFile = True
process.rpcdigidqm.dqmshifter = True
process.rpcdigidqm.dqmexpert = True
process.rpcdigidqm.dqmsuperexpert = True
process.rpcdigidqm.RootFileNameDigi = 'RPCDQM_97003.root'
#process.DQM.collectorHost = 'myhost'
process.DQM.collectorHost = ''
process.DQM.collectorPort = 9090
process.DQM.debug = False
#process.rpcRecHits.rpcDigiLabel = 'muonRPCDigis'
process.rpcRecHits.rpcDigiLabel = 'rpcunpacker'

