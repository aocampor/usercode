#! /usr/bin/env python
from ROOT import TCanvas,TH1F,gROOT,TFile,gDirectory,TGraphErrors
from Tkinter import *
from math import *

class Diagnostic(object):

##    def invSigm(self,p0,p1,p2,y):
##        x = 1/p1*(log(p0/y)-1) + p2
##        return x

    def __init__(self,root_file_name):
        self.RootFile=TFile.Open(root_file_name)
        #print root_file_name

    def getPlateauVal(self,histoname):
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
           
        plateauv = []
        for roll in rolls_in_chamber:
            try:
                heffName = 'hefficiency_' + roll
                histo = gDirectory.FindObjectAny(heffName)
                f1 = histo.GetFunction("f1")
                plateauv.append(f1.GetParameter(0))
            except AttributeError:
                plateauv.append(-100.)
                
        return plateauv
        
    def getNoiseVal(self,histoname):
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
           
        noisev = []
        for roll in rolls_in_chamber:
            try:
                hnoiseName = 'hnoise_' + roll
                histo = gDirectory.FindObjectAny(hnoiseName)
                nBins = histo.GetXaxis().GetNbins()
                noisev.append(histo.GetBinContent(nBins-1))
            except AttributeError:
                noisev.append(-100.)
            
        return noisev

    def setColourEff(self,plateauv):
        colour =''
        countRed = 0
        countGreen = 0
        countBlack = 0

        for pval in plateauv:
            if float(pval) == -100.0: countBlack += 1
            elif float(pval) < 90: countRed += 1
            elif 90 <= float(pval) <= 100:  countGreen += 1
            elif float(pval) > 100: countPurple += 1

        if countBlack == 0:
            if countRed == 1: colour = 'yellow'
            elif countRed > 1: colour = 'red'
            elif countGreen > 1 and countRed == 0: colour = 'green'
        else: colour = 'black'
            
        return colour
            
    def setColourNoise(self,noisev):
        colour =''
        countRed = 0
        countGreen = 0
        countBlack = 0

        for nval in noisev:
            if float(nval) == -100.0: countBlack += 1
            elif float(nval) >= 3000: countRed += 1
            elif float(nval) < 2000:  countGreen += 1

        if countBlack == 0:
            if countRed == 1: colour = 'yellow'
            elif countRed > 1: colour = 'red'
            elif countGreen > 1 and countRed == 0: colour = 'green'
        else: colour = 'black'

        return colour

    def setColour(self,plateauv,noisev):
        colour =''
        countRed = 0
        countYellow = 0
        countGreen = 0
        countBlack = 0
        countPurple = 0

        for value in noisev:
            if float(value) == -100: countBlack += 1
            elif float(value) >= 3000: countRed += 1
            elif  0. <= float(value) < 3000: countGreen += 1
                
        for value in plateauv:
            if float(value) == -100: countBlack += 1
            elif 0 <= float(value) < 90: countRed += 1
            elif 90 <= float(value) <= 100: countGreen += 1

        if countBlack == 0:
            if countRed == 1: colour = 'yellow'
            elif countRed == 2 and countGreen > 0: colour = 'orange'
            elif countRed == 2 and countGreen == 0: colour = 'red'
            elif countRed > 2: colour = 'red'
            elif countYellow > 0: colour = 'yellow'
            elif countGreen > 0 and countRed == 0: colour = 'green'
            elif countPurple > 0: colour = 'violet'
        else: colour = 'black'

        return colour

