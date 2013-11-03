#! /usr/bin/env python
from ROOT import TCanvas,TH1F,gROOT,TFile,gDirectory
from Tkinter import *
from math import *

class DiagnosticDisk(object):

    def __init__(self,root_file_name):
        self.RootFile=TFile.Open(root_file_name)
        
    def retrieve_historoot(self,root_histo_name):
        self.HistoRoot=self.RootFile.Get(root_histo_name)

    def getMeanValue(self,histoname):
        inputname = histoname.rstrip().split("_")

        histo_A = histoname + '_A'
        histo_B = histoname + '_B'
        histo_C = histoname + '_C'
        rolls_in_chamber = [histo_A,histo_B,histo_C]

        meanvalue = []
        for roll in rolls_in_chamber:
            try:
                histo = gDirectory.FindObjectAny(roll)
                meanvalue.append(histo.GetMean())
            except AttributeError:
                meanvalue.append(-100)
        return meanvalue


    def getMedia(self,histoname):
        inputname = histoname.rstrip().split("_")

        histo_A = histoname + '_A'
        histo_B = histoname + '_B'
        histo_C = histoname + '_C'
        rolls_in_chamber = [histo_A,histo_B,histo_C]

        meanvalue = []
        for roll in rolls_in_chamber:
            try:
                histo = gDirectory.FindObjectAny(roll)
                if not histo:
                    vname = roll.rstrip().split("_")
                    name = "Profile_"+vname[1]+"_"+vname[2]+"_"+vname[3]+"_"+vname[4]
                    histo = gDirectory.FindObjectAny(name)
                    
                eff = 0
                for j in range(histo.GetNbinsX()):
                    eff = eff + histo.GetBinContent(j+1)
                media=eff/histo.GetNbinsX()
                meanvalue.append(media)
                
            except AttributeError:
                meanvalue.append(-100)
                
        return meanvalue
                    
    def getStatistics(self,histoname):
        histo = gDirectory.FindObjectAny(histoname)
        sul = histo.GetBinContent(1)
        return sul

        
    def getMaskedStrip(self,histoname):
        inputname = histoname.rstrip().split("_")

        histo_A = histoname + '_A'
        histo_B = histoname + '_B'
        histo_C = histoname + '_C'
        rolls_in_chamber = [histo_A,histo_B,histo_C]

        meanvalue = []
        for roll in rolls_in_chamber:
            try:
                histo = gDirectory.FindObjectAny(roll)
                counter = 0
                for j in range(histo.GetNbinsX()):
                    if histo.GetBinContent(j+1) == 0: counter += 1
                    
                meanvalue.append(counter)
            except AttributeError:
                meanvalue.append(-100)
        return meanvalue



    def getNoise(self,histoname):
        inputname = histoname.rstrip().split("_")

        histo_A = histoname + '_A'
        histo_B = histoname + '_B'
        histo_C = histoname + '_C'
        rolls_in_chamber = [histo_A,histo_B,histo_C]

        meanvalue = []
        for roll in rolls_in_chamber:
            try:
                names = roll.rstrip().split("_")
                names2 = names[0] + '_'
                if(names[2] == 'CH13' or names[2] == 'CH14' or names[2] == 'CH15' or names[2] == 'CH16' or names[2] == 'CH17' or names[2] == 'CH18' or names[2] == 'CH19' or names[2] == 'CH20' or names[2] == 'CH21' or names[2] == 'CH22' or names[2] == 'CH23' or names[2] == 'CH24' or names[2] == 'CH25' or names[2] == 'CH26' or names[2] == 'CH27' or names[2] == 'CH28' or names[2] == 'CH29' or names[2] == 'CH30'):
                    names2 = names2 + 'Far_Side'#_media.root'
                else:
                    names2 = names2 + 'Near_Side'#_media.root'
                histo = gDirectory.FindObjectAny(names2)
#                histo = gDirectory.FindObjectAny(roll)
                nbins = histo.GetNbinsX()
                for i in range(nbins):
                    aux_name = histo.GetXaxis().GetBinLabel(i)
                    if(aux_name == roll):
                        meanvalue.append(histo.GetBinContent(i))
####################3
#                histo = gDirectory.FindObjectAny(roll)
                
 #               value_atpeak = histo.GetBinContent(histo.GetMaximumBin())
  #              left_edge = histo.FindBin(-3.0)
   #             right_edge = histo.FindBin(3.0)
                
    #            value_for_left_edge = histo.GetBinContent(left_edge)
     #           value_for_right_edge = histo.GetBinContent(right_edge)
      #          if value_atpeak != 0:
       #             delta = fabs(value_for_left_edge - value_for_right_edge)
        #            minvalue = min(value_for_left_edge,value_for_right_edge)
         #           maxvalue = max(value_for_left_edge,value_for_right_edge)
          #          errmin = sqrt(minvalue)

           #         if fabs(maxvalue-minvalue) <= errmin: 
            #            delta1 = 100.0-(100.0*(value_atpeak - value_for_left_edge)/value_atpeak)
             #           delta2 = 100.0-(100.0*(value_atpeak - value_for_right_edge)/value_atpeak)
              #          meanvalue.append(max(delta1,delta2))
               #     else:
                #        meanvalue.append(1.)
            except AttributeError:
                meanvalue.append(-100)
        return meanvalue

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
            if float(value) > 20.: countRed += 1
            elif 0. <= float(value) <= 20.: countGreen += 1
            elif float(value) == -100: countBlack += 1

        if countRed == 1 and countBlack == 0: colour = 'yellow'
        elif countRed >= 2 and countBlack == 0: colour = 'red'
        elif countBlack > 0: colour = 'black'
        elif countGreen > 0 and countBlack == 0 and countRed == 0: colour = 'green'

        return colour

    def setColourNoise2(self,noise):
        colour =''
        countRed = 0
        countGreen = 0
        countBlack = 0

        for value in noise:
            if float(value) > 3000.: countRed += 1
            elif 0. <= float(value) <= 3000.: countGreen += 1
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
