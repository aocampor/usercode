import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
       "rfio:/castor/cern.ch/cms/store/data/BeamCommissioning08/Cosmics/RECO/v1/000/062/815/003EA8C7-D583-DD11-A955-001617C3B6FE.root",
"rfio:/castor/cern.ch/cms/store/data/BeamCommissioning08/Cosmics/RECO/v1/000/062/815/0041569E-DF83-DD11-9BA8-001617C3B6E8.root"
#"rfio:/castor/cern.ch/cms/store/data/BeamCommissioning08/Cosmics/RECO/v1/000/062/815/029AD8F8-9383-DD11-9B9A-000423D9880C.root",
#"rfio:/castor/cern.ch/cms/store/data/BeamCommissioning08/Cosmics/RECO/v1/000/062/815/06668D07-D883-DD11-BBCF-000423D944F8.root",
#"rfio:/castor/cern.ch/cms/store/data/BeamCommissioning08/Cosmics/RECO/v1/000/062/815/06CB2DB3-CC83-DD11-B7C7-000423D6B42C.root",
#"rfio:/castor/cern.ch/cms/store/data/BeamCommissioning08/Cosmics/RECO/v1/000/062/815/06F9F840-DC83-DD11-AECF-000423D98750.root",
#"rfio:/castor/cern.ch/cms/store/data/BeamCommissioning08/Cosmics/RECO/v1/000/062/815/0876C3C6-D583-DD11-941F-001617E30CD4.root",
#"rfio:/castor/cern.ch/cms/store/data/BeamCommissioning08/Cosmics/RECO/v1/000/062/815/08F4D475-DD83-DD11-8AD0-000423D944DC.root",
#"rfio:/castor/cern.ch/cms/store/data/BeamCommissioning08/Cosmics/RECO/v1/000/062/815/0ADAFFC9-D583-DD11-902A-000423D99AA2.root"

    )
)

process.demo = cms.EDAnalyzer("Beam",
    hist_bins = cms.untracked.int32(500000),
    hist_min = cms.untracked.int32(-77),
    hist_max = cms.untracked.int32(173),
    hist_bins_e = cms.untracked.int32(550000),
    hist_min_e = cms.untracked.int32(0),
    hist_max_e = cms.untracked.int32(550000),
    Root_file = cms.untracked.string("Time_analysis_62815_cham.root")
)


process.p = cms.Path(process.demo)
