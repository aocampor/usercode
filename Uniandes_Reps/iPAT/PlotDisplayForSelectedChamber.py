#! /usr/bin/env python
import commands
import sys, os, string, fileinput
from Tkinter import *
import ROOT
from ROOT import TCanvas,TH1F,gROOT,TFile,gDirectory,gStyle

class DisplayPlots(Frame):
    def __init__(self,root_file_name,Wheel,parent=None):
        ROOT.gROOT.SetBatch(ROOT.kFALSE)
        runFile = root_file_name.split('/')

        w = Wheel[1]+Wheel[2]

        if int(w) >= 0: 
            RootFileNoiseName = '/'+runFile[1]+'/'+runFile[2]+'/'+runFile[3]+'/'+runFile[3]+'_0'+str(int(w))+'.root'
        else:
            RootFileNoiseName = '/'+runFile[1]+'/'+runFile[2]+'/'+runFile[3]+'/'+runFile[3]+'_0m'+str(abs(int(w)))+'.root'

        self.RootFileNoise=TFile.Open(RootFileNoiseName)
        
        self.RootFile=TFile.Open(root_file_name)

        Frame.__init__(self, parent)
        self.pack()
        self.canvas = Canvas(self,width = 300, height = 200, bg = 'darkgreen')
        self.canvas.pack(expand = YES, fill = BOTH)

    def plotHisto(self,histoname):
        inputname = histoname.rstrip().split("_")

        histo_prefix = ['BXN_','ClusterSize_','Occupancy_']
        
        histo_back = histoname + '_Backward'
        histo_for = histoname + '_Forward'
        rolls_in_chamber = [histo_for,histo_back]
        listCanvas = [TCanvas(histo_for,histo_for,200,10,700,500),
                      TCanvas(histo_back,histo_back,200,10,700,500)]

        if (cmp(inputname[0],'W+2') == 0 or cmp(inputname[0],'W-2') == 0) and cmp(inputname[1],'RB2out') == 0:
            histo_middle = histoname + '_Middle'
            rolls_in_chamber.append(histo_middle)
            listCanvas.append(TCanvas(histo_middle,histo_middle,200,10,700,500))
        elif (cmp(inputname[0],'W-1')==0 or cmp(inputname[0],'W+0')==0 or cmp(inputname[0],'W+1')==0) and cmp(inputname[1],'RB2in')==0:
            histo_middle = histoname + '_Middle'
            rolls_in_chamber.append(histo_middle)
            listCanvas.append(TCanvas(histo_middle,histo_middle,200,10,700,500))

        j = 0    
        for roll in rolls_in_chamber:
            listCanvas[j].Divide(3,2)
            i = 1
            self.RootFile.cd()
            for h in histo_prefix:
                try:
                    histo = gDirectory.FindObjectAny(h+roll)
                    listCanvas[j].cd(i)
                    histo.Draw()
                    i += 1
                except AttributeError:
                    pass


            try:
                listCanvas[j].cd(4)
                histo1 = gDirectory.FindObjectAny('LocalEfficiencyFromSegments_'+roll)
                if not histo1:
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
                histo = gDirectory.FindObjectAny('RPCResidualsFromDT_'+roll)
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

