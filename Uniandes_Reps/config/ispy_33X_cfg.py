import FWCore.ParameterSet.Config as cms

process = cms.Process("IGUANA")
process.load("ISpy/Analyzers/ISpy_Producer_cff")
process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load('Configuration.StandardSequences.VtxSmearedEarly10TeVCollision_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.GlobalTag.globaltag = 'MC_31X_V9::All'

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring('file:/lustre/cms/store/user/aocampor/SUSY/LM0/MC_31X_V3_7TeV-v1/PFandPAT/aocampor/LM0/LM0_7TeV_PF2PATandPATuple_OCAMPO/15b965e62687e4f6db82f42f1f6c01bb/LM0_PF2PATandPATuple_85.root'
                                                              )
)

from FWCore.MessageLogger.MessageLogger_cfi import *

process.add_(
    cms.Service("ISpyService",
    outputFileName = cms.untracked.string('RelValTTbar.ig')
    )
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(5)
)

process.p1 = cms.Path(process.iSpy_sequence)
