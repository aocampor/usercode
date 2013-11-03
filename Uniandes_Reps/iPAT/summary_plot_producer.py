#! /usr/bin/env python
from Tkinter import *
import commands
import sys, os, string, fileinput
from sys import argv
from ROOT import *

if __name__ == '__main__':

    RootFile=TFile.Open(str(sys.argv[1]))
    wheel = sys.argv[2]
    RootOut=TFile.Open(str(sys.argv[1]) + '_' + str(wheel) + '_summary_out.root',"RECREATE")

    layers = ['RB1in','RB1out','RB2in','RB2out','RB3','RB4']
    cham = ['','+','-']
    roll = ['Forward','Backward','Middle']
    sectors = ['S04','S05','S06','S07','S08','S09','S10','S11','S12','S01','S02','S03']
    bin2 = 1
    
    title1 = str(wheel) + '_summary' + str(sys.argv[1])
    titlel = str(wheel) + '_layer_summary' + str(sys.argv[1])
    plotl = TH1F(titlel,titlel,4,0,4)
    plot1 = TH1F(title1,title1,12,0,12)
    bins = 1
    crol = 0
    for ob in sectors:
        if(ob == 'S04' or ob == 'S10'):
            bin = 1
            if(ob=='S04'):
                title = str(wheel)+'_Far_Side'
            else:
                title = str(wheel)+'_Near_Side'
            plot = TH1F(title,title,110,0,110)
        cont = 0    
        for item in layers:
            for thing in cham:
                for thing2 in cham:
                    for ding in roll:
                        mir = true
                        if ((item == 'RB3' or item == 'RB4') and thing2 == '' ):
                            mir = false
                        if(mir):
                            histname = str(wheel) + '_' + str(item) + str(thing) + str(thing2) + '_' + str(ob) + '_' + str(ding) + '_media'
                            binname = str(wheel) + '_' + str(item) + str(thing) + str(thing2) + '_' + str(ob) + '_' + str(ding) 
                            histo = RootFile.FindObjectAny(histname)
                            if(histo):
                                crol = crol + 1
                                histmed = TH1F(histname + '_frq_dist',histname + '_media',500000,0,5000)
                                xbins = histo.GetXaxis().GetNbins()
                                plot.GetXaxis().SetBinLabel(bin,binname)
                                plot1.GetXaxis().SetBinLabel(bins,str(wheel)+'_'+str(ob))
                                for i in range(xbins):
                                    histmed.Fill(histo.GetBinContent(i+1))
                                nmean = histmed.GetMean()
                                sigma = histmed.GetRMS()
                                cerr = 0
                                for i in range(xbins):
                                    num = histo.GetBinContent(i+1)

                                    cont = cont + histo.GetBinError(i+1)
#                                    if (num < nmean + 3*sigma):
                                      #if (num <= 100):
                                    cerr = cerr + histo.GetBinError(i+1)
                                    plot.Fill(bin-1,num)
                                    plot1.Fill(bins-1,num)
                                plot.SetBinError(bin-1,cerr)
                                bin = bin + 1
                                plot.GetXaxis().SetLabelSize(0.03)
                                plot.GetYaxis().SetTitle('Hz')
        plot1.SetBinError(bins-1,cont)                                                            
        bins = bins + 1                        
        if(ob == 'S09' or ob == 'S03'):
            plot.GetXaxis().LabelsOption("V")
            gStyle.SetOptStat(0)    
            if(RootOut.cd()):
                plot.Write()
                plot1.Write()
    plot1.Write()            

