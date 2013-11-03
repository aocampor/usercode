import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")


maxevts   = -1
#inputfile = 'rfio:/castor/cern.ch/user/s/sanabria/gridfiles/Summer09/SUSY_LM0_229_SUSYPAT_V5_v1/patLayer1_1.root'
inputfile = 'file:/lustre/home/ocampo/CMSSW_3_3_2/src/MCLM0_prod/LM0/PF/PF2PAT_full.root'
#inputfile = 'file:/lustre/cms/store/user/aocampor/SUSY/LM0/PF/LM0_SUSY_PF_10.root'

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32( maxevts ) )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring( inputfile ) )

process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = 'STARTUP31X_V2::All'
process.load("Configuration.StandardSequences.MagneticField_cff")

# PAT Layer 0+1
#process.load("PhysicsTools.PatAlgos.patLayer0_cff")
#process.load("PhysicsTools.PatAlgos.patLayer1_cff")
#process.load("PhysicsTools.PatAlgos.patSequences_cff")
process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")

process.demo = cms.EDAnalyzer('SusyOSLepton',
#                              MuonTag = cms.InputTag("cleanLayer1Muons"),
 #                             ElectronTag = cms.InputTag("cleanLayer1Electrons"),
  #                            JetTag = cms.InputTag("cleanLayer1JetsIC5"),
   #                           MetTag = cms.InputTag("layer1METsIC5"),
                              MuonTag = cms.InputTag("selectedLayer1Muons"),
                              ElectronTag = cms.InputTag("selectedLayer1Electrons"),
                              JetTag = cms.InputTag("selectedLayer1Jets"),
                              MetTag = cms.InputTag("layer1METs"),
                              CutsMask = cms.vuint32(1,1,1,1,1,1,1,1),
#                              CutsMask = cms.vuint32(0,0,0,0,0,0,0,0), #no original
                              #MuonIsoCut = cms.double(0.1),
                              MuonIsoCut = cms.double(0.1),  ## fake
                              #MuonPtCut = cms.double(20.0),
                              MuonPtCut = cms.double(20.0),  #fake
                              #MuonEtaCut = cms.double(2.1),
                              MuonEtaCut = cms.double(2.1),   ##fake
                              #MuonChiDoFCut = cms.double(10.0),
                              MuonChiDoFCut = cms.double(10.0),       #fake
                              #Muond0Cut = cms.double(0.2),
                              Muond0Cut = cms.double(0.2),   ## fake
                              #MuonTrkCut = cms.int32(11),
                              MuonTrkCut = cms.int32(11),   ## fake
                              #MuonHCalECut = cms.double(6.0),
                              MuonHCalECut = cms.double(6.0),    ## fake
                              #MuonECalECut = cms.double(4.0),
                              MuonECalECut = cms.double(4.0),   ## fake
                              #ElecPtCut = cms.double(20.0),
                              ElecPtCut = cms.double(20.0),    ## fake
                              #ElecEtaCut = cms.double(2.5),
                              ElecEtaCut = cms.double(2.5),     ##fake
                              #ElecIsoCut = cms.double(0.1),
                              ElecIsoCut = cms.double(0.1),    ## fake
                              #Elecd0Cut = cms.double(0.2),
                              Elecd0Cut = cms.double(0.2),    ## fake
                              #ElectronCut = cms.int32(0),
                              ElectronCut = cms.int32(0),   ## fake
                              METCut = cms.double(100.0),   ## fake
                              #METCut = cms.double(100.0),
                              JetNumCut = cms.uint32(3),   ## fake
                              #JetNumCut = cms.uint32(3),
                              #JetPtCut = cms.double(50.0),   
                              JetPtCut = cms.double(50.0),   ## fake
                              #JetEtaCut = cms.double(2.4),
                              JetEtaCut = cms.double(2.4),    ##fake
                              #JetEMFCut = cms.double(0.1),
                              JetEMFCut = cms.double(0.1),    ## fake
                              PF2PAT = cms.int32(1)
                              )

#process.content = cms.EDAnalyzer("EventContentAnalyzer")

process.TFileService = cms.Service("TFileService", fileName = cms.string('PF_par.root') )

process.p = cms.Path(
    # process.patLayer0*
    # process.patLayer1*
    #(process.patLayer1 +process.content)*
    process.demo)
