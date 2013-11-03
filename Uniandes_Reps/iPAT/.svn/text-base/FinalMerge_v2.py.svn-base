#! /usr/bin/env python
import commands, time
import sys, os, string, fileinput
from ROOT import *


def numfiles(dataset,runnum):
    total = [item[:-1] for item in os.popen('./aSearchCLI --dbsInst=cms_dbs_prod_global --limit=-1 --input \"find file where dataset like ' + dataset + ' and run = ' + runnum + '\" | grep -v root | awk \'{print $2}\'')]
    return total[1]

class DetectFiles:
    def f(self):
        return 'Detecting string!'

    def __init__(self):
        self.data = []

    def findPath(self,dataset,runNumber):
        cmd = './aSearchCLI --dbsInst=cms_dbs_prod_global --limit=10000 --input \" find file where dataset = ' + dataset + ' and ' + 'run = ' + runNumber +' \" | egrep \"[a-Z]\" | grep -v \"Found\" '
        the_files = [item[:-1] for item in os.popen(cmd)]
        print the_files
        return the_files

    def replaceStringInFile(self,namein,nameout,list):
        fin=open(namein, 'r')
        fout=open(nameout, 'w')
        for line in fin:
            for ilist in range(len(list)):
                if ilist%2 == 0:
                    lineno1 = 0
                    lineno1 = string.find(line, list[ilist])
                    if lineno1 > 0:
                        line =line.replace(list[ilist], list[ilist+1])
            fout.write(line)
                        
    def replacesingle(self,file,list):
        for line in fileinput.FileInput(file,inplace=1):
            line = line.replace(list[0],list[1])
            if line != '':
                print line
if __name__ == "__main__":

    detString = DetectFiles()

    me = [item[:-1] for item in os.popen('whoami')]
    casa = [item[:-1] for item in os.popen('echo $HOME')]
    pwd = [item[:-1] for item in os.popen('pwd')]

    ds = str(sys.argv[1]).replace('/','')

    tmpath = '/tmp/' + me[0] +'/'
    tmpath0 = '/tmp/' + me[0] +'/'+str(sys.argv[2])+ '/' 
    tmpath1 = casa[0] + '/scratch0/' + str(sys.argv[2]) + '/job/'


#    os.system('mkdir ' + tmpath)
    os.system('mkdir ' + tmpath0)
    os.system('mkdir ' + casa[0] + '/scratch0/' + str(sys.argv[2]))
    os.system('mkdir ' + tmpath1)
    
    path = '/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[2]) + '/root'
    path1 = '/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[2]) + '/noise'

    job = 'MergeJobTemplate_tot_' + str(sys.argv[2]) + '.job'
    os.system('cp MergeJobTemplate.job '+ tmpath1 + job )
    
    detString.replacesingle( tmpath1 + job ,['----RUN-NUMBER----',str(sys.argv[2])])
    
    fh = open( tmpath1 + job,'a')

    conti = True
    
    dqmsrpc_fil = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path + '/Merge_DQM_SRPC.root')]
    dqm_fil = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path + '/Merge_DQM.root')]
    srpc_fil = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path + '/Merge_SRPC.root')]
    grpc_fil = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path + '/Merge_GRPC.root')]
    if(dqmsrpc_fil != [] and grpc_fil != []):
        fh.writelines('cmsStageIn '+ path + '/' + 'Merge_DQM_SRPC.root .\n' )
        fh.writelines('cmsStageIn '+ path + '/' + 'Merge_GRPC.root .\n' )
        fh.writelines('hadd Merge_DQM_SRPC_GRPC.root Merge_DQM_SRPC.root Merge_GRPC.root \n')
    elif( dqmsrpc_fil != [] and grpc_fil == []):    
        fh.writelines('cmsStageIn '+ path + '/' + 'Merge_DQM_SRPC.root .\n' )
        fh.writelines('mv Merge_DQM_SRPC.root Merge_DQM_SRPC_GRPC.root \n')
    elif(dqm_fil != [] and srpc_fil != [] and grpc_fil != []):    
        fh.writelines('cmsStageIn '+ path + '/' + 'Merge_DQM.root .\n' )
        fh.writelines('cmsStageIn '+ path + '/' + 'Merge_GRPC.root .\n' )
        fh.writelines('cmsStageIn '+ path + '/' + 'Merge_SRPC.root .\n' )
        fh.writelines('hadd Merge_DQM_SRPC_GRPC.root Merge_DQM.root Merge_SRPC.root Merge_GRPC.root \n')
    elif(dqm_fil != [] and srpc_fil != [] and grpc_fil == []):    
        fh.writelines('cmsStageIn '+ path + '/' + 'Merge_DQM.root .\n' )
        fh.writelines('cmsStageIn '+ path + '/' + 'Merge_SRPC.root .\n' )
        fh.writelines('hadd Merge_DQM_SRPC_GRPC.root Merge_DQM.root Merge_SRPC.root \n')
    else :
        conti = False

    if(conti):
        fh.writelines('cmsStageOut Merge_DQM_SRPC_GRPC.root ' + path +'/Merge_DQM_SRPC_GRPC.root \n')
        fh.writelines('rfchmod +777 ' + path +'/Merge_DQM_SRPC_GRPC.root \n' )
    
    fh.writelines('cp '+pwd[0]+'/LastPlotStep.py ' + tmpath + str(sys.argv[2])+'\n')
    fh.writelines('chmod a+x ' + tmpath + str(sys.argv[2]) + '/LastPlotStep.py\n')
    fh.writelines('cp '+pwd[0]+'/GlobalPlotsProduction.py ' + tmpath + str(sys.argv[2])+'\n')
    fh.writelines('chmod a+x ' + tmpath + str(sys.argv[2]) + '/GlobalPlotsProduction.py\n')
    fh.writelines('cp '+pwd[0]+'/QualityPerformance.py ' + tmpath + str(sys.argv[2])+'\n')
    fh.writelines('chmod a+x ' + tmpath + str(sys.argv[2]) + '/QualityPerformance.py\n')
    fh.writelines('cp '+pwd[0]+'/EfficiencyPlotProductionDisk.py ' + tmpath + str(sys.argv[2])+'\n')
    fh.writelines('chmod a+x ' + tmpath + str(sys.argv[2]) + '/EfficiencyPlotProductionDisk.py\n')
    fh.writelines('cp '+pwd[0]+'/EfficiencyPlotProduction.py ' + tmpath + str(sys.argv[2])+'\n')
    fh.writelines('chmod a+x ' + tmpath + str(sys.argv[2]) + '/EfficiencyPlotProduction.py\n')
    fh.writelines('cp '+pwd[0]+'/disk_coord_old.txt ' + tmpath + str(sys.argv[2])+'\n')
    fh.writelines('cp '+pwd[0]+'/disk_coord.txt ' + tmpath + str(sys.argv[2])+'\n')
    fh.writelines('cp '+pwd[0]+'/wheel_coord.txt ' + tmpath + str(sys.argv[2])+'\n')
    
    fh.writelines('./LastPlotStep.py ' + str(sys.argv[1]) +  ' '  + str(sys.argv[2]) + '\n')    
    fh.close()
    
    joberr = job + 'cerr'
    jobout = job + 'cout'
    os.system('chmod a+x '+tmpath1+ job)
    if(conti):    
        os.system('/afs/cern.ch/cms/caf/scripts/cmsbsub -q cmscaf1nd ' + ' -e ' +  tmpath1 + joberr + ' -o ' +  tmpath1 + jobout + ' ' + tmpath1 + job)
    print 'Done Final merge!!!'            
