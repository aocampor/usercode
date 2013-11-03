import FWCore.ParameterSet.Config as cms

process = cms.Process("rpctest")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)

process.source = cms.Source("PoolSource",
    moduleLogName = cms.untracked.string('source'),
    fileNames = cms.untracked.vstring(
            '/store/data/Summer08/Cosmics/RECO/CRAFT_ALL_V8_v1/0000/047AADFF-0FF4-DD11-B47F-001D0968F0B2.root'
    )
)



process.MessageLogger = cms.Service("MessageLogger",
 destinations = cms.untracked.vstring('log.txt')
)

# rpc geometry
process.load("Geometry.MuonNumbering.muonNumberingInitialization_cfi")
process.load("Geometry.MuonCommonData.muonIdealGeometryXML_cfi")
process.load("Geometry.RPCGeometry.rpcGeometry_cfi")

# emulation
process.load("L1TriggerConfig.RPCTriggerConfig.RPCPatSource_cfi")

# For cosmic patterns (3/6) from src directory execute:
# mkdir -p MyAna/EmuData/data/
# ln -s /afs/cern.ch/cms/data/CMSSW/L1Trigger/RPCTrigger/data/CosmicPats/v6/ MyAna/EmuData/data/CosmicPats6
# and uncomment following two lines. Otherwise LHC patterns will be used
#process.rpcconf.filedir = cms.untracked.string('MyAna/EmuData/data/CosmicPats6/')
#process.rpcconf.PACsPerTower = cms.untracked.int32(1)


process.load("L1TriggerConfig.RPCTriggerConfig.RPCConeSource_cfi")
process.load("L1TriggerConfig.RPCTriggerConfig.RPCHwConfigSource_cfi")
process.load("L1Trigger.RPCTrigger.l1RpcEmulDigis_cfi")

process.l1RpcEmulDigis.label = cms.string('muonRPCDigis')
process.dump=cms.EDAnalyzer('EventContentAnalyzer')
process.p = cms.Path(process.l1RpcEmulDigis*process.dump)

#process.p=cms.Path(process.dump)

