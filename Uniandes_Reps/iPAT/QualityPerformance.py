#! /usr/bin/env python
import ROOT
from ROOT import TCanvas,TH1F,gROOT,TFile,gDirectory, TF1
from Tkinter import *
from math import *

class Diagnostic(object):

    def __init__(self,root_file_name):
        ROOT.gROOT.SetBatch(ROOT.kTRUE)
        path = root_file_name.rstrip().split("/")
        self.RootFile=TFile.Open(root_file_name)
        self.folder = gDirectory.FindObjectAny("RPC")
        self.f1 = TF1("f1","pol0",0,91)
        self.mapeff={}
        self.mapnoise={}        
        if self.folder:
            tower = ["Far","Near"]
            wheel = ["W-2","W-1","W+0","W+1","W+2"]
            for i in wheel:
                for j in tower:
                    name =  str(i)+'_' + j + '_Side' 
                    histo = self.RootFile.FindObjectAny(name)
                    if histo:
                        nbins = histo.GetNbinsX()
                        for k in range(nbins):
                            lab = histo.GetXaxis().GetBinLabel(k+1)
                            if(lab == i + '_RB4-_S09_Forward'):
                                lab = i + '_RB4_S09_Forward'
                            elif (lab == i + '_RB4-_S09_Backward' ):
                                lab =  i + '_RB4_S09_Backward'
                            elif(lab == i + '_RB4-_S11_Forward'):
                                lab = i + '_RB4_S11_Forward'
                            elif (lab == i + '_RB4-_S11_Backward' ):
                                lab =  i + '_RB4_S11_Backward'                                
                            self.mapnoise[str(lab)] = histo.GetBinContent(k+1)

            tower = ["far","near"]
            prefi = "GlobEfficiencyWheel_"
            for i in range(-2,3):
                for j in tower:
                    name = prefi + str(i) + j
                    histo = self.folder.FindObjectAny(name)
                    if histo:
                        nbins = histo.GetNbinsX()
                        for k in range(nbins):
                            lab = histo.GetXaxis().GetBinLabel(k+1)
                            self.mapeff[str(lab)] = histo.GetBinContent(k+1)
                    elif i == -2 and histo == 0:
                        f=open('wheel_coord.txt', 'r')
                        for line in f:
                            coord = line.rstrip().split("  ")
                            for w in wheel:
                                histoname = 'LocalEfficiencyFromSegments_'+ str(w) + '_' + coord[0]
                                inputname = histoname.rstrip().split("_")
                                histo_back = histoname + '_Backward'
                                histo_for = histoname + '_Forward'
                                rolls_in_chamber = [histo_for,histo_back]
                                
                                if cmp(inputname[1],'W-2') == 0 and cmp(inputname[2],'RB2out') == 0:
                                    histo_middle = histoname + '_Middle'
                                    rolls_in_chamber.append(histo_middle)
                                elif cmp(inputname[1],'W+2') == 0 and cmp(inputname[2],'RB2out') == 0:
                                    histo_middle = histoname + '_Middle'
                                    rolls_in_chamber.append(histo_middle)    
                                elif (cmp(inputname[1],'W-1')==0 or cmp(inputname[1],'W+0')==0 or cmp(inputname[1],'W+1')==0) and cmp(inputname[2],'RB2in')==0:
                                    histo_middle = histoname + '_Middle'
                                    rolls_in_chamber.append(histo_middle)
                                for roll in rolls_in_chamber:
                                        try:
                                            name2 = roll.rstrip().split("_")
                                            self.RootFile.cd()
                                            histo = gDirectory.FindObjectAny(roll)
                                            histo.Fit(self.f1)
                                            media = (self.f1).GetParameter(0)
                                            
                                            self.mapeff[name2[1]+'_'+name2[2]+'_'+name2[3]+'_'+name2[4]]=media

                                        except AttributeError:
                                            pass                        
                        break
        
    def getMeanValue(self,histoname):
        inputname = histoname.rstrip().split("_")

        histo_back = histoname + '_Backward'
        histo_for = histoname + '_Forward'
        rolls_in_chamber = [histo_for,histo_back]

        if (cmp(inputname[1],'W+2') == 0 or cmp(inputname[1],'W-2') == 0) and cmp(inputname[2],'RB2out') == 0:
            histo_middle = histoname + '_Middle'
            rolls_in_chamber.append(histo_middle)
        elif (cmp(inputname[1],'W-1')==0 or cmp(inputname[1],'W+0')==0 or cmp(inputname[1],'W+1')==0) and cmp(inputname[2],'RB2in')==0:
            histo_middle = histoname + '_Middle'
            rolls_in_chamber.append(histo_middle)

        meanvalue = []
        
        for roll in rolls_in_chamber:
            try:
                if self.folder:
                    histo = self.folder.FindObjectAny(roll)
                else:    
                    histo = gDirectory.FindObjectAny(roll)
                meanvalue.append(histo.GetMean())
            except AttributeError:
                meanvalue.append(-100)
        return meanvalue


    def getMedia(self,histoname):
        inputname = histoname.rstrip().split("_")

        histo_back = histoname + '_Backward'
        histo_for = histoname + '_Forward'
        rolls_in_chamber = [histo_for,histo_back]

        if cmp(inputname[1],'W-2') == 0 and cmp(inputname[2],'RB2out') == 0:
            histo_middle = histoname + '_Middle'
            rolls_in_chamber.append(histo_middle)
        elif cmp(inputname[1],'W+2') == 0 and cmp(inputname[2],'RB2out') == 0:
            histo_middle = histoname + '_Middle'
            rolls_in_chamber.append(histo_middle)    
        elif (cmp(inputname[1],'W-1')==0 or cmp(inputname[1],'W+0')==0 or cmp(inputname[1],'W+1')==0) and cmp(inputname[2],'RB2in')==0:
            histo_middle = histoname + '_Middle'
            rolls_in_chamber.append(histo_middle)

        meanvalue = []
        for roll in rolls_in_chamber:
            name2 = roll.rstrip().split("_")
            try:
                meanvalue.append(self.mapeff[name2[1]+'_'+name2[2]+'_'+name2[3]+'_'+name2[4]])

            except KeyError:
                meanvalue.append(-100)
                
        return meanvalue
                    
    def getStatistics(self,histoname):
        histo = gDirectory.FindObjectAny(histoname)
        sul = histo.GetBinContent(1)
        return sul

        
    def getMaskedStrip(self,histoname):
        inputname = histoname.rstrip().split("_")

        histo_back = histoname + '_Backward'
        histo_for = histoname + '_Forward'
        rolls_in_chamber = [histo_for,histo_back]

        if cmp(inputname[1],'W-2') == 0 and cmp(inputname[2],'RB2out') == 0:
            histo_middle = histoname + '_Middle'
            rolls_in_chamber.append(histo_middle)
        elif cmp(inputname[1],'W+2') == 0 and cmp(inputname[2],'RB2out') == 0:
            histo_middle = histoname + '_Middle'
            rolls_in_chamber.append(histo_middle)    
        elif (cmp(inputname[1],'W-1')==0 or cmp(inputname[1],'W+0')==0 or cmp(inputname[1],'W+1')==0) and cmp(inputname[2],'RB2in')==0:
            histo_middle = histoname + '_Middle'
            rolls_in_chamber.append(histo_middle)

        meanvalue = []
        for roll in rolls_in_chamber:
            try:
                histo = gDirectory.FindObjectAny(roll)
                counter = 0
                for j in range(histo.GetNbinsX()):
                    if histo.GetBinContent(j+1) == 0: counter += 1
                    
                meanvalue.append((counter/histo.GetNbinsX())*100)
            except AttributeError:
                meanvalue.append(-100)
        return meanvalue

    def getNoise(self,histoname):
        inputname = histoname.rstrip().split("_")

        histo_back = histoname + '_Backward'
        histo_for = histoname + '_Forward'
        rolls_in_chamber = [histo_for,histo_back]

        if cmp(inputname[1],'W-2') == 0 and cmp(inputname[2],'RB2out') == 0:
            histo_middle = histoname + '_Middle'
            rolls_in_chamber.append(histo_middle)
        elif cmp(inputname[1],'W+2') == 0 and cmp(inputname[2],'RB2out') == 0:
            histo_middle = histoname + '_Middle'
            rolls_in_chamber.append(histo_middle)    
        elif (cmp(inputname[1],'W-1')==0 or cmp(inputname[1],'W+0')==0 or cmp(inputname[1],'W+1')==0) and cmp(inputname[2],'RB2in')==0:
            histo_middle = histoname + '_Middle'
            rolls_in_chamber.append(histo_middle)

        meanvalue = []
        for roll in rolls_in_chamber:
            name2 = roll.rstrip().split("_")
            try:
                meanvalue.append(self.mapnoise[name2[1]+'_'+name2[2]+'_'+name2[3]+'_'+name2[4]])

            except KeyError:
                meanvalue.append(-100)

        return meanvalue

    def plotHisto(self,histoname):
        c1 = TCanvas('c1','Imported ROOT histogram',200,10,700,500)    
        h1 = gDirectory.FindObjectAny(histoname)
        h1.Draw()
        c1.Update()
        return c1

    def setColour(self,mean_bx,mean_cls,noise,eff,masked):
        colour =''
        countRed = 0
        countGreen = 0
        countBlack = 0
        for value in mean_bx:
            if -3 < float(value) < -1. or 1. < float(value) < 3: countRed += 1
            elif -1. < float(value) < 1.: countGreen += 1
            elif float(value) == -100: countBlack += 1

        for value in mean_cls:
            if 2.5 < float(value): countRed += 1
            elif 1 <= float(value) <= 2.5: countGreen += 1
            elif float(value) == -100 or float(value) == 0.0: countBlack += 1

        for value in noise:
            if float(value) > 20: countRed += 1
            elif  0. <= float(value) <= 20: countGreen += 1
            elif float(value) == -100: countBlack += 1

        for value in eff:
            if 0 <= float(value) < 90: countRed += 1
            elif 90 <= float(value) <= 100: countGreen += 1
            elif float(value) == -100: countBlack += 1

        for value in masked:
            if float(value) > 4.: countRed += 1
            elif 0. <= float(value) <= 4.: countGreen += 1
            elif float(value) == -100: countBlack += 1
            
        if countRed == 1 and countBlack == 0: colour = 'yellow'
        elif countRed == 2 and countBlack == 0: colour = 'orange'
        elif countRed > 2 and countBlack == 0: colour = 'red'
        elif countBlack > 0: colour = 'black'
        elif countGreen > 0 and countBlack == 0 and countRed == 0: colour = 'green'
        
        return colour

    def setColourBx(self,mean_bx):
        colour =''
        countRed = 0
        countGreen = 0
        countBlack = 0
        for value in mean_bx:
            if -3 < float(value) < -1. or 1. < float(value) < 3: countRed += 1
            elif -1. <= float(value) <= 1.: countGreen += 1
            elif float(value) == -100: countBlack += 1

        if countRed == 1 and countBlack == 0: colour = 'yellow'
        elif countRed >= 2 and countBlack == 0: colour = 'red'
        elif countBlack > 0: colour = 'black'
        elif countGreen > 0 and countBlack == 0 and countRed == 0: colour = 'green'
        
        return colour

    def setColourCls(self,mean_cls):
        colour =''       
        countRed = 0
        countGreen = 0
        countBlack = 0

        for value in mean_cls:
            if 2.5 < float(value): countRed += 1
            elif 1 <= float(value) <= 2.5: countGreen += 1
            elif float(value) == -100 or float(value) == 0.0: countBlack += 1

        if countRed == 1 and countBlack == 0: colour = 'yellow'
        elif countRed >= 2 and countBlack == 0: colour = 'red'
        elif countBlack > 0: colour = 'black'
        elif countGreen > 0 and countBlack == 0 and countRed == 0: colour = 'green'
        
        return colour
    
    def setColourEff(self,eff):
        colour =''
        countRed = 0
        countGreen = 0
        countBlack = 0

        for value in eff:
            if value <= 1:
                value = value*100
            if 0 <= float(value) < 90: countRed += 1
            elif 90 <= float(value) <= 100: countGreen += 1
            elif float(value) == -100: countBlack += 1

        if countRed == 1 and countBlack == 0: colour = 'yellow'
        elif countRed >= 2 and countBlack == 0: colour = 'red'
        elif countBlack > 0: colour = 'black'
        elif countGreen > 0 and countBlack == 0 and countRed == 0: colour = 'green'
        
        return colour
    
    def setColourNoise(self,noise):
        colour =''
        countRed = 0
        countGreen = 0
        countBlack = 0

        for value in noise:
            if float(value) > 5.: countRed += 1
            elif 0. <= float(value) <= 5.: countGreen += 1
            elif float(value) == -100: countBlack += 1            

        if countRed == 1 and countBlack == 0: colour = 'yellow'
        elif countRed >= 2 and countBlack == 0: colour = 'red'
        elif countBlack > 0: colour = 'black'
        elif countGreen > 0 and countBlack == 0 and countRed == 0: colour = 'green'

        return colour


    def setColourMasked(self,masked):
        colour =''
        countRed = 0
        countGreen = 0
        countBlack = 0

        for value in masked:
            if float(value) > 4.: countRed += 1
            elif 0. <= float(value) <= 4.: countGreen += 1
            elif float(value) == -100: countBlack += 1

        if countRed == 1 and countBlack == 0: colour = 'yellow'
        elif countRed >= 2 and countBlack == 0: colour = 'red'
        elif countBlack > 0: colour = 'black'
        elif countGreen > 0 and countBlack == 0 and countRed == 0: colour = 'green'

        return colour
