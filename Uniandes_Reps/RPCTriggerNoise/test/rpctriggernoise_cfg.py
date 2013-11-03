import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(2000) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
                            fileNames = cms.untracked.vstring(
    '/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0000/46FF6C90-71C1-DD11-A71F-0019B9E4FFE1.root'
    )
)

process.load("Geometry.MuonNumbering.muonNumberingInitialization_cfi")

#Geometry
process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Geometry.MuonCommonData.muonIdealGeometryXML_cfi")
process.load("Geometry.RPCGeometry.rpcGeometry_cfi")
process.load("MagneticField.Engine.volumeBasedMagneticField_cfi")
process.load("RecoLocalMuon.Configuration.RecoLocalMuonCosmics_cff")
process.load("RecoMuon.Configuration.RecoMuonCosmics_cff")
process.load("RecoMuon.MuonSeedGenerator.CosmicMuonSeedProducer_cfi")
process.load("RecoMuon.CosmicMuonProducer.cosmicMuons_cfi")

#Geometry
process.load("Geometry.DTGeometry.dtGeometry_cfi")
process.load("Alignment.CommonAlignmentProducer.GlobalPosition_Fake_cff")


process.demo = cms.EDAnalyzer('RPCTriggerNoise',
                              root_file_name = cms.untracked.string("RPCTrigerNoise.root"),
                              GMTInputTag = cms.InputTag("gtDigis"),
                              labelDT = cms.untracked.string("muonDTDigis"),
                              bins = cms.untracked.int32(10000),
                              hours = cms.untracked.int32(3)
)


process.p = cms.Path(process.demo)
