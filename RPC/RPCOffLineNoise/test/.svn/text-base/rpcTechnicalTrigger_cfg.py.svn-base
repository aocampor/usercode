import FWCore.ParameterSet.Config as cms

process   = cms.Process("RPCTechnicalTrigger")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.categories = ['*']
process.MessageLogger.destinations = ['cout']
process.MessageLogger.cout = cms.untracked.PSet(
    	threshold = cms.untracked.string('INFO'),
	INFO = cms.untracked.PSet(
        limit = cms.untracked.int32(-1) ) )

#.. Geometry
process.load("Configuration.StandardSequences.Geometry_cff")

#.. Real data raw to digi
process.load("Configuration.StandardSequences.RawToDigi_Data_cff")


#.. access database hardware configuration objects

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(3000) )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring( 'rfio:/castor/cern.ch/user/c/ccmuon/RPC/minidaq/97234/digis.97234.0001.0000.root' ) )
#process.source = cms.Source("NewEventStreamFileReader",
 #        fileNames = cms.untracked.vstring(
   # 'rfio:/castor/cern.ch/user/c/ccmuon/RPC/minidaq/97004/PrivMuon.00097004.0001.A.storageManager.00.0000.dat'
  #  'rfio:/castor/cern.ch/user/c/ccmuon/RPC/minidaq/97134/PrivMuon.00097134.0001.A.storageManager.00.0000.dat'        
   # ))

process.load("Geometry.MuonNumbering.muonNumberingInitialization_cfi")

process.load("Alignment.CommonAlignmentProducer.GlobalPosition_Fake_cff")
process.load("EventFilter.RPCRawToDigi.RPCSQLiteCabling_cfi")

process.load("Geometry.MuonCommonData.muonIdealGeometryXML_cfi")
process.load("Geometry.RPCGeometry.rpcGeometry_cfi")

process.rpcunpacker = cms.EDFilter("RPCUnpackingModule",
           InputLabel = cms.untracked.InputTag("source"),
           doSynchro = cms.bool(False)
)

process.rpcTechnicalTrigger  = cms.EDProducer('RPCTechnicalTrigger',
                                              Verbosity = cms.untracked.int32(1),
                                              TriggerMode = cms.int32(1),
                                              RPCDigiLabel = cms.InputTag("rpcunpacker"),
                                              UseDatabase = cms.untracked.int32(0),
                                              BitNumbers=cms.vuint32(24,25,26,27,28),
                                              BitNames=cms.vstring('L1Tech_rpcBit1',
                                                                   'L1Tech_rpcBit2',
                                                                   'L1Tech_rpcBit3',
                                                                   'L1Tech_rpcBit4',
                                                                   'L1Tech_rpcBit5') )


process.TFileService = cms.Service("TFileService", fileName = cms.string('rpctt_results.root') )
process.demo = cms.EDAnalyzer( 'L1GtTechTrig' )


process.p = cms.Path(process.rpcunpacker*process.rpcTechnicalTrigger*process.demo)


