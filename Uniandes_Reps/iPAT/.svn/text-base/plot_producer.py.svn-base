#! /usr/bin/env python
from Tkinter import *
import commands
import sys, os, string, fileinput
from sys import argv
from ROOT import *

def findArea(name):
    cmd = "pwd"
    homedir = [item[:-1] for item in os.popen(cmd)]
    area = 0
    f=open(str(homedir[0])+'/area_noise.txt', 'r')
    for line in f:
        coord = line.rstrip().split(" ")
        if str(coord[0]) == str(name):
            area = float(coord[3])
    f.close()
    return area

if __name__ == '__main__':

    RootFile=TFile.Open(str(sys.argv[1]))
    wheel = sys.argv[2]
    item = sys.argv[3]
    RootOut=TFile.Open(str(sys.argv[1]) + '_' + str(item) + '.root',"RECREATE")
    sectors = ['S04','S05','S06','S07','S08','S09','S10','S11','S12','S01','S02','S03']
    roll = ['Forward','Backward','Middle']
    stdis = TH1F('stripnoisedis','stripnoisedis',100000,0,1000)
    for cosa in sectors:
        for ding in roll:
            histname = str(wheel) + '_' + str(item) + '_' + str(cosa) + '_' + str(ding)
            histo = RootFile.FindObjectAny(histname)
            histotime = RootFile.FindObjectAny('Timeperbin')
            if(histo):
                ybins = histo.GetYaxis().GetNbins()
                histmed = TH1F(histname + '_media',histname + '_media',ybins,0,ybins)
                xbins = histo.GetXaxis().GetNbins()
                areastrip = 0
                for i in range(ybins):
                    hist1 = TH1F(histname + '_proy'+str(i),histname + '_proy',100000,0,9000000)
                    binname = histname + '_' + str(i)  
                    proy = histo.ProjectionX(binname,i+1,i+1)
                    for j in range(xbins):
                        if histotime.GetBinContent(j+1) != 0 :
                            hist1.Fill(proy.GetBinContent(j+1)*1000000000/175/(histotime.GetBinContent(j+1)))
                    if(areastrip == 0):                       
                        areastrip = findArea(histname)
                    if(areastrip != 0):
                        stdis.Fill(hist1.GetMean()/areastrip)
                    histmed.SetBinContent(i+1,hist1.GetMean())
                    histmed.SetBinError(i+1,hist1.GetMeanError())
                if(RootOut.cd()):
                    histmed.Write()

                    del histmed    
            del histo
    if(RootOut.cd()):
        stdis.Write()
    RootOut.Close()
