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
runid  = options.dataset
infile = runid + '/list_of_files.txt'

cmsswver = 'CMSSW_2_2_9'

inputpath = '/dpm/uniandes.edu.co/home/cms/user/a/aosorio/gridfiles/SUSY/Summer09/SUSY_LM0_229_SUSYPAT_V5_v1/'

prefix   = '/afs/cern.ch/user/a/aosorio/scratch0/'+cmsswver+'/src/SusyAnalyzers/SusyOSLepton/test/'

cfg_file = prefix + 'susyoslepton_cfg.py' 

app = cmsRun()
app.uselibs = 1
app.version = cmsswver

ff = File( name=infile )
ff.subdir = ff.subdir = inputpath + '/'
fdata = CMSDataset( ff , 'castor' )

sp = SplitByFiles()
sp.filesPerJob = 1
sp.maxFiles = -1

rm = RootMerger()
rm.files = ['RA6.root']
rm.overwrite = True
rm.ignorefailed = True

app.cfgfile = File( name=cfg_file )

myjob = Job( application = app, backend = 'LSF' )
myjob.name = 'susy.analyzers.' + dataset
myjob.inputdata = fdata
myjob.inputdata.type = 'PoolSource'

myjob.outputsandbox = ['RA6.root']

myjob.splitter = sp
myjob.merger = rm

##myjob.backend.queue = '1nh'
##myjob.backend.queue = 'cmscaf1nh'
##myjob.backend.queue = 'cmscaf8nh'
##myjob.backend = 'Local'

CElement = 'kuragua.uniandes.edu.co:2119/jobmanager-lcgpbs-cms'

myjob.backend = 'LCG'
myjob.backend.middleware = 'GLITE'
myjob.backend.CE = CElement

myjob.submit()

print "job submission done."

