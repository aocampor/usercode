#! /usr/bin/env python
import commands
import sys, os, string, fileinput
from ROOT import *


#
# main
#

if __name__ == "__main__":

    dataset = str(sys.argv[1])
    ds = str(sys.argv[1]).replace('/','')  
     
#    path = '/castor/cern.ch/user/a/aocampor/NOISE/' + ds + '/' + str(sys.argv[2]) + '/root'
    
    cmd0 = 'whoami'
    user = [item[:-1] for item in os.popen(cmd0)]
    tmppath = '/tmp/' + user[0] + '/'

    cmd = './aSearchCLI --dbsInst=cms_dbs_prod_global --limit=-1 --input \"find file where dataset = ' + dataset + ' and ' + 'run = ' + str(sys.argv[2]) + ' \" | egrep \"[a-Z]\" | grep -v \"Found\" '
    the_files = [item[:-1] for item in os.popen(cmd)]

    jobdir = '~/scratch0/' + str(sys.argv[2]) + '/job'
    pydir = '~/scratch0/' + str(sys.argv[2]) + '/python'
    print the_files

    os.system('mkdir ~/scratch0/' + str(sys.argv[2]))
    os.system('chmod +777 ~/scratch0/' + str(sys.argv[2]))
    os.system('mkdir ' + jobdir)
    os.system('chmod +777 ' + jobdir )
    os.system('mkdir ' + pydir)
    os.system('chmod +777 ' + pydir)
    if (int(sys.argv[5]) == -1):
        end = 10000000
    else:
        end = int(sys.argv[5])
        
    cont = 0     
    for i in range(len(the_files)):
        if (cont < end):
            if (i >= int(sys.argv[6])):
                cont = cont + 1
                jobname = jobdir + '/jobtemplate_' + str(sys.argv[3]) + str(i) + '.job'
                pyname = pydir + '/' + str(sys.argv[3]) + '_' + str(i) + '.py'
                joberr = jobname + 'cerr'
                jobout = jobname + 'cout'
                os.system('cp ../cfg/jobtemplate ' + jobname)
                os.system('cp ../cfg/' + str(sys.argv[3]) + ' ' + pyname)
                os.system('replace \"----input_file----\" \"' + the_files[i] + '\" -- '+ pyname)
                os.system('replace \"----output_file----\" \"'+str(sys.argv[4]) +'_'+str(i)+'.root' +'\" -- ' + pyname)
                os.system('replace \"----input_file----\" \"' +  str(sys.argv[3]) + '_' + str(i) + '.py' + '\" -- '+ jobname)
                os.system('replace \"----RUN-NUMBER----\" \"' + str(sys.argv[2]) + '\" -- '+ jobname)
                os.system('replace \"----output_file----\" \"'+str(sys.argv[4]) +'_'+str(i)+'.root' +'\" -- ' + jobname)
                os.system('chmod a+x ' + jobname)
                os.system('bsub -q cmscaf -e ' + joberr + ' -o ' + jobout + ' ' + jobname)
                

    print 'DONE!!!!!'
            


