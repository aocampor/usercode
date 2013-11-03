import FWCore.ParameterSet.Config as cms

process = cms.Process("COPY")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring("/store/relval/CMSSW_2_1_6/RelValTTbar/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v1/0000/00B3662C-DA78-DD11-88E6-001617C3B70E.root")
                            )

process.copyAll = cms.OutputModule("PoolOutputModule", fileName = cms.untracked.string("reco.root") )
process.printEventNumber = cms.EDAnalyzer("AsciiOutputModule")
process.out = cms.EndPath(process.copyAll + process.printEventNumber)


