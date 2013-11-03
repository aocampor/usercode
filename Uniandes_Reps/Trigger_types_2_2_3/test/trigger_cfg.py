import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(

#    '/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0049/049EEF80-E8CA-DD11-9228-0019B9E7DE7D.root'
#    '/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0051/A8041014-E8CB-DD11-8885-0019B9E4B010.root'
        'file:/afs/cern.ch/user/a/aosorio/public/for_Alberto/digis.root'
                                
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


process.demo = cms.EDAnalyzer('Trigger',
                                                            histoName = cms.untracked.string("Reigger.root"),
)


process.p = cms.Path(process.demo)
