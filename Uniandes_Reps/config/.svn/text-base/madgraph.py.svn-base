# Auto generated configuration file
# using:
# Revision: 1.123.4.3
# Source: /cvs_server/repositories/CMSSW/CMSSW/Configuration/PyReleaseValidation/python/ConfigBuilder.py,v
# with command line options: MCDBtoEDM592 -s NONE --filein=mcdb:592 --fileout=EDM.root --conditions FrontierConditions_GlobalTag,MC_31X_V3::All --number 100 --mc --no_exec --datatier GEN
import FWCore.ParameterSet.Config as cms

process = cms.Process('LHE')

# import of standard configurations
process.load('Configuration/StandardSequences/Services_cff')
process.load('FWCore/MessageService/MessageLogger_cfi')
process.load('Configuration/StandardSequences/MixingNoPileUp_cff')
process.load('Configuration/StandardSequences/GeometryIdeal_cff')
process.load('Configuration/StandardSequences/MagneticField_38T_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load('Configuration/EventContent/EventContent_cff')

process.configurationMetadata = cms.untracked.PSet(
        version = cms.untracked.string('$Revision: 1.123.4.3 $'),
            annotation = cms.untracked.string('MCDBtoEDM592 nevts:100'),
            name = cms.untracked.string('PyReleaseValidation')
        )
process.maxEvents = cms.untracked.PSet(
        input = cms.untracked.int32(100)
        )
process.options = cms.untracked.PSet(
        Rethrow = cms.untracked.vstring('ProductNotFound')
        )
# Input source
process.source = cms.Source("MCDBSource",
                                articleID = cms.uint32(592),
                                supportedProtocols = cms.untracked.vstring('rfio')
                            )

# Output definition
process.output = cms.OutputModule("PoolOutputModule",
                                      splitLevel = cms.untracked.int32(0),
                                      outputCommands = process.RECOSIMEventContent.outputCommands,
                                      fileName = cms.untracked.string('EDM.root'),
                                      dataset = cms.untracked.PSet(
            dataTier = cms.untracked.string('GEN'),
                    filterName = cms.untracked.string('')
                )
                                  )

# Additional output definition

# Other statements
process.GlobalTag.globaltag = 'MC_31X_V3::All'

# Path and EndPath definitions
process.out_step = cms.EndPath(process.output)

# Schedule definition
process.schedule = cms.Schedule(process.out_step)

