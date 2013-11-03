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
    h2 = gDirectory.FindObjectAny('BunchXDifrpc')
    h1.SetLineColor(1)
    h2.SetLineColor(1)
    h1.GetXaxis().SetTitle('Seconds')
    h1.GetYaxis().SetTitle('Trigger Rate')
    h1.SetTitle('Run ' +  str(sys.argv[2]))
    h1.Draw()
    c1.cd(2)
    h2.SetTitle('Run ' +  str(sys.argv[2]))
    h2.GetXaxis().SetTitle('#Delta Bx')
    h2.GetYaxis().SetTitle('Event pairs')
    h2.Draw()
    c1.cd(2).SetLogy()
    print 'al peluche'
    root.mainloop()
