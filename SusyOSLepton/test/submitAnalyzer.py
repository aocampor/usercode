import sys
from optparse import OptionParser
#-----------------------------------------------------
#-----------------------------------------------------
parser = OptionParser()
parser.add_option("-r", type = "string", dest="dataset",
                  help="Run id (dataset)" )

(options, args) = parser.parse_args()

if options.dataset is None:
        parser.error("please give a run ID dataset type")
#-----------------------------------------------------
#-----------------------------------------------------

from GangaCMS.Lib.CMSexe import *

dataset  = options.dataset
indata  = options.dataset
#infile = indata + '/list_of_files.txt'

cmsswver = 'CMSSW_2_2_9'

#inputpath = '/castor/cern.ch/user/s/sanabria/gridfiles/Summer09/SUSY_LM0_229_SUSYPAT_V5_v1/'

prefix   = '/afs/cern.ch/user/s/sanabria/'+cmsswver+'/src/SusyAnalyzers/SusyOSLepton/test/'

cfg_file = prefix + 'susyoslepton_cfg.py' 

app = cmsRun()
app.uselibs = 1
app.version = cmsswver
app.user_release_area='/afs/cern.ch/user/s/sanabria'

#ff = File( name=infile )
#ff.subdir = inputpath
#fdata = CMSDataset( ff , 'castor' )

fdata = CMSDataset()
fdata.SetDatasetFromTwiki(indata,'grid')
#fdata.SetMaxFiles(10)

sp = SplitByFiles()
sp.filesPerJob = 3
sp.maxFiles = -1

rm = RootMerger()
rm.files = ['RA6.root']
rm.overwrite = True
rm.ignorefailed = True

app.cfgfile = File( name=cfg_file )

#myjob = Job( application = app, backend = 'LSF' )
myjob = Job( application = app, backend = 'LCG' )

myjob.name = 'susy.analyzers.' + dataset
myjob.inputdata = fdata
myjob.inputdata.type = 'PoolSource'

myjob.outputsandbox = ['RA6.root']

myjob.splitter = sp
myjob.merger = rm

#myjob.backend.queue = '1nh'

#myjob.backend.queue = '8nh'

#myjob.backend.queue = 'cmscaf1nh'

#myjob.backend.queue = 'cmscaf8nh'

#myjob.backend = 'LCG'
myjob.backend.middleware = 'GLITE'
#myjob.backend.CE = 'kuragua.uniandes.edu.co:2119/jobmanager-lcgpbs-cms'

myjob.backend.CE = 'hephygr.oeaw.ac.at:2119/jobmanager-lcgpbs-cms'


myjob.submit()

print "job submission done."

