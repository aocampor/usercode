#! /usr/bin/env python
import commands
import sys, os, string, fileinput
from Tkinter import *
from ROOT import TCanvas,TH1F,gROOT,TFile,gDirectory,gStyle
from math import *

def err(n,p):
    return (1/n)*sqrt(p*(n-p)/n)

def binerr (n,p):
    if n > 0 :
        err0 = err(n,p)
    else :
        err0 = 0
    return err0

def bincon (n , p ):
    if n > 0 :
        con = p/n
    else :
        con = 0
    return con
                                                            

                        
#
# main
#


if __name__ == "__main__":
    gStyle.SetOptStat(0)
    root = Tk()
    file1 = TFile(str(sys.argv[1]))
    #    file2 = TFile(str(sys.argv[2]))
 #   gDirectory.cd(file1)
##    run = str(sys.argv[2])
    c1 = TCanvas('c1','Imported ROOT histogram',200,10,700,500)
    c1.Divide(1,2)
    c1.cd(1)
    h1 = gDirectory.FindObjectAny('NTrigMuon')
    h2 = gDirectory.FindObjectAny('NTrigRPC')
    h3 = gDirectory.FindObjectAny('NTrigCSC')
    h4 = gDirectory.FindObjectAny('NTrigDT')
    h5 = gDirectory.FindObjectAny('NTrigECAL')
    h6 = gDirectory.FindObjectAny('NDigiRPC')
    h7 = gDirectory.FindObjectAny('NDigiCSC')
    h8 = gDirectory.FindObjectAny('NDigiDT')
    h9 = gDirectory.FindObjectAny('NRecHitECAL')
    h10 = gDirectory.FindObjectAny('NRecHitHCAL')
    h11 = gDirectory.FindObjectAny('NDigiTracker')
    h12 = gDirectory.FindObjectAny('NDigiPixel')
    h20 = gDirectory.FindObjectAny('NEven')
    bins = h6.GetNbinsX()
    h13 = TH1F('NoiseProfile','Noise profile',bins,0,bins)
    for i in range (1,bins):
        h13.SetBinContent(i,bincon(h20.GetBinContent(i),h6.GetBinContent(i)))
    bins = h7.GetNbinsX()
    h14 = TH1F('NoiseProfile1','Noise profile',bins,0,bins)
    for i in range (1,bins):
        h14.SetBinContent(i,bincon(h20.GetBinContent(i),h7.GetBinContent(i)))
    bins = h8.GetNbinsX()
    h15 = TH1F('NoiseProfile2','Noise profile',bins,0,bins)
    for i in range (1,bins):
        h15.SetBinContent(i,bincon(h20.GetBinContent(i),h8.GetBinContent(i)))
    bins = h9.GetNbinsX()
    h16 = TH1F('NoiseProfile3','Noise profile',bins,0,bins)
    for i in range (1,bins):
        h16.SetBinContent(i,bincon(h20.GetBinContent(i),h9.GetBinContent(i)))
    bins = h10.GetNbinsX()
    h17 = TH1F('NoiseProfile4','Noise profile',bins,0,bins)
    for i in range (1,bins):
        h17.SetBinContent(i,bincon(h20.GetBinContent(i),h10.GetBinContent(i)))
    bins = h11.GetNbinsX()
    h18 = TH1F('NoiseProfile5','Noise profile',bins,0,bins)
    for i in range (1,bins):
        h18.SetBinContent(i,bincon(h20.GetBinContent(i),h11.GetBinContent(i)))
    bins = h12.GetNbinsX()
    h19 = TH1F('NoiseProfile6','Noise profile',bins,0,bins)
    for i in range (1,bins):
        h19.SetBinContent(i,bincon(h20.GetBinContent(i),h12.GetBinContent(i)))                

                
    h1.SetLineColor(1)
    h2.SetLineColor(2)
    h3.SetLineColor(3)
    h4.SetLineColor(4)
    h5.SetLineColor(5)
    h1.SetTitle('Run ' +  str(sys.argv[2]))
    h1.GetXaxis().SetTitle('Seconds')
    h1.GetYaxis().SetTitle('Trigger Rate')
    h1.Draw()
    h2.Draw()
#    h6.Draw()
 #   h20.SetLineColor(3)
  #  h12.SetLineColor(2)
   # h20.Draw('SAME')
    #h13.Draw('SAME')
    h3.Draw('SAME')
    h4.Draw('SAME')
    h5.Draw('SAME')
    c1.cd(1).SetLogy()
    c1.SetLogy()
    c1.cd(2)
    h13.SetLineColor(2)
    h14.SetLineColor(3)
    h15.SetLineColor(4)
    h16.SetLineColor(5)
    h17.SetLineColor(6)
    h18.SetLineColor(7)
    h19.SetLineColor(8)
    h17.Draw()
    h15.Draw('SAME')
    h14.Draw('SAME')
    h16.Draw('SAME')
    h13.Draw('SAME')
    h18.Draw('SAME')
    h19.Draw('SAME')
    c1.cd(2).SetLogy()
#    c1.SaveAs('Trigger_'+str(sys.argv[1])+'.png')
    print 'al peluche'
    root.mainloop()
