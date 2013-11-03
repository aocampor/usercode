#! /usr/bin/env python
import commands, time
import sys, os, string, fileinput
from ROOT import *


#
# main
#

if __name__ == "__main__":

    ds = str(sys.argv[1]).replace('/','')  
     
    path = '/castor/cern.ch/cms/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[2]) + '/root'
    path1 = '/castor/cern.ch/cms/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[2]) + '/noise'
    path2 = '/castor/cern.ch/cms/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[2]) + '/gif'
    
    cmd0 = 'whoami'
    user = [item[:-1] for item in os.popen(cmd0)]
    tmppath = '/tmp/' + user[0] + '/' + str(sys.argv[2]) + '/'

    ver1 = [item[:-1] for item in os.popen('rfdir ' + path + '/Merge_DQM.root')]
    ver1_2 = [item[:-1] for item in os.popen('rfdir ' + path + '/Merge_DQM_SRPC.root')]
    if (ver1 == [] and ver1_2 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path + ' | grep " DQM_"')]
        if(check != []):
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' DQM_' + ' root')

    ver2 = [item[:-1] for item in os.popen('rfdir ' + path + '/Merge_SRPC.root')]
    if (ver2 == [] and ver1_2 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path + ' | grep " SRPC_"')]
        if(check != []):        
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' SRPC_' + ' root')

    ver2bis = [item[:-1] for item in os.popen('rfdir ' + path + '/Merge_GRPC.root')]
    if (ver2bis == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path + ' | grep " GRPC_"')]
        if(check != []):
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' GRPC_' + ' root')

    ver3 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Noise.root')]
    if (ver3 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Noise_"')]
        if(check != []):        
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Noise_ noise ')

    ver4 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_00.root')]
    if (ver4 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_00_"')]
        if(check != []):        
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_00_ noise ')

    ver5 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_01.root')]
    if (ver5 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_01_"')]
        if(check != []):        
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_01_ noise ')        

    ver6 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Trig.root')]
    if (ver6 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Trig_"')]
        if(check != []):
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Trig_ noise ' )
        
    ver7 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_02.root')]
    if (ver7 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_02_"')]
        if(check != []):        
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_02_ noise ')

    ver8 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_0m1.root')]
    if (ver8 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_0m1_"')]
        if(check != []):        
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_0m1_ noise ')

    ver9 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_0m2.root')]
    if (ver9 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_0m2_"')]
        if(check != []):        
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_0m2_ noise ')

    ver10 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_11.root')]
    if (ver10 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_11_"')]
        if(check != []):        
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_11_ noise ')

    ver11 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_12.root')]
    if (ver11 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_12_"')]
        if(check != []):        
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_12_ noise ')

    ver12 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_13.root')]
    if (ver12 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_13_"')]
        if(check != []):        
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_13_ noise ')
        
    ver13 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_m11.root')]
    if (ver13 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_m11_"')]
        if(check != []):        
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_m11_ noise ')

    ver14 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_m12.root')]
    if (ver14 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_m12_"')]
        if(check != []):        
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_m12_ noise ')        

    ver15 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_m13.root')]
    if (ver15 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_m13_"')]
        if(check != []):        
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_m13_ noise ')

    ver16 = [item[:-1] for item in os.popen('rfdir ' + path + '/Merge_Trigger_eff.root ' )]
    if (ver16 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path + ' | grep " Trigger_eff_"')]
        if(check != []):        
            os.system('./MergeSeveral.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Trigger_eff_ root ')        
        

    jobs =  [item[:-1] for item in os.popen('bjobs -w | grep /' + str(sys.argv[2]) + '/ | grep Merge ' )]
    time.sleep(60)
    print 'Waiting for jobs to been submitted'
    while (jobs != []):
        print 'jobs running!!!'
        jobs =  [item[:-1] for item in os.popen('bjobs -w | grep /' + str(sys.argv[2]) + '/ | grep Merge ' )]
        time.sleep(60)

    ver1 = [item[:-1] for item in os.popen('rfdir ' + path + '/Merge_DQM.root')]
    ver1_2 = [item[:-1] for item in os.popen('rfdir ' + path + '/Merge_DQM_SRPC.root')]
    if (ver1 == [] and ver1_2 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path + ' | grep " DQM_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' DQM' + ' root')

    ver2 = [item[:-1] for item in os.popen('rfdir ' + path + '/Merge_SRPC.root')]
    if (ver2 == [] and ver1_2 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path + ' | grep " SRPC_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' SRPC' + ' root')

    ver2bis = [item[:-1] for item in os.popen('rfdir ' + path + '/Merge_GRPC.root')]
    if (ver2bis == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path + ' | grep " GRPC_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' GRPC' + ' root')

    ver3 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Noise.root')]
    if (ver3 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Noise_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Noise noise ')

    ver4 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_00.root')]
    if (ver4 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_00_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_00 noise ')

    ver5 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_01.root')]
    if (ver5 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_01_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_01 noise ')        

    ver6 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Trig.root')]
    if (ver6 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Trig_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Trig noise ' )
        
    ver7 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_02.root')]
    if (ver7 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_02_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_02 noise ')

    ver8 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_0m1.root')]
    if (ver8 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_0m1_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_0m1 noise ')

    ver9 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_0m2.root')]
    if (ver9 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_0m2_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_0m2 noise ')

    ver10 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_11.root')]
    if (ver10 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_11_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_11 noise ')

    ver11 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_12.root')]
    if (ver11 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_12_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_12 noise ')

    ver12 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_13.root')]
    if (ver12 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_13_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_13 noise ')
        
    ver13 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_m11.root')]
    if (ver13 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_m11_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_m11 noise ')

    ver14 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_m12.root')]
    if (ver14 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_m12_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_m12 noise ')        

    ver15 = [item[:-1] for item in os.popen('rfdir ' + path1 + '/Merge_Strips_m13.root')]
    if (ver15 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep " Strips_m13_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Strips_m13 noise ')

    ver16 = [item[:-1] for item in os.popen('rfdir ' + path + '/Merge_Trigger_eff.root ' )]
    if (ver16 == []):
        check = [item[:-1] for item in os.popen('rfdir ' + path + ' | grep " Trigger_eff_'+str(sys.argv[2])+'_"')]
        if(check != []):        
            os.system('./MergeSeveral_2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) + ' Trigger_eff root ')        
        
    jobs =  [item[:-1] for item in os.popen('bjobs -w | grep /' + str(sys.argv[2]) + '/ | grep Merge ' )]
    time.sleep(60)
#    print 'Waiting for jobs to been submitted'
    while (jobs != []):
        print 'jobs running!!!'
        jobs =  [item[:-1] for item in os.popen('bjobs -w | grep /' + str(sys.argv[2]) + '/ | grep Merge ' )]
        time.sleep(60)
        
    noise_files = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep Merge_Strips_ | wc | awk \'{print $1}\'')]
    noise_files_1 = [item[:-1] for item in os.popen('rfdir ' + path1 + ' | grep Merge_Noise.root ')]
    if ( int(noise_files[0]) == 11 or noise_files_1 != [] ):
        os.system('./FinalNoiseMerge.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2]) )

    jobs =  [item[:-1] for item in os.popen('bjobs -w | grep /' + str(sys.argv[2]) + '/ | grep Merge ' )]
    time.sleep(60)
#    print 'Waiting for jobs to been submitted'
    while (jobs != []):
        print 'jobs running!!!'
        jobs =  [item[:-1] for item in os.popen('bjobs -w | grep /' + str(sys.argv[2]) + '/ | grep Merge ' )]
        time.sleep(60)
        
    plots = [item[:-1] for item in os.popen('rfdir ' + path2 + ' | grep gif')]
    medsg = [item[:-1] for item in os.popen('rfdir ' + path + ' | grep Merge_tot_new.root')]
    if (plots == [] or medsg == []):
        os.system('./FinalMerge_v2.py ' + str(sys.argv[1]) + ' ' + str(sys.argv[2])  )

    print 'End Of Merge For a Given Run Number!!!!!'
            


