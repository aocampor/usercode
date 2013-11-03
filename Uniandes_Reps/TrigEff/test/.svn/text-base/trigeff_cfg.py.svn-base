import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
#        'file:myfile.root'
#    '/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0005/26F5D1C5-E1C2-DD11-9373-0019B9E4FCD0.root'
#    '/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0001/325DAB5D-02C2-DD11-9EA5-001D0967C653.root' ##67181
    '/store/data/Commissioning08/Cosmics/RECO/CRAFT_ALL_V4_ReReco-v1/0000/B271F089-61C1-DD11-A9F3-001D0967DAFD.root'  ##69912
    )
)

process.demo = cms.EDAnalyzer('TrigEff',
                              GMTInputTag = cms.InputTag("gtDigis"),
                              histoName = cms.untracked.string("TriggerEff.root")
)

#process.dump=cms.EDAnalyzer('EventContentAnalyzer')
process.p = cms.Path(process.demo)
#process.p=cms.Path(process.dump)

