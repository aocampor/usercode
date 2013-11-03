import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

#from Alignment.CommonAlignmentProducer.DBConfiguration_cff import PoolDBESSource

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
#        'file:myfile.root'
           '/store/data/Commissioning09/Cosmics/RECO/v4/000/102/352/E68ADFB9-BE6A-DE11-B9E9-000423D94A20.root',
                '/store/data/Commissioning09/Cosmics/RECO/v4/000/102/352/DA5B58CF-C06A-DE11-B7DE-001D09F28755.root',
                '/store/data/Commissioning09/Cosmics/RECO/v4/000/102/352/C4AB9411-066D-DE11-86DA-001D09F253C0.root',
                '/store/data/Commissioning09/Cosmics/RECO/v4/000/102/352/B0B1D06F-6469-DE11-A3B0-001D09F28F25.root',
                '/store/data/Commissioning09/Cosmics/RECO/v4/000/102/352/4A8EABCF-C06A-DE11-90DE-0030487A18F2.root',
                '/store/data/Commissioning09/Cosmics/RECO/v4/000/102/352/38C1F8E6-C76A-DE11-891F-000423D99AAA.root'
    )
)

#process.load("Configuration.GlobalRuns.ForceZeroTeslaField_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = 'GR09_31X_V5P::All'
#process.GlobalTag.globaltag = 'IDEAL_V9::All'
process.prefer("GlobalTag")
process.load("Configuration.StandardSequences.ReconstructionCosmics_cff")
process.load("RecoMuon.MuonIdentification.muonIdProducerSequence_cff")
process.load("RecoMuon.MuonIdentification.links_cfi")

#import FWCore.Framework.test.cmsExceptionsFatalOption_cff
#options = cms.untracked.PSet(
 #   Rethrow = FWCore.Framework.test.cmsExceptionsFatalOption_cff.Rethrow
  #  )

process.load("Geometry.MuonNumbering.muonNumberingInitialization_cfi")
# Magnetic Field
#process.load("MagneticField.VolumeBasedEngine.volumeBasedMagneticField_cfi")
process.load("Configuration.StandardSequences.Geometry_cff")
#process.load("Geometry.MuonCommonData.muonIdealGeometryXML_cfi")
#process.load("Geometry.RPCGeometry.rpcGeometry_cfi")
process.load("Configuration.StandardSequences.MagneticField_cff")
# Geometries
#process.load("Geometry.CMSCommonData.cmsIdealGeometryXML_cff") 
#process.load("Geometry.CommonDetUnit.bareGlobalTrackingGeometry_cfi")
#process.load("Geometry.DTGeometry.dtGeometry_cfi")
#process.load("Geometry.CSCGeometry.cscGeometry_cfi")
#process.load("Geometry.RPCGeometry.rpcGeometry_cfi")
#process.load("RecoMuon.DetLayers.muonDetLayerGeometry_cfi")
#process.load("Alignment.CommonAlignmentProducer.GlobalPosition_Frontier_cff")

#process.load("PhysicsTools.HepMCCandAlgos.genParticleCandidates_cfi")
#process.load("Configuration.StandardSequences.L1Emulator_cff")


##CaloMuons
process.load("RecoTracker.GeometryESProducer.TrackerRecoGeometryESProducer_cfi")


# This is a fix for "No TrackingComponentsRecord found in the EventSetup."
process.load("RecoTracker.CkfPattern.CkfTrackCandidates_cff")
 
 # This is needed for rec tracks
process.load("TrackPropagation.SteppingHelixPropagator.SteppingHelixPropagatorAny_cfi")

process.load("RecoMuon.MuonIdentification.caloCompatibility_cff")
process.load("TrackingTools.TrackAssociator.default_cfi")
process.load("RecoMuon.MuonIdentification.calomuons_cfi")

process.load("Geometry.CaloEventSetup.CaloGeometry_cff")


from TrackingTools.TrackAssociator.default_cfi import *
from TrackingTools.TrackAssociator.DetIdAssociatorESProducer_cff import *
from RecoMuon.MuonIdentification.caloCompatibility_cff import *

process.load("RecoMuon.MuonIdentification.muonIdProducerSequence_cff")
from RecoMuon.MuonIdentification.muonIdProducerSequence_cff import *


process.calomuons.minCaloCompatibility = 0.0
process.calomuons.inputTracks = 'cosmicMuons'

process.demo = cms.EDAnalyzer('CosmicsCaloCom'
)
process.TFileService = cms.Service("TFileService", fileName = cms.string('cosmicmuons.root') )

process.p = cms.Path(process.calomuons*process.demo)
