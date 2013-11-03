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
                                

#
# main
#

if __name__ == "__main__":

    detString = DetectFiles()

    me = [item[:-1] for item in os.popen('whoami')]
    casa = [item[:-1] for item in os.popen('echo $HOME')]
    pwd = [item[:-1] for item in os.popen('pwd')]

    ds = str(sys.argv[1]).replace('/','')

    tmpath = '/tmp/' + me[0] +'/'
    tmpath0 = '/tmp/' + me[0] +'/'+str(sys.argv[2])+ '/' 
    tmpath1 = casa[0] + '/scratch0/' + str(sys.argv[2]) + '/job/'

    os.system('mkdir ' + tmpath)
    os.system('mkdir ' + tmpath0)
    os.system('mkdir ' + tmpath1)
    os.system('mkdir ' + casa[0] + '/scratch0/' + str(sys.argv[2]))

    path = '/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[2]) + '/root'
    path1 = '/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[2]) + '/noise'

    os.system('cp MergeJobTemplate.job ' +tmpath1+'MergeJobTemplate_noise_' + str(sys.argv[2]) + '.job' )
    detString.replacesingle(tmpath1 +'MergeJobTemplate_noise_' + str(sys.argv[2]) + '.job' ,['----RUN-NUMBER----',str(sys.argv[2])])

##     strip_files = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + ' | grep Merge_Strips | wc | awk \'{print $1}\'' )]
##     if(strip_files[0] > 0 ):
##         fh = open(tmpath1 + 'MergeJobTemplate_noise_' + str(sys.argv[2]) + '.job','a')
##         fh.writelines('\n rm -f ' + tmpath0 + 'Strips*.root \n')
##         fh.writelines('rm -f ' + tmpath0 + 'Merge*.root \n')
##         fh.writelines('cp '+pwd[0]+'/noise_run_analyzer.py ' + tmpath0 +'\n')
##         fh.writelines('chmod a+x ' + tmpath0 + 'noise_run_analyzer.py\n')
##         fh.writelines('cp '+pwd[0]+'/wheel_noise_producer.py ' + tmpath0 +'\n')
##         fh.writelines('chmod a+x ' + tmpath0 + 'wheel_noise_producer.py\n')
##         fh.writelines('cp '+pwd[0]+'/plot_producer1.py ' + tmpath0 +'\n')
##         fh.writelines('chmod a+x ' + tmpath0 + 'plot_producer1.py\n')
##         fh.writelines('cp '+pwd[0]+'/plot_davide.py ' + tmpath0 +'\n')
##         fh.writelines('chmod a+x ' + tmpath0 + 'plot_davide.py\n')    
##         fh.writelines('cp '+pwd[0]+'/plot_producer.py ' + tmpath0 +'\n')
##         fh.writelines('chmod a+x ' + tmpath0 + 'plot_producer.py\n')
##         #    fh.writelines('cp '+pwd[0]+'/end_noise_producer.py ' + tmpath0 +'\n')
##         #   fh.writelines('chmod a+x ' + tmpath0 + 'end_noise_producer.py\n')
##         fh.writelines('cp '+pwd[0]+'/summary_plot_producer.py ' + tmpath0 +'\n')
##         fh.writelines('chmod a+x ' + tmpath0 + 'summary_plot_producer.py\n')
##         fh.writelines('cp '+pwd[0]+'/summary_plot_producer_end.py ' + tmpath0 +'\n')
##         fh.writelines('chmod a+x ' + tmpath0 + 'summary_plot_producer_end.py\n')    
##         fh.writelines('cp '+pwd[0]+'/plot_producer1_end.py ' + tmpath0 +'\n')
##         fh.writelines('chmod a+x ' + tmpath0 + 'plot_producer1_end.py\n')
##         fh.writelines('cp '+pwd[0]+'/plot_producer_end.py ' + tmpath0 +'\n')
##         fh.writelines('chmod a+x ' + tmpath0 + 'plot_producer_end.py\n')
##         fh.writelines('cp '+pwd[0]+'/noise_summary_plot_producer.py ' + tmpath0 +'\n')
##         fh.writelines('chmod a+x ' + tmpath0 + 'noise_summary_plot_producer.py\n')
        
##         fh.writelines('cmsStageIn ' + path1 +'/Merge_Strips_01.root .\n')
##         fh.writelines('mv Merge_Strips_01.root '+tmpath0+'/'+str(sys.argv[2])+'_01.root \n')    
##         fh.writelines('cmsStageIn ' + path1 +'/Merge_Strips_02.root .\n')
##         fh.writelines('mv Merge_Strips_02.root '+tmpath0+'/'+str(sys.argv[2])+'_02.root \n')
##         fh.writelines('cmsStageIn ' + path1 +'/Merge_Strips_00.root .\n')
##         fh.writelines('mv Merge_Strips_00.root '+tmpath0+'/'+str(sys.argv[2])+'_00.root \n')
##         fh.writelines('cmsStageIn ' + path1 +'/Merge_Strips_0m1.root .\n')
##         fh.writelines('mv Merge_Strips_0m1.root '+tmpath0+'/'+str(sys.argv[2])+'_0m1.root \n')
##         fh.writelines('cmsStageIn ' + path1 +'/Merge_Strips_0m2.root .\n')
##         fh.writelines('mv Merge_Strips_0m2.root '+tmpath0+'/'+str(sys.argv[2])+'_0m2.root \n')
##         fh.writelines('cmsStageIn ' + path1 +'/Merge_Strips_11.root .\n')
##         fh.writelines('mv Merge_Strips_11.root '+tmpath0+'/'+str(sys.argv[2])+'_11.root \n')    
##         fh.writelines('cmsStageIn ' + path1 +'/Merge_Strips_12.root .\n')
##         fh.writelines('mv Merge_Strips_12.root '+tmpath0+'/'+str(sys.argv[2])+'_12.root \n')
##         fh.writelines('cmsStageIn ' + path1 +'/Merge_Strips_13.root .\n')
##         fh.writelines('mv Merge_Strips_13.root '+tmpath0+'/'+str(sys.argv[2])+'_13.root \n')
##         fh.writelines('cmsStageIn ' + path1 +'/Merge_Strips_m11.root .\n')
##         fh.writelines('mv Merge_Strips_m11.root '+tmpath0+'/'+str(sys.argv[2])+'_m11.root \n')
##         fh.writelines('cmsStageIn ' + path1 +'/Merge_Strips_m12.root .\n')
##         fh.writelines('mv Merge_Strips_m12.root '+tmpath0+'/'+str(sys.argv[2])+'_m12.root \n')
##         fh.writelines('cmsStageIn ' + path1 +'/Merge_Strips_m13.root .\n')
##         fh.writelines('mv Merge_Strips_m13.root '+tmpath0+'/'+str(sys.argv[2])+'_m13.root \n')
        
##         fh.writelines('./noise_run_analyzer.py ' + str(sys.argv[2]) + '\n')
##         fh.writelines('cmsStageOut '+str(sys.argv[2])+'_strip_final.root ' + path1 +'/ \n')
##         fh.writelines('rfchmod +777 /castor/cern.ch/cms' + path1 +'/'+str(sys.argv[2])+'_strip_final.root \n')
##         fh.close()
##         job = 'MergeJobTemplate_noise_' + str(sys.argv[2]) + '.job'
##         joberr = job + 'cerr'
##         jobout = job + 'cout'
##         os.system('chmod a+x '+tmpath1+'MergeJobTemplate_noise_' + str(sys.argv[2]) + '.job')
##         #    if(stopc == 0):
##        os.system('/afs/cern.ch/cms/caf/scripts/cmsbsub -q cmscaf1nd ' + ' -e ' +  tmpath1 + joberr + ' -o ' +  tmpath1 + jobout + ' ' + tmpath1 + job)
    noi = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + ' | grep Merge_Noise.root ' )]
    if(noi != []):
        fh = open(tmpath1 + 'MergeJobTemplate_noise_' + str(sys.argv[2]) + '.job','a')
        fh.writelines('rm -f ' + tmpath0 + 'Merge*.root \n')
        fh.writelines('cp '+pwd[0]+'/noise_summary_plot_producer.py ' + tmpath0 +'\n')
        fh.writelines('cp '+pwd[0]+'/area_noise.txt ' + tmpath0 +'\n')        
        fh.writelines('chmod a+x ' + tmpath0 + 'noise_summary_plot_producer.py\n')
        fh.writelines('./noise_summary_plot_producer.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' \n' )
        fh.writelines('cmsStageOut '+str(sys.argv[2])+'_final.root ' + path1 +'/ \n')
        fh.writelines('rfchmod +777 /castor/cern.ch/cms' + path1 +'/'+str(sys.argv[2])+'_final.root \n')
        fh.close()
        job = 'MergeJobTemplate_noise_' + str(sys.argv[2]) + '.job'
        joberr = job + 'cerr'
        jobout = job + 'cout'
        os.system('chmod a+x '+tmpath1+'MergeJobTemplate_noise_' + str(sys.argv[2]) + '.job')
        #    if(stopc == 0):
        os.system('/afs/cern.ch/cms/caf/scripts/cmsbsub -q cmscaf1nd ' + ' -e ' +  tmpath1 + joberr + ' -o ' +  tmpath1 + jobout + ' ' + tmpath1 + job)
    print 'Done Final Noise merge!!!'
        
