#! /usr/bin/env python
import commands
import sys, os, string, fileinput
from Tkinter import *
import ROOT
from ROOT import TCanvas,TH1F,gROOT,TFile,gDirectory,gStyle

class DisplayPlots(Frame):
    def __init__(self,root_file_name,Wheel,parent=None):
        ROOT.gROOT.SetBatch(ROOT.kFALSE)
        print root_file_name
        runFile = root_file_name.split('/')
        w = Wheel[2]+Wheel[3]

        print w
        if int(w) >= 0: 
            RootFileNoiseName = '/'+runFile[1]+'/'+runFile[2]+'/'+runFile[3]+'/'+runFile[3]+'_1'+str(w)+'.root'
        else:
            RootFileNoiseName = '/'+runFile[1]+'/'+runFile[2]+'/'+runFile[3]+'/'+runFile[3]+'_m1'+str(abs(int(w)))+'.root'


        self.RootFileNoise=TFile.Open(RootFileNoiseName)

        self.RootFile=TFile.Open(root_file_name)
        Frame.__init__(self, parent)
        self.pack()
        self.canvas = Canvas(self,width = 300, height = 200, bg = 'darkgreen')
        self.canvas.pack(expand = YES, fill = BOTH)

    def plotHisto(self,histoname1):
        inputname = histoname1.rstrip().split("_")
        histoname =  inputname[0]+'_'+inputname[1]+'_'+inputname[3]
        print inputname, histoname
        histo_prefix = ['BXN_','ClusterSize_','Occupancy_']

        histo_A = histoname + '_A'
        histo_B = histoname + '_B'
        histo_C = histoname + '_C'
        rolls_in_chamber = [histo_A,histo_B,histo_C]
        
        listCanvas = [TCanvas(histo_A,histo_A,200,10,700,500),
                      TCanvas(histo_B,histo_B,200,10,700,500),
                      TCanvas(histo_C,histo_C,200,10,700,500)]

        j = 0    
        for roll in rolls_in_chamber:
            listCanvas[j].Divide(3,2)
            i = 1
            self.RootFile.cd()
            for h in histo_prefix:
                try:
                    histo = gDirectory.FindObjectAny(h+roll)
                    print h+roll
                    listCanvas[j].cd(i)
                    histo.Draw()
                    i += 1
                except AttributeError:
                    pass

            try:    
                listCanvas[j].cd(4)
                histo1 = gDirectory.FindObjectAny('LocalEfficiencyFromSegments_'+roll)
                if not histo1:
                    print 'Profile_'+roll
                    histo1 = gDirectory.FindObjectAny('Profile_'+roll)
                
                histo1.SetLineColor(1)
                histo1.SetMarkerColor(1)
                histo1.Draw()
                
                histo = gDirectory.FindObjectAny('LocalEfficiencyFromTrack_'+roll)
                histo.SetLineColor(4)
                histo.SetMarkerColor(4)
                histo.Draw("same")

            except AttributeError:
                pass

            try:    
                listCanvas[j].cd(5)
                histo = gDirectory.FindObjectAny('RPCResidualsFromCSC_'+roll)
                histo.SetLineColor(1)
                histo.SetMarkerColor(1)
                histo.Draw()
                histo1 = gDirectory.FindObjectAny('Residualsmin_'+roll)
                histo1.SetLineColor(4)
                histo1.SetMarkerColor(4)
                histo1.Draw("same")
            except AttributeError:
                pass

            try:
                self.RootFileNoise.cd()
                listCanvas[j].cd(6)
                gStyle.SetPalette(1)
                histo = gDirectory.FindObjectAny(roll)
                histo.Draw()
            except AttributeError:
                pass








            
            j += 1
            
        self.mainloop()

