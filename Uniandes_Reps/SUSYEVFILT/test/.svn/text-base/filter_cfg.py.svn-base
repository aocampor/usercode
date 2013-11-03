import FWCore.ParameterSet.Config as cms

#process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
#'file:/cmshome/aocampor/CMSSW_3_6_1/src/PAT/LM0/LM0_7TeV_PATrereco.root'    
#'/store/user/aocampor/DATA/aocampor/MinimumBias/7TeVReReco/PFandPAT/PF2PAT_DATA7TeV_rereco_993.root.root'
'/store/user/aocampor/LM0/aocampor/LM0/LM07_TeVReReco_v2/PF2PAT/PF2PAT_LM07TeV_rereco_100.root.root'
    )
)
#from SusyAnalyzers.SUSYEVFILT.SUSYEVFILT_cfi import *
process.load("SusyAnalyzers.SUSYEVFILT.SUSYEVFILT_cfi")

process.p = cms.Path(process.leptonfilter)
#process.p = cms.Path(process.leptonfilter*process.demo)

process.out = cms.OutputModule("PoolOutputModule",
                               SelectEvents = cms.untracked.PSet( SelectEvents = cms.vstring('p') ),
                               outputCommands = cms.untracked.vstring("keep *"),
                               fileName = cms.untracked.string('pippo.root')
                               )

#process.TFileService = cms.Service("TFileService", fileName = cms.string('LM0_ntuple.root') )

process.e = cms.EndPath(process.out)
