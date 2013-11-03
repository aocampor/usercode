#! /usr/bin/env python
from Tkinter import *
import commands
import sys, os, string, fileinput
from sys import argv
from ROOT import *

if __name__ == '__main__':

    RootFile=TFile.Open(str(sys.argv[1]))#"97003_noise_v4.root")
    RootOut=TFile.Open(str(sys.argv[1]) + '_davide.root',"RECREATE")

    wheels = ['W-2','W-1','W+0','W+1','W+2']
#    wheel = sys.argv[2]
    whe = -2
#    c1 = TCanvas('c1','c1',1)
    histo = TH1F('distribution','distribution',100,0,1)
    for item in wheels:
        title1 = str(item) + '_Far_Side97210.root_out1.root'
        title2 = str(item) + '_Near_Side97210.root_out1.root'
#        print str(title1)
        plot1 = RootFile.FindObjectAny(title1)
        plot2 = RootFile.FindObjectAny(title2)
        nbin1 = plot1.GetXaxis().GetNbins()
        nbin2 = plot2.GetXaxis().GetNbins()
 #       print 'bin1: ' + str(nbin1) + 'bin2: ' + str(nbin2)
        for i in range(nbin1):
            mean1 = plot1.GetBinContent(i + 1)
            if(mean1 != 0):
                histo.Fill(mean1/30000)
        for i in range(nbin2):
            mean2 = plot2.GetBinContent(i+1)
            if(mean2 != 0):
                histo.Fill(mean2/30000)
    histo.Write()
    #c1.SaveAs('davide.C')
    
