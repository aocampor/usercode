#! /usr/bin/env python
from Tkinter import *
import commands
import sys, os, string, fileinput
from sys import argv
from ROOT import *

if __name__ == '__main__':  

    #print 'ahi vamos'
    run = sys.argv[1]
    ch1 = TCanvas("Resume","Resumen",1397,299,700,502)
    histname = 'OrbitTimelhccond'
    RootFile1=TFile.Open(str(sys.argv[1])+'_noise_cosmic.root')
    histo1 = RootFile1.FindObjectAny(histname)
    histo1.SetLineColor(1)
    histo1.GetXaxis().SetRangeUser(0,20000)
    histo1.GetYaxis().SetRangeUser(0,90)
    histo1.SetTitle('Run ' + str(run) + ' Comparision between RPC L1 Trigger Emulators for Cosmics, pp collisions and TTU')
    histo1.GetYaxis().SetTitle('Trigger/1000Events')
    histo1.GetXaxis().SetTitle('EventsX10^{3}')
    histo1.Draw()
#    RootFile1.Close()
    RootFile2=TFile.Open(str(sys.argv[1])+'_noise_colli.root')
    histo2 = RootFile2.FindObjectAny(histname)
    histo2.SetLineColor(2)
    histo2.Draw('SAMES')
 #   RootFile2.Close()
    RootFile3=TFile.Open(str(sys.argv[1])+'_ttu.root')
    histo3 = RootFile3.FindObjectAny(histname)
    histo3.SetLineColor(4)
    histo3.Draw('SAMES')
  #  RootFile3.Close()
    ch1.SaveAs(str(run)+'_resumen.C')


