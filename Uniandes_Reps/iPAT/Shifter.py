#! /usr/bin/env python
import commands, time
import sys, os, string, fileinput
from ROOT import *


def numfiles(dataset,runnum):
    total = [item[:-1] for item in os.popen('./aSearchCLI --dbsInst=cms_dbs_prod_global --limit=-1 --input \"find file where dataset like ' + dataset + ' and run = ' + runnum + '\" | grep -v root | awk \'{print $2}\'')]
    return total[1]


if __name__ == "__main__":

    ds = str(sys.argv[2]).replace('/','')
    njos = numfiles(str(sys.argv[2]),str(sys.argv[3]))

    path = '/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[3]) + '/root'
    path1 = '/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[3]) + '/noise'
    
    contdqm = 0
    contsrpc = 0
    contgrpc = 0
    contterpc = 0
    contnoi = 0
    conttrig = 0
    cont00 = 0
    cont01 = 0
    cont02 = 0
    cont0m1 = 0
    cont0m2 = 0
    cont11 = 0
    cont12 = 0
    cont13 = 0
    contm11 = 0
    contm12 = 0
    contm13 = 0
    
    while( contdqm != njos or contsrpc != njos or contgrpc !=0  or contterpc != njos or contnoi != njos or conttrig != njos or cont00 != njos or cont01 != njos or cont02 != njos or cont0m1 != njos or cont0m2 != njos or cont11 != njos or cont12 != njos or cont13 != njos or contm11 != njos or contm12 != njos or contm13 != njos ):
        
        jobs = [item[:-1] for item in os.popen('bjobs -w | grep -v Shifter_Job_' + str(sys.argv[3]) + '.job | grep /' + str(sys.argv[3]) + '/') ]
        os.system('rm ~/scratch0/'+str(sys.argv[3])+'/job/*cout')
        os.system('rm ~/scratch0/'+str(sys.argv[3])+'/job/*cerr')                
        while jobs != []:
#            print jobs
            print 'waiting!!'
            time.sleep(60)
            jobs = [item[:-1] for item in os.popen('bjobs -w | grep -v Shifter_Job_' + str(sys.argv[3]) + '.job | grep /' + str(sys.argv[3]) + '/') ]
#            quota = [item[:-1] for item in os.popen('fs listquota')]
 #           numquota = int(quota[1].split(' ')[30].split('%')[0])
  #          if(numquota > 94):

        contdqm = 0
        contsrpc = 0
        contgrpc = 0
        contterpc = 0
        contnoi = 0
        conttrig = 0
        cont00 = 0
        cont01 = 0
        cont02 = 0
        cont0m1 = 0
        cont0m2 = 0
        cont11 = 0
        cont12 = 0
        cont13 = 0
        contm11 = 0
        contm12 = 0
        contm13 = 0
    
        for x in range(int(njos)):
            print 'counting files: ' + str(x)
            dqm = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path + '/' + 'DQM_'+str(x)+'.root | awk \'{print $5}\'' )]
            if dqm != []:
              if dqm[0] > 500 :
                contdqm = contdqm + 1
            srpc = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path + '/' + 'SRPC_'+str(x)+'.root | awk \'{print $5}\'' )]
            if srpc != []:
              if srpc[0] > 500 :
                contsrpc = contsrpc + 1
            grpc = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path + '/' + 'GRPC_'+str(x)+'.root | awk \'{print $5}\'' )]
            if grpc != []:
              if grpc[0] > 500:
                contgrpc = contgrpc + 1            
            terpc = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path + '/' + 'Trigger_eff_'+str(x)+'.root | awk \'{print $5}\'' )]
            if terpc != []:
              if terpc[0] > 500:
                contterpc = contterpc + 1
            noi = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/' + 'Noise_'+str(x)+'.root | awk \'{print $5}\'' )]
            if noi != []:
              if noi[0] > 500:
                contnoi = contnoi + 1
            trig = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/' + 'Trig_'+str(x)+'.root | awk \'{print $5}\'' )]
            if trig != []:
              if trig[0] > 500:
                conttrig = conttrig + 1
            strip00 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/' + 'Strips_00_'+str(x)+'.root | awk \'{print $5}\'' )]
            if strip00 != []:
              if strip00[0] > 500:
#                print strip00[0]
                cont00 = cont00 + 1
            strip01 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/' + 'Strips_01_'+str(x)+'.root | awk \'{print $5}\'' )]
            if strip01 != []:
              if strip01[0] > 500:
                cont01 = cont01 + 1
            strip02 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/' + 'Strips_02_'+str(x)+'.root | awk \'{print $5}\'' )]
            if strip02 != []:
              if strip02[0] > 500:
                cont02 = cont02 + 1
            strip0m1 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/' + 'Strips_0m1_'+str(x)+'.root | awk \'{print $5}\'' )]
            if strip0m1 != []: 
              if strip0m1[0] > 500:
                cont0m1 = cont0m1 + 1
            strip0m2 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/' + 'Strips_0m2_'+str(x)+'.root | awk \'{print $5}\'' )]
            if strip0m2 != []:
              if strip0m2[0] > 500:
                cont0m2 = cont0m2 + 1
            strip11 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/' + 'Strips_11_'+str(x)+'.root | awk \'{print $5}\'' )]
            if strip11 != []:
              if strip11[0] > 500:
                cont11 = cont11 + 1
            strip12 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/' + 'Strips_12_'+str(x)+'.root | awk \'{print $5}\'' )]
            if strip12 != []:            
              if strip12[0] > 500:
                cont12 = cont12 + 1
            strip13 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/' + 'Strips_13_'+str(x)+'.root | awk \'{print $5}\'' )]
            if strip13 != []:            
              if strip13[0] > 500:
                cont13 = cont13 + 1
            stripm11 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/' + 'Strips_m11_'+str(x)+'.root | awk \'{print $5}\'' )]
            if stripm11 != []:
              if stripm11[0] > 500:
                contm11 = contm11 + 1
            stripm12 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/' + 'Strips_m12_'+str(x)+'.root | awk \'{print $5}\'' )]
            if stripm12 != []:            
              if stripm12[0] > 500:
                contm12 = contm12 + 1
            stripm13 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/' + 'Strips_m13_'+str(x)+'.root | awk \'{print $5}\'' )]
            if stripm13 != []:
              if stripm13[0] > 500:
                contm13 = contm13 + 1

        dqm1 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path + '/' + 'Merge_DQM.root | awk \'{print $5}\'' )]
        if( contdqm != njos and dqm1 == []):    
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 0 1 0 0 0 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            print 'limite ' + str(int(lim[0]))
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)
        else:
            contdqm = njos
        if( contsrpc != njos ):    
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)
        if( contgrpc != njos ):    
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)
        if( contterpc != njos ):
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)            
        if( contnoi != njos ):
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)            
        if( conttrig != njos ):
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)            
        if( cont02 != njos ):
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)
        if( cont01 != njos ):
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)
        if( cont00 != njos ):
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)
        if( cont0m1 != njos ):
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)
        if( cont0m2 != njos ):
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)
        if( cont11 != njos ):
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)
        if( cont12 != njos ):
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)
        if( cont13 != njos ):
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)
        if( contm11 != njos ):
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)
        if( contm12 != njos ):
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)
        if( contm13 != njos ):
            os.system('./filecounter.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 &')
            lim = [item[:-1] for item in os.popen('bjobs | wc | awk \'{print $1}\'')]
            if(lim != []):
                while(int(lim[0]) > 100):
                    time.sleep(60)                                

        time.sleep(60)

    contdqm = 0
    contsrpc = 0
    contgrpc = 0
    contterpc = 0
    contnoi = 0
    conttrig = 0
    cont00 = 0
    cont01 = 0
    cont02 = 0
    cont0m1 = 0
    cont0m2 = 0
    cont11 = 0
    cont12 = 0
    cont13 = 0
    contm11 = 0
    contm12 = 0
    contm13 = 0


    while (contdqm != 1 or contsrpc != 1 or contgrpc != 1 or contterpc != 1 or contnoi != 1 or conttrig != 1 or contstr00 != 1 or contstr01 != 1 or  contstr02 != 1 or contstr0m1 != 1 or contstr0m2 != 1 or contstr11 != 1 or contstr12 != 1 or contstr13 != 1 or contstrm11 != 1 or contstrm12 != 1 or contstrm13 != 1):
        contdqm = 0
        contsrpc = 0
        contgrpc = 0
        contterpc = 0
        contnoi = 0
        conttrig = 0
        cont00 = 0
        cont01 = 0
        cont02 = 0
        cont0m1 = 0
        cont0m2 = 0
        cont11 = 0
        cont12 = 0
        cont13 = 0
        contm11 = 0
        contm12 = 0
        contm13 = 0

        jobs = [item[:-1] for item in os.popen('bjobs -w | grep -v Shifter_Job_' + str(sys.argv[3]) + '.job | grep /' + str(sys.argv[3]) + '/ | grep Merge')]
    
        while jobs != []:
            print 'waiting!!'
            time.sleep(60)
            jobs = [item[:-1] for item in os.popen('bjobs -w | grep -v Shifter_Job_' + str(sys.argv[3]) + '.job | grep /' + str(sys.argv[3]) + '/ | grep Merge')]
            
        dqm1 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path + '/' + 'Merge_DQM.root | awk \'{print $5}\'' )]
        if dqm1 != []:
            if dqm1[0] > 500 :
                contdqm = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path + '/' + 'Merge_DQM.root')
        srpc1 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path + '/Merge_SRPC.root | awk \'{print $5}\'' )]
        if srpc1 != []:
            if srpc1[0] > 500 :
                contsrpc = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path + '/' + 'Merge_SRPC.root')
        grpc1 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path + '/Merge_GRPC.root | awk \'{print $5}\'' )]
        if grpc1 != []:
            if grpc1[0] > 500 :
                contgrpc = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path + '/' + 'Merge_GRPC.root')                
        terpc1 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path + '/Merge_Trigger_eff.root | awk \'{print $5}\'' )]
        if terpc1 != []:
            if terpc1[0] > 500 :
                contterpc = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path + '/' + 'Trigger_eff_tot.root')                
        noi1 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/Merge_Noise_tot.root | awk \'{print $5}\'' )]
        if noi1 != []:
            if noi1[0] > 500 :
                contnoi = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path1 + '/' + 'Merge_Noise_tot.root')                
        trig1 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/Merge_Trig_tot.root | awk \'{print $5}\'' )]
        if trig1 != []:
            if trig1[0] > 500 :
                conttrig = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path1 + '/' + 'Merge_Trig_tot.root')                
        str00 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/Merge_Strips_00.root | awk \'{print $5}\'' )]
        if str00 != []:
            if str00[0] > 500 :
                cont00 = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path1 + '/Merge_Strips_00.root')                
        str01 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/Merge_Strips_01.root | awk \'{print $5}\'' )]
        if str01 != []:
            if str01[0] > 500 :
                cont01 = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path1 + '/Merge_Strips_01.root')                
        str02 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/Merge_Strips_02.root | awk \'{print $5}\'' )]
        if str02 != []:
            if str02[0] > 500 :
                cont02 = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path1 + '/Merge_Strips_02.root')                                
        str0m1 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/Merge_Strips_0m1.root | awk \'{print $5}\'' )]
        if str0m1 != []:
            if str0m1[0] > 500 :
                cont0m1 = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path1 + '/Merge_Strips_0m1.root')                                
        str0m2 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/Merge_Strips_0m2.root | awk \'{print $5}\'' )]
        if str0m2 != []:
            if str0m2[0] > 500 :
                cont0m2 = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path1 + '/Merge_Strips_0m2.root')                                
        str11 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/Merge_Strips_11.root | awk \'{print $5}\'' )]
        if str11 != []:
            if str11[0] > 500 :
                cont11 = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path1 + '/Merge_Strips_11.root')                                
        str12 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/Merge_Strips_12.root | awk \'{print $5}\'' )]
        if str12 != []:
            if str12[0] > 500 :
                cont12 = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path1 + '/Merge_Strips_12.root')                                
        str13 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/Merge_Strips_13.root | awk \'{print $5}\'' )]
        if str13 != []:
            if str13[0] > 500 :
                cont13 = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path1 + '/Merge_Strips_13.root')                                
        strm11 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/Merge_Strips_m11.root | awk \'{print $5}\'' )]
        if strm11 != []:
            if strm11[0] > 500 :
                contm11 = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path1 + '/Merge_Strips_m11.root')                                
        strm12 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/Merge_Strips_m12.root | awk \'{print $5}\'' )]
        if strm12 != []:
            if strm12[0] > 500 :
                contm12 = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path1 + '/Merge_Strips_m12.root')                                
        strm13 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms' + path1 + '/Merge_Strips_m13.root | awk \'{print $5}\'' )]
        if strm13 != []:
            if strm13[0] > 500 :
                contm13 = 1
            else:
                os.system('rfrm /castor/cern.ch/cms' + path1 + '/Merge_Strips_m13.root')
                
        if( contdqm != 1 or contsrpc != 1 or contgrpc != 1 or contterpc != 1 or conttrig != 1 or contnoi != 1 or cont00 != 1 or cont01 != 1 or cont02 != 1 or cont0m1 != 1 or cont0m2 != 1 or cont11 != 1 or cont12 != 1 or cont13 != 1 or contm11 != 1 or contm12 != 1 or contm13 != 1 ):
            os.system('./MergeJobForAGivenRunNumber_new.py ' + str(sys.argv[2]) + ' ' + str(sys.argv[3]) + ' &')
            time.sleep(60)
            
    print 'Listo!'
    os.system('mail 0041767340812@sms.switch.ch < "run ' + str(sys.argv[3]) + ' is ready!"')
    

