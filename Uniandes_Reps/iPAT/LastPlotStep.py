#! /usr/bin/env python
import commands
import sys, os, string, fileinput
from ROOT import *

from GlobalPlotsProduction import GlobalPlotsProduction

#
# main
#

if __name__ == "__main__":

    ds = str(sys.argv[1]).replace('/','')  

        
    path = '/castor/cern.ch/cms/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[2]) + '/root'
    path_aux = '/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[2]) + '/root'
    path1 = '/castor/cern.ch/cms/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[2]) + '/noise'
    path1_aux = '/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[2]) + '/noise'
    path2 = '/castor/cern.ch/cms/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[2]) + '/gif'
    path2_aux = '/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[2]) + '/gif/'
    

    cmd0 = 'whoami'
    user = [item[:-1] for item in os.popen(cmd0)]
    tmppath = '/tmp/' + user[0] + '/' + str(sys.argv[2]) + '/'

    os.system("mkdir " + tmppath)

    wheels = ['W-2','W-1','W+0','W+1','W+2']
    os.system('cmsStageIn ' + path_aux + '/' + 'Merge_DQM_SRPC_GRPC.root .')
    trick = [item[:-1] for item in os.popen('rfdir ' + path1 + '/' + str(sys.argv[2]) + '_final.root')]
    if (trick != []):
        os.system('cmsStageIn ' + path1_aux + '/' + str(sys.argv[2]) + '_final.root .')    
        os.system('hadd Merge_1.root Merge_DQM_SRPC_GRPC.root ' + str(sys.argv[2]) + '_final.root ')
        os.system('mv Merge_1.root ' + tmppath )
    else:
        os.system('mv Merge_DQM_SRPC_GRPC.root ' + tmppath + '/Merge_1.root' )
        
    for w in wheels:
        os.system('./EfficiencyPlotProduction.py ' + tmppath + 'Merge_1.root ' + w + ' \n')
        os.system('mv prova.root ' + tmppath + w + '.root \n')

    disks = ['RE-3','RE-2','RE-1','RE+1','RE+2','RE+3']

    for w in disks:
        os.system('./EfficiencyPlotProductionDisk.py ' + tmppath + 'Merge_1.root ' + w + '\n')
        os.system('mv prova.root ' + tmppath + w + '.root \n')

    trick = [item[:-1] for item in os.popen('rfdir ' + path + '/Merge_Trigger_eff.root ')]
    if (trick != []):
        os.system('cmsStageIn ' + path_aux + '/' + 'Merge_Trigger_eff.root ' + tmppath)
        os.system('mv Merge_Trigger_eff.root ' + tmppath )
        os.system('hadd -f ' + tmppath + 'Merge_tot.root ' +  tmppath + 'Merge_1.root ' + tmppath +'W*.root ' + tmppath +'RE*.root '+  tmppath + 'Merge_Trigger_eff.root ')
    else:
        os.system('hadd -f ' + tmppath + 'Merge_tot.root ' +  tmppath + 'Merge_1.root ' + tmppath +'W*.root ' + tmppath +'RE*.root ')
    os.system('./GlobalPlotsProduction.py '+tmppath + 'Merge_tot.root '+str(sys.argv[2])+'  '+tmppath+ '\n')
    os.system('mv GlobalPlots.root ' + tmppath +'GlobalPlots.root \n')
    os.system('hadd -f ' + tmppath + 'Merge_tot_new.root ' +  tmppath + 'Merge_tot.root '+ tmppath +'GlobalPlots.root \n')
    os.system('cmsStageOut ' + tmppath + 'Merge_tot_new.root ' + path_aux + '/Merge_tot_new.root \n' )
    os.system('rfchmod +777 ' + path + '/Merge_tot_new.root \n' )

##------------------------------------------------------------------------------------------------------------------------------

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_p2_near.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_p2_near.gif ' + path2_aux )
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_p2_near.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_p2_Far.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_p2_Far.gif ' + path2_aux )
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_p2_Far.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_p1_near.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_p1_near.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_p1_near.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_p1_Far.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_p1_Far.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_p1_Far.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_m2_near.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_m2_near.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_m2_near.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_m2_Far.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_m2_Far.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_m2_Far.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_m1_near.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_m1_near.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_m1_near.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_m1_Far.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_m1_Far.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_m1_Far.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_0_near.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_0_near.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_0_near.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_0_Far.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_0_Far.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_0_Far.gif ' )

##---------------------------------------------------------------------------------------------------------------------------


    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_2_near_noise.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_2_near_noise.gif ' + path2_aux )
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_2_near_noise.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_2_far_noise.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_2_far_noise.gif ' + path2_aux )
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_2_far_noise.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_1_near_noise.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_1_near_noise.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_1_near_noise.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_1_far_noise.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_1_far_noise.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_1_far_noise.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_m2_near_noise.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_m2_near_noise.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_m2_near_noise.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_m2_far_noise.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_m2_far_noise.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_m2_far_noise.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_m1_near_noise.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_m1_near_noise.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_m1_near_noise.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_m1_far_noise.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_m1_far_noise.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_m1_far_noise.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_0_near_noise.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_0_near_noise.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_0_near_noise.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_wheel_0_far_noise.gif'):        
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_wheel_0_far_noise.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_wheel_0_far_noise.gif ' )

##---------------------------------------------------------------------------------------------------------------------------        

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hBarrel_bx.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hBarrel_bx.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hBarrel_bx.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_ClusterSize_for_Barrel.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_ClusterSize_for_Barrel.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_ClusterSize_for_Barrel.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hBarrel_masked.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hBarrel_masked.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hBarrel_masked.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hBarrel_eff.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hBarrel_eff.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hBarrel_eff.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hBarrel_eff_STA.gif"): ##
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hBarrel_eff_STA.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hBarrel_eff_STA.gif ' ) ##

##-------------------------------------------------------------------------------------------------------------------------------

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_m1_RE1.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_m1_RE1.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_m1_RE1.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_m1_RE2.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_m1_RE2.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_m1_RE2.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_m1_RE3.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_m1_RE3.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_m1_RE3.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_m2_RE1.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_m2_RE1.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_m2_RE1.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_m2_RE2.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_m2_RE2.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_m2_RE2.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_m2_RE3.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_m2_RE3.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_m2_RE3.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_m3_RE1.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_m3_RE1.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_m3_RE1.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_m3_RE2.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_m3_RE2.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_m1_RE2.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_m3_RE3.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_m3_RE3.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_m3_RE3.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_p1_RE1.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_p1_RE1.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_p1_RE1.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_p1_RE2.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_p1_RE2.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_p1_RE2.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_p1_RE3.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_p1_RE3.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_p1_RE3.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_p2_RE1.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_p2_RE1.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_p2_RE1.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_p2_RE2.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_p2_RE2.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_p2_RE2.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_p2_RE3.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_p2_RE3.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_p2_RE3.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_p3_RE1.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_p3_RE1.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_p3_RE1.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_p3_RE2.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_p3_RE2.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_p1_RE2.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+'_c_disk_p3_RE3.gif'):
        os.system('cmsStageOut run'+str(sys.argv[2])+'_c_disk_p3_RE3.gif ' + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_c_disk_p3_RE3.gif ' )

##-------------------------------------------------------------------------------------------------------------------------------

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hEndcap_bx.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hEndcap_bx.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hEndcap_bx.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_ClusterSize_for_Endcap_P.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_ClusterSize_for_Endcap_P.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_ClusterSize_for_Endcap_P.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_ClusterSize_for_Endcap_N.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_ClusterSize_for_Endcap_N.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_ClusterSize_for_Endcap_N.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hEndcap_masked.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hEndcap_masked.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hEndcap_masked.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hEndcap_eff.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hEndcap_eff.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hEndcap_eff.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hEndcap_eff_STA.gif"): ##
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hEndcap_eff_STA.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hEndcap_eff_STA.gif ' ) ##

##--------------------------------------------------------------------------------------------------------------------------------

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_BxDistribution_Wheel_m2.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_BxDistribution_Wheel_m2.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_BxDistribution_Wheel_m2.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_ClusterSize_Wheel_m2.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_ClusterSize_Wheel_m2.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_ClusterSize_Wheel_m2.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hWm2_masked.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hWm2_masked.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hWm2_masked.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hWm2_eff.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hWm2_eff.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hWm2_eff.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hWm2_eff_STA.gif"): ##
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hWm2_eff_STA.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hWm2_eff_STA.gif ' ) ##

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_BxDistribution_Wheel_m1.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_BxDistribution_Wheel_m1.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_BxDistribution_Wheel_m1.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_ClusterSize_Wheel_m1.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_ClusterSize_Wheel_m1.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_ClusterSize_Wheel_m1.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hWm1_masked.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hWm1_masked.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hWm1_masked.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hWm1_eff.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hWm1_eff.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hWm1_eff.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hWm1_eff_STA.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hWm1_eff_STA.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hWm1_eff_STA.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_BxDistribution_Wheel_0.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_BxDistribution_Wheel_0.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_BxDistribution_Wheel_0.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_ClusterSize_Wheel_0.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_ClusterSize_Wheel_0.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_ClusterSize_Wheel_0.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hW0_masked.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hW0_masked.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hW0_masked.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hW0_eff.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hW0_eff.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hW0_eff.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hW0_eff_STA.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hW0_eff_STA.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hW0_eff_STA.gif ' )
    
    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_BxDistribution_Wheel_p1.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_BxDistribution_Wheel_p1.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_BxDistribution_Wheel_p1.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_ClusterSize_Wheel_p1.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_ClusterSize_Wheel_p1.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_ClusterSize_Wheel_p1.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hWp1_masked.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hWp1_masked.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hWp1_masked.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hWp1_eff.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hWp1_eff.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hWp1_eff.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hWp1_eff_STA.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hWp1_eff_STA.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hWp1_eff_STA.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_BxDistribution_Wheel_p2.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_BxDistribution_Wheel_p2.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_BxDistribution_Wheel_p2.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_ClusterSize_Wheel_p2.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_ClusterSize_Wheel_p2.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_ClusterSize_Wheel_p2.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hWp2_masked.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hWp2_masked.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hWp2_masked.gif  ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hWp2_eff.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hWp2_eff.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hWp2_eff.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hWp2_eff_STA.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hWp2_eff_STA.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hWp2_eff_STA.gif ' )

##-------------------------------------------------------------------------------------------------------------

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_BxDistribution_Disk_m1.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_BxDistribution_Disk_m1.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_BxDistribution_Disk_m1.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_ClusterSize_Disk_m1.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_ClusterSize_Disk_m1.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_ClusterSize_Disk_m1.gif  ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDm1_masked.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDm1_masked.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDm1_masked.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDm1_eff.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDm1_eff.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDm1_eff.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDm1_eff_STA.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDm1_eff_STA.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDm1_eff_STA.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_BxDistribution_Disk_m2.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_BxDistribution_Disk_m2.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_BxDistribution_Disk_m2.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_ClusterSize_Disk_m2.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_ClusterSize_Disk_m2.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_ClusterSize_Disk_m2.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDm2_masked.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDm2_masked.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDm2_masked.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDm2_eff.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDm2_eff.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDm2_eff.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDm2_eff_STA.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDm2_eff_STA.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDm2_eff_STA.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_BxDistribution_Disk_m3.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_BxDistribution_Disk_p3.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_BxDistribution_Disk_p3.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_ClusterSize_Disk_m3.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_ClusterSize_Disk_p3.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_ClusterSize_Disk_p3.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDm3_masked.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDm3_masked.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDm3_masked.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDm3_eff.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDm3_eff.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDm3_eff.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDm3_eff_STA.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDm3_eff_STA.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDm3_eff_STA.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_BxDistribution_Disk_p1.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_BxDistribution_Disk_p1.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_BxDistribution_Disk_p1.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_ClusterSize_Disk_p1.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_ClusterSize_Disk_p1.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_ClusterSize_Disk_p1.gif  ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDp1_masked.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDp1_masked.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDp1_masked.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDp1_eff.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDp1_eff.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDp1_eff.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDp1_eff_STA.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDp1_eff_STA.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDp1_eff_STA.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_BxDistribution_Disk_p2.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_BxDistribution_Disk_p2.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_BxDistribution_Disk_p2.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_ClusterSize_Disk_p2.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_ClusterSize_Disk_p2.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_ClusterSize_Disk_p2.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDp2_masked.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDp2_masked.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDp2_masked.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDp2_eff.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDp2_eff.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDp2_eff.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDp2_eff_STA.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDp2_eff_STA.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDp2_eff_STA.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_BxDistribution_Disk_p3.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_BxDistribution_Disk_p3.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_BxDistribution_Disk_p3.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_ClusterSize_Disk_p3.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_ClusterSize_Disk_p3.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_ClusterSize_Disk_p3.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDp3_masked.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDp3_masked.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDp3_masked.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDp3_eff.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDp3_eff.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDp3_eff.gif ' )

    if os.path.exists(tmppath+"run"+str(sys.argv[2])+"_hDp3_eff_STA.gif"):
        os.system('cmsStageOut run'+str(sys.argv[2])+"_hDp3_eff_STA.gif " + path2_aux)
        os.system('rfchmod +777 ' + path2 + '/' + "run"+str(sys.argv[2])+'_hDp3_eff_STA.gif ' )

    print 'DONE!!!!!'
         


