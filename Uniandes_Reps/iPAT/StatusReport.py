#! /usr/bin/env python
import os
import sys
import time
#from sys import argv
from QualityPerformance import Diagnostic
from QualityPerformanceDisk import DiagnosticDisk
import ROOT

class StatusReport(object):

    def __init__(self,root_file_name,ds,run,value1,value2,value3,value4,value5,value6,value7,value8,value9,value10):
        self.RootFileName = root_file_name
        self.values = [ds,run,value1,value2,value3,value4,value5,value6,value7,value8,value9,value10]

        print "Status report processing......Please wait!"
        
        name = root_file_name.rstrip().split("/")
        self.diagn = Diagnostic(self.RootFileName)
        self.diagndisk = DiagnosticDisk(self.RootFileName)

        numsta = self.diagn.getStatistics('Statistics')

        cmd = "pwd"
        homedir = [item[:-1] for item in os.popen(cmd)]
        f=open(str(homedir[0])+'/wheel_coord.txt', 'r')
        f1=open(str(homedir[0])+'/disk_coord.txt', 'r')

        fout=open("StatusReport.txt",'w')

        listWheel = ['W-2','W-1','W+0','W+1','W+2']
        listDisk = ['RE-3','RE-2','RE-1','RE+1','RE+2','RE+3']

        print self.values[0],self.values[1]

        fout.writelines("Dataset: "+self.values[0]+"\n")
        fout.writelines("Run number: "+self.values[1]+"\n")
        fout.writelines("Number of events: "+str(numsta)+"\n")

        for line in f:
            coord = line.rstrip().split("  ")
            print coord[0]
            for el in listWheel:
                histoname_bx = 'BXN_'+el+'_' + coord[0]
                histoname_cls = 'ClusterSize_'+el+'_'+coord[0]
                histoname_occ = 'Occupancy_'+el+'_'+coord[0]
                histoname_Eff = 'LocalEfficiencyFromSegments_'+el+'_' + coord[0]

                bx_for = self.diagn.getMeanValue(histoname_bx)[0]
                cls_for = self.diagn.getMeanValue(histoname_cls)[0]
                eff_for = self.diagn.getMedia(histoname_Eff)[0]
                mask_for = self.diagn.getMaskedStrip(histoname_occ)[0]
                noise_for = self.diagn.getNoise(histoname_bx)[0]

                bx_back = self.diagn.getMeanValue(histoname_bx)[1]
                cls_back = self.diagn.getMeanValue(histoname_cls)[1]
                eff_back = self.diagn.getMedia(histoname_Eff)[1]
                mask_back = self.diagn.getMaskedStrip(histoname_occ)[1]
                noise_back = self.diagn.getNoise(histoname_bx)[1]

                if len(self.diagn.getMeanValue(histoname_bx)) == 3:

                    bx_middle = self.diagn.getMeanValue(histoname_bx)[2]
                    cls_middle = self.diagn.getMeanValue(histoname_cls)[2]
                    eff_middle = self.diagn.getMedia(histoname_Eff)[2]
                    mask_middle = self.diagn.getMaskedStrip(histoname_occ)[2]
                    noise_middle = self.diagn.getNoise(histoname_bx)[2]

                if float(self.values[2])<= float(bx_for) <= float(self.values[3]) and float(self.values[4]) <= float(cls_for) <= float(self.values[5]) and float(self.values[6]) <= float(eff_for) <= float(self.values[7]) and float(self.values[8]) <= float(mask_for) <= float(self.values[9]) and ( float(self.values[10]) <= float(noise_for) <= float(self.values[11]) or float(noise_for) == float(-100)):

                    fout.writelines("Wheel: "+el+"   "+"Ch: "+coord[0]+"   "+"Bx Forw: "+("%.2f" % (bx_for))+"   "+"Cls Forw :"+("%.2f" % (cls_for))+"   "+"Eff Forw: "+("%.2f" % (eff_for))+"   "+"Mask Forw: "+("%.2f" % (mask_for))+"   "+"Noise Forw: "+("%.2f" % (noise_for))+"\n")

                if float(self.values[2]) <= float(bx_back) <= float(self.values[3]) and float(self.values[4]) <= float(cls_back) <= float(self.values[5]) and float(self.values[6]) <= float(eff_back) <= float(self.values[7]) and float(self.values[8]) <= float(mask_back) <= float(self.values[9]) and (float(self.values[10]) <= float(noise_back) <= float(self.values[11]) or float(noise_back) == float(-100) ):

                    fout.writelines("Wheel: "+el+"   "+"Ch: "+coord[0]+"   "+"Bx Back: "+("%.2f" % (bx_back))+"   "+"Cls Back :"+("%.2f" % (cls_back))+"   "+"Eff Back: "+("%.2f" % (eff_back))+"   "+"Mask Back: "+("%.2f" % (mask_back))+"   "+"Noise Back: "+("%.2f" % (noise_back))+"\n")


                if len(self.diagn.getMeanValue(histoname_bx)) == 3:
                    if float(self.values[2]) <= float(bx_middle) <= float(self.values[3]) and float(self.values[4]) <= float(cls_middle) <= float(self.values[5]) and float(self.values[6]) <= float(eff_middle) <= float(self.values[7]) and float(self.values[8]) <= float(mask_middle) <= float(self.values[9]) and ( float(self.values[10]) <= float(noise_middle) <= float(self.values[11]) or float(noise_middle) == float(-100) ) :
                        fout.writelines("Wheel: "+el+"   "+"Ch: "+coord[0]+"   "+"Bx Middle: "+("%.2f" % (bx_middle))+"   "+"Cls Middle :"+("%.2f" % (cls_middle))+"   "+"Eff Middle: "+("%.2f" % (eff_middle))+"   "+"Mask Middle: "+("%.2f" % (mask_middle))+"   "+"Noise Middle: "+("%.2f" % (noise_middle))+"\n")

                    
        for line in f1:
            coord = line.rstrip().split("  ")
            print coord[0]            
            for el in listDisk:
                histoname_bx = 'BXN_'+el+'_' + coord[0]
                histoname_cls = 'ClusterSize_'+el+'_'+coord[0]
                histoname_occ = 'Occupancy_'+el+'_'+coord[0]
                histoname_Eff = 'LocalEfficiencyFromSegments_'+el+'_' + coord[0]
                
                bx_1 = self.diagndisk.getMeanValue(histoname_bx)[0]
                cls_1 = self.diagndisk.getMeanValue(histoname_cls)[0]
                eff_1 = self.diagndisk.getMedia(histoname_Eff)[0]
                mask_1 = self.diagndisk.getMaskedStrip(histoname_occ)[0]
                noise_1 = self.diagndisk.getNoise(histoname_bx)[0]
                
                bx_2 = self.diagndisk.getMeanValue(histoname_bx)[1]
                cls_2 = self.diagndisk.getMeanValue(histoname_cls)[1]
                eff_2 = self.diagndisk.getMedia(histoname_Eff)[1]
                mask_2 = self.diagndisk.getMaskedStrip(histoname_occ)[1]
                noise_2 = self.diagndisk.getNoise(histoname_bx)[1]
                
                if len(self.diagndisk.getMeanValue(histoname_bx)) == 3:
                    
                    bx_3 = self.diagndisk.getMeanValue(histoname_bx)[2]
                    cls_3 = self.diagndisk.getMeanValue(histoname_cls)[2]
                    eff_3 = self.diagndisk.getMedia(histoname_Eff)[2]
                    mask_3 = self.diagndisk.getMaskedStrip(histoname_occ)[2]
                    noise_3 = self.diagndisk.getNoise(histoname_bx)[2]

                if float(self.values[2]) <= float(bx_1) <= float(self.values[3]) and float(self.values[4]) <= float(cls_1) <= float(self.values[5]) and float(self.values[6]) <= float(eff_1) <= float(self.values[7]) and float(self.values[8]) <= float(mask_1) <= float(self.values[9]) and (float(self.values[10]) <= float(noise_1) <= float(self.values[11]) or float(noise_1) == float(-100) ):
                    fout.writelines("Disk: "+el+"   "+"Ch: "+coord[0]+"   "+"Bx 1: "+("%.2f" % (bx_1))+"   "+"Cls 1 :"+("%.2f" % (cls_1))+"   "+"Eff 1: "+("%.2f" % (eff_1))+"   "+"Mask 1: "+("%.2f" % (mask_1))+"   "+"Noise 1: "+("%.2f" % (noise_1))+"\n")

                if float(self.values[2]) <= float(bx_2) <= float(self.values[3]) and float(self.values[4]) <= float(cls_2) <= float(self.values[5]) and float(self.values[6]) <= float(eff_2) <= float(self.values[7]) and float(self.values[8]) <= float(mask_2) <= float(self.values[9]) and ( float(self.values[10]) <= float(noise_2) <= float(self.values[11]) or float(noise_2) == float(-100) ): 
                    fout.writelines("Disk: "+el+"   "+"Ch: "+coord[0]+"   "+"Bx 2: "+("%.2f" % (bx_2))+"   "+"Cls 2 :"+("%.2f" % (cls_2))+"   "+"Eff 2: "+("%.2f" % (eff_2))+"   "+"Mask 2: "+("%.2f" % (mask_2))+"   "+"Noise 2: "+("%.2f" % (noise_2))+"\n")

                if len(self.diagndisk.getMeanValue(histoname_bx)) == 3:

                    if float(self.values[2]) <= float(bx_3) <= float(self.values[3]) and float(self.values[4]) <= float(cls_3) <= float(self.values[5]) and float(self.values[6]) <= float(eff_3) <= float(self.values[7]) and float(self.values[8]) <= float(mask_3) <= float(self.values[9]) and (float(self.values[10])<= float(noise_3) <= float(self.values[11]) or float(noise_3) == float(-100)) : 
                        fout.writelines("Disk: "+el+"   "+"Ch: "+coord[0]+"   "+"Bx 3: "+("%.2f" % (bx_3))+"   "+"Cls 3 :"+("%.2f" % (cls_3))+"   "+"Eff 3: "+("%.2f" % (eff_3))+"   "+"Mask 3: "+("%.2f" % (mask_3))+"   "+"Noise 3: "+("%.2f" % (noise_3))+"\n")

        fout.close()
        print "Done!"



if __name__ == '__main__': StatusReport(sys.argv[1],sys.argv[2],sys.argv[3],sys.argv[4],sys.argv[5],sys.argv[6],sys.argv[7],sys.argv[8],sys.argv[9],sys.argv[10],sys.argv[11],sys.argv[12],sys.argv[13])
