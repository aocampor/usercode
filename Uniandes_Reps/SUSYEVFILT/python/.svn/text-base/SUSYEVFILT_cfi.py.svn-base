import FWCore.ParameterSet.Config as cms

leptonfilter = cms.EDFilter("SUSYEVFILT",
                            HTCut = cms.double(0.0),
                            pfJetsColl = cms.InputTag("selectedPatJetsPF"),
                            JetsColl = cms.InputTag("cleanPatJetsIC5Calo"),
                            pfTausColl = cms.InputTag("selectedPatTausPF"),
                            TausColl = cms.InputTag("cleanPatTaus"),
                            pfElectronsColl = cms.InputTag("selectedPatElectronsPF"),
                            ElectronsColl = cms.InputTag("cleanPatElectrons"),
                            pfMuonsColl = cms.InputTag("selectedPatMuonsPF"),
                            MuonsColl = cms.InputTag("cleanPatMuons"),
                            SelElColl = cms.InputTag("cleanPatElectrons"),
                            SelMuColl = cms.InputTag("cleanPatMuons"),
                            PatElColl = cms.InputTag("cleanPatElectrons"),
                            PatMuColl = cms.InputTag("cleanPatMuons"),
                            pfSelElColl = cms.InputTag("pfAllElectronsPF"),
                            pfSelMuColl = cms.InputTag("pfAllMuonsPF"),
                            pfPatElColl = cms.InputTag("selectedPatElectronsPF"),
                            pfPatMuColl = cms.InputTag("selectedPatMuonsPF"),
                            PF2PAT = cms.int32(1),
                            prinel = cms.bool(True),
                            prinmu = cms.bool(True),
                            d0max = cms.double(0.1),
                            z0max = cms.double(0.2),
                            ptmin = cms.double(0),
                            ccone = cms.double(0.5),
                            cveto = cms.double(1e-05),
                            Rlist = cms.vdouble(0.1,0.2,0.3,0.4,0.5)
                            )
#FEVT = cms.OutputModule("PoolOutputModule",
 #                       outputCommands = cms.untracked.vstring("keep *_*_*_*"),
  #                      fileName = cms.untracked.string('pippo.root')
   #                     )

#lfseq = cms.Sequence(leptonfilter*FEVT)
