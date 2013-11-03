#! /usr/bin/env python
from Tkinter import *
import commands
import sys, os, string, fileinput
from sys import argv
from ROOT import *

def findArea(name):
    cmd = "pwd"
    homedir = [item[:-1] for item in os.popen(cmd)]
    f=open(str(homedir[0])+'/area_noise.txt', 'r')
    area = '0'
    for line in f:
        coord = line.rstrip().split(" ")
        if coord[0] == str(name):
            area=str(coord[2])
    f.close()
    return area

if __name__ == '__main__':

    RootFile=TFile.Open(str(sys.argv[1]))
    RootOut=TFile.Open(str(sys.argv[1]) + '_davide.root',"RECREATE")
    run = str(sys.argv[2])

    wheels = ['RE-3','RE-2','RE-1','W-2','W-1','W+0','W+1','W+2','RE+1','RE+2','RE+3']
    whe = ['m13','m12','m11','0m2','0m1','00','01','02','11','12','13']
    histo = TH1F('distribution','distribution',100000,0,1000)
    cont = 0
    for item in wheels:
        title1 = str(item) + '_Far_Side'
        title2 = str(item) + '_Near_Side'
        plot1 = RootFile.FindObjectAny(title1)
        plot2 = RootFile.FindObjectAny(title2)
        if (plot1 and plot2):
         nbin1 = plot1.GetXaxis().GetNbins()
         nbin2 = plot2.GetXaxis().GetNbins()
         for i in range(nbin1):
            mean1 = plot1.GetBinContent(i + 1)
            area1 = findArea(plot1.GetXaxis().GetBinLabel(i+1))
            if(area1 != '0'):
                histo.Fill(mean1/float(area1))
         for i in range(nbin2):
            mean2 = plot2.GetBinContent(i+1)
            area2 = findArea(plot2.GetXaxis().GetBinLabel(i+1))
            if(area2 != '0'):
                histo.Fill(mean2/float(area2))

        cont = cont + 1        
    histo.Write()
    
