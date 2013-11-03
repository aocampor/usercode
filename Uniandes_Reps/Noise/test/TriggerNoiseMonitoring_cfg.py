#
# cfg file to run L1GmtTriggerSource
#

import FWCore.ParameterSet.Config as cms

# process
process = cms.Process("TEST")

# number of events to be processed and source file
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(

        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/002914EB-29A6-DD11-9804-001D09F28F0C.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/00C4877E-5AA6-DD11-A21F-001D09F23A6B.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/00F08198-42A6-DD11-AF1C-001D09F295FB.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/02179A21-14A6-DD11-A76C-0030487C6062.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/0229B8A4-10A6-DD11-BD38-001D09F2AF96.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/04588A79-EDA5-DD11-A50B-000423D98EA8.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/048A337A-66A6-DD11-82DB-000423D986A8.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/049C7468-66A6-DD11-874E-001617C3B6E2.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/04BD9666-66A6-DD11-BC22-000423D998BA.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/04E7C11C-2EA6-DD11-BAA2-00161757BF42.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/04F877C6-3FA6-DD11-B89B-001D09F23A20.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/06056499-1CA6-DD11-B4FE-001D09F2516D.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/069EB55D-EBA5-DD11-9953-0030487C608C.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/080763E1-0DA6-DD11-94CC-001D09F291D2.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/082885F1-3CA6-DD11-B51A-001617E30F50.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/08AF0CE4-F5A5-DD11-91FA-001D09F251CC.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/0A51AB24-54A6-DD11-9B42-001D09F24448.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/0AF00B2B-3AA6-DD11-9435-0030487C6062.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/0AF3A4E8-12A6-DD11-B5C5-000423D6B444.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/0C2129FC-1DA6-DD11-BDC3-000423D98634.root',
        '/store/data/Commissioning08/Cosmics/RECO/v1/000/068/021/0C5D9091-EFA5-DD11-BB3F-0019B9F72BFF.root'

                                      )
)

process.load("Geometry.MuonNumbering.muonNumberingInitialization_cfi")

#Geometry
process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Geometry.MuonCommonData.muonIdealGeometryXML_cfi")
process.load("Geometry.RPCGeometry.rpcGeometry_cfi")
process.load("Geometry.DTGeometry.dtGeometry_cfi")
##process.load("Geometry.TrackerGeometryBuilder.idealForDigiTrackerGeometry_cff")
process.load("MagneticField.Engine.volumeBasedMagneticField_cfi")
##process.load("MagneticField.Engine.uniformMagneticField_cfi")
process.load("Alignment.CommonAlignmentProducer.GlobalPosition_Fake_cff")

##process.load("Geometry.EcalCommonData.EcalOnly_cfi")
##process.load("Geometry.EcalMapping.EcalMapping_cfi")
##process.load("Geometry.EcalMapping.EcalMappingRecord_cfi")


process.load("RecoLocalMuon.Configuration.RecoLocalMuonCosmics_cff")
process.load("RecoMuon.Configuration.RecoMuonCosmics_cff")
process.load("RecoMuon.MuonSeedGenerator.CosmicMuonSeedProducer_cfi")
process.load("RecoMuon.CosmicMuonProducer.cosmicMuons_cfi")

process.TriggerNoiseMonitoring = cms.EDAnalyzer("TriggerNoiseMonitoring",
                               GMTInputTag = cms.InputTag("gtDigis"),

                               labelDT = cms.untracked.string("muonDTDigis"),
                               histoName = cms.untracked.string("RPCTriggerNoiseMonitoring.root")          
)

process.MessageLogger = cms.Service("MessageLogger",
   destinations = cms.untracked.vstring('cout')
)

# path to be run
process.p = cms.Path(process.TriggerNoiseMonitoring)

