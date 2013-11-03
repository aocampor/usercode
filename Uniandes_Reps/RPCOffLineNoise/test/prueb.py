import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(3000) )

#process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
#    fileNames = cms.untracked.vstring(
  #      '/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0000/46FF6C90-71C1-DD11-A71F-0019B9E4FFE1.root'
#     'rfio:/castor/cern.ch/user/c/ccmuon/RPC/minidaq/97030/digis.97030.0001.0002.root'
 #     'rfio:/castor/cern.ch/user/c/ccmuon/RPC/minidaq/97296/digis.97296.0001.0000.root'
  #  )
#)

process.source = cms.Source("NewEventStreamFileReader",
         fileNames = cms.untracked.vstring(
   # 'rfio:/castor/cern.ch/user/c/ccmuon/RPC/minidaq/97004/PrivMuon.00097004.0001.A.storageManager.00.0000.dat'
    'rfio:/castor/cern.ch/user/c/ccmuon/RPC/minidaq/97134/PrivMuon.00097134.0001.A.storageManager.00.0000.dat'        
    ))

process.load("Geometry.MuonNumbering.muonNumberingInitialization_cfi")

#Geometry
process.load("CondCore.DBCommon.CondDBSetup_cfi")
process.load("Alignment.CommonAlignmentProducer.GlobalPosition_Fake_cff")
process.load("EventFilter.RPCRawToDigi.RPCSQLiteCabling_cfi")

process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Geometry.MuonCommonData.muonIdealGeometryXML_cfi")
process.load("Geometry.RPCGeometry.rpcGeometry_cfi")
#process.load("Configuration.StandardSequences.volumeBasedMagneticField_cfi")
process.load("RecoLocalMuon.Configuration.RecoLocalMuonCosmics_cff")
process.load("RecoMuon.Configuration.RecoMuonCosmics_cff")
process.load("RecoMuon.MuonSeedGenerator.CosmicMuonSeedProducer_cfi")
process.load("RecoMuon.CosmicMuonProducer.cosmicMuons_cfi")

#Geometry
process.load("Geometry.DTGeometry.dtGeometry_cfi")
process.load("Alignment.CommonAlignmentProducer.GlobalPosition_Fake_cff")

#emulation
process.load("L1TriggerConfig.RPCTriggerConfig.RPCPatSource_cfi")

process.load("L1TriggerConfig.RPCTriggerConfig.RPCConeSource_cfi")
process.load("L1TriggerConfig.RPCTriggerConfig.RPCHwConfigSource_cfi")
process.load("L1Trigger.RPCTrigger.l1RpcEmulDigis_cfi")
process.rpcconf.filedir = cms.untracked.string('MyAna/EmuData/data/CosmicPats6/')
process.rpcconf.PACsPerTower = cms.untracked.int32(1)
process.l1RpcEmulDigis.label = cms.string('rpcunpacker')

process.demo = cms.EDAnalyzer('RPCOffLineNoise',
                              root_file_name = cms.untracked.string("RPCOffLineNoise.root"),
                              GMTInputTag = cms.InputTag("rpcunpacker"),
                              labelDT = cms.untracked.string("muonDTDigis"),
#                              bins = cms.untracked.int32(10000),
                              noise = cms.untracked.bool(True),   ##### Want to run over the noise limit or over all the digis?
                              limit = cms.untracked.int32(100),   ########## Limit of Noise events
                              hours = cms.untracked.int32(5)      ### How many hours does the run takes
)
process.rpcunpacker = cms.EDFilter("RPCUnpackingModule",
           InputLabel = cms.untracked.InputTag("source"),
           doSynchro = cms.bool(False)
)

#process.RPCCabling = cms.ESSource("PoolDBESSource",
 #                                 DBParameters = cms.PSet(
  #  messageLevel = cms.untracked.int32(0),
   # authenticationPath = cms.untracked.string('/nfshome0/hltpro/cmssw/cfg/')
   # ),
    #                              timetype = cms.string('runnumber'),
     #                             toGet = cms.VPSet(cms.PSet(
#    record = cms.string('RPCEMapRcd'),
 #   tag = cms.string('RPCEMap_v2')
  #  )),
   #                               connect = cms.string('frontier://(proxyurl=http://localhost:3128)(serverurl=http://frontier1.cms:8000/FrontierOnProd)(serverurl=http://frontier2.cms:8000/FrontierOnProd)(retrieve-ziplevel=0)/CMS_COND_20X_RPC'),
    #                              siteLocalConfig = cms.untracked.bool(False)
     #                             )

process.rpcRecHits.rpcDigiLabel = 'rpcunpacker'


process.p = cms.Path(process.rpcunpacker*process.l1RpcEmulDigis*process.demo)
#process.p = cms.Path(process.demo)
