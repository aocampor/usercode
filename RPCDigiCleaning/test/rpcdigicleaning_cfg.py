import FWCore.ParameterSet.Config as cms

process = cms.Process("RPCDIGIClean")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        'rfio:/castor/cern.ch/cms/store/data/Commissioning09/RPCMonitor/RAW/v2/000/102/352/D05CC00C-2768-DE11-8BE5-001D09F29169.root'
    )
)

process.load("Geometry.MuonNumbering.muonNumberingInitialization_cfi")

#Geometry
process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Geometry.MuonCommonData.muonIdealGeometryXML_cfi")
process.load("Geometry.RPCGeometry.rpcGeometry_cfi")
#process.load("MagneticField.Engine.volumeBasedMagneticField_cfi")
process.load("RecoLocalMuon.Configuration.RecoLocalMuonCosmics_cff")
process.load("RecoMuon.Configuration.RecoMuonCosmics_cff")
process.load("RecoMuon.MuonSeedGenerator.CosmicMuonSeedProducer_cfi")
process.load("RecoMuon.CosmicMuonProducer.cosmicMuons_cfi")

#Geometry
process.load("Geometry.DTGeometry.dtGeometry_cfi")
process.load("Alignment.CommonAlignmentProducer.GlobalPosition_Fake_cff")

#process.myMuonRPCDigis = cms.EDProducer('RPCDigiCleaning',
 #                                        GMTInputTag = cms.InputTag("hltMuonRPCDigis")
#)

process.load("UserCode.RPCDigiCleaning.rpcdigicleaning_cfi")
process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string('myOutputFile.root'),
                               outputCommands = cms.untracked.vstring(
    "drop *",
    "keep *DigiCollection_*_*_*")
    
)

  
#process.p = cms.Path(process.myMuonRPCDigis)
process.p = cms.Path(process.muonRPCDigisClean)

process.e = cms.EndPath(process.out)
