import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1))

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0000/46FF6C90-71C1-DD11-A71F-0019B9E4FFE1.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0000/8A9B693E-46C1-DD11-88D1-001D0967D558.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0000/9ACFD2EC-67C1-DD11-8CC2-001D0967CFCC.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0001/1EF817E4-CEC1-DD11-82F4-001D0967CFCC.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0001/3CB465BE-03C2-DD11-949C-001D0967D48B.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0001/5A00515D-B5C1-DD11-B6CE-001D0967D616.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0001/EEF3EDF1-D8C1-DD11-BBF7-0019B9E4FC1C.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0002/B0A82B97-1FC2-DD11-8734-001D0968F684.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0003/8494C44F-63C2-DD11-87F6-0019B9E4FF87.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0004/1A306101-93C2-DD11-A126-001D0967D512.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0004/E8288861-B3C2-DD11-92C8-0019B9E4B0D8.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0005/04A73F53-01C3-DD11-B055-0019B9E4FD5C.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0005/26F5D1C5-E1C2-DD11-9373-0019B9E4FCD0.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0005/44DE2797-FEC2-DD11-B629-0019B9E4FDB6.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0005/5403C6B8-18C3-DD11-84C6-001D0967D643.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0005/5448BB36-0BC3-DD11-B39B-001D0967DA3A.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0005/74D5AD21-35C3-DD11-9B0C-0019B9E714CE.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0005/8690E3F1-02C3-DD11-B430-0019B9E4F9B1.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0005/EE7C4F6A-D9C2-DD11-8938-0019B9E4AF4C.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0006/380E6A7E-6AC3-DD11-939D-001D0967BC66.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0006/62D593C4-45C3-DD11-9A13-001D0967D6AC.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0006/B0938B1B-D6C3-DD11-9150-001D0967C07B.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0006/C8F0F5B7-3CC3-DD11-9E3D-001D0967D24C.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0007/0C8C30D5-F5C3-DD11-91B9-0019B9E4F868.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0007/8C2EBED1-02C4-DD11-8FF1-001D0967D16B.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0007/8CEB9080-00C4-DD11-A19B-0019B9E4B07E.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0007/B6D6F63F-70C4-DD11-A9DF-001D0967DC92.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0007/D216EA0A-9CC4-DD11-8BDC-001D0967DA6C.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0008/C4E759BE-A6C4-DD11-B00A-001D0968F36E.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0013/B25FF569-35C5-DD11-BFDF-0019B9E7C849.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0017/D6C57972-9BC5-DD11-A9D6-0019B9E4AFDE.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0022/7C662B76-1CC6-DD11-A1D7-001D0967DF21.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0031/A4D506BB-13C7-DD11-9DDB-001D0967D25B.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0032/2EBF6767-24C7-DD11-9D8E-001D096B0E9F.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0033/32BF1C13-3DC7-DD11-9D97-001D0967D2E7.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0033/8EBFB40F-3DC7-DD11-9D73-0019B9E4FB72.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0035/02BDECA1-A1C7-DD11-97F7-0019B9E7CA12.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0035/786F597D-BDC7-DD11-BF44-0019B9E48BF5.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0035/9E954F39-DDC7-DD11-B34B-001D0967E061.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0035/BA713B0E-ACC7-DD11-9F64-001D0968F26A.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0045/145BAB41-88C8-DD11-9A55-001D0967C1E9.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0045/309FD486-A5C8-DD11-B35A-001D0967C987.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0045/A845FF72-A7C8-DD11-B914-001D09675C47.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0045/D2F56B9D-A4C8-DD11-B141-0019B9E4FA2B.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0047/3825A915-1DC9-DD11-91B9-0019B9E7E9AE.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0047/44CA5F5C-3CC9-DD11-99F9-001D0968C880.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0047/708D36F5-28C9-DD11-BDFB-0019B9E4FA2B.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0047/744DCA87-20C9-DD11-91E3-0019B9E4FD5C.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0047/9CD3A28B-27C9-DD11-8A5F-001D0967D67F.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0047/F0B0389B-FBC8-DD11-B5A3-0019B9E489B4.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0048/B6CA31E1-03CA-DD11-AF1A-0019B9E4FBC7.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0048/F80F86B2-F7C9-DD11-9A2D-0019B9E4FB68.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0048/FA93E4A8-EAC9-DD11-905A-001D0967BE87.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0049/1856A518-38CB-DD11-ABB2-001D0967D021.root',
        #'/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0049/F03DE038-19CA-DD11-9868-001D0968F26A.root',
        '/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0050/C04E3F69-84CB-DD11-923C-0019B9E7C077.root'
        
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

process.demo = cms.EDAnalyzer('TBXanal',
                              GMTInputTag = cms.InputTag("gtDigis"),
                              histoName = cms.untracked.string("RPCTriggerNoiseMonitoring.root"),
                              numbins = cms.untracked.int32( 100000 )
                              )

process.filter = cms.EDFilter("Filter")

process.out = cms.OutputModule( "PoolOutputModule",
                                fileName = cms.untracked.string( 'out.root' ),
                                SelectEvents = cms.untracked.PSet( SelectEvents = cms.vstring( SelectEvents = cms.vstring("Filter"))
                                                                   ),
                                outputCommands = cms.untracked.vstring('drop *',
                                                                       "keep *_muonRPCDigis_*_*",
                                                                       "keep *_gtDigis_*_*"
                                                                       )
    )


process.p = cms.Path(process.filter*process.demo)
#process.p = cms.Path(process.demo)
#process.e = cms.EndPath( process.out )
