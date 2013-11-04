import FWCore.ParameterSet.Config as cms



muonRPCDigisClean = cms.EDProducer('RPCDigiCleaning',
                                   GMTInputTag = cms.InputTag("hltMuonRPCDigis")
                              
)
