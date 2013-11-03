#! /usr/bin/env python
from Tkinter import *
import commands
import sys, os, string, fileinput
from sys import argv
from ROOT import *

if __name__ == '__main__':

    RootFile1=TFile.Open(str(sys.argv[1])+'_01_out1.root_summary_out.root')
    ch1 = TCanvas("Resume","Resumen",1397,299,700,502)
    histname = 'W+1_Far_Side97210_01_out1.root'

    histo1 = RootFile1.FindObjectAny(histname)
    histo1.SetName('primohisto')
    histo1.Draw()
    n = histo1.GetNbinsX()
    RootFile2 = TFile.Open('Noise_RB+1_far_2009_5_20__21_58_12_th240_hv9300.root')
    histo2 = RootFile2.FindObjectAny('Summary with sum')
#    histo2.Draw('SAME')
    histo3 = TH1F("histo3","histo3",n,1,n)
    infile = open('test','r')
    a = []
    for line in infile.readlines():
        a.append(line.split()[3])


    for item in range(n):
        binname = histo1.GetXaxis().GetBinLabel(item)        
        cont = 0
        for cosa in a:
            b = cosa.split('/')[0] + '_' + cosa.split('/')[1]
            if (cosa.split('/')[2][1] == '+' or cosa.split('/')[2][1] == '-' ):
                b = b + cosa.split('/')[2][1]
                if (cosa.split('/')[2][2] == '+' or cosa.split('/')[2][2] == '-' ):
                    b = b + cosa.split('/')[2][2]
            else:
                if ( cosa.split('/')[1] == 'RB4' ):
                    b = b + '-'
            b = b + '_S0' + cosa.split('/')[2][0] + '_'
            if ( cosa.split('/')[2].find('Forward') != -1):
                b = b + 'Forward'
            if ( cosa.split('/')[2].find('Backward') != -1):
                b = b + 'Backward'
            if ( cosa.split('/')[2].find('Central') != -1):
                b = b + 'Middle'
            #print binname + ' ' + b 
            if (binname == b):
               # print 'oofline name: ' + binname + ' online name: '+ b + ' item: ' + str(item) + ' cont: ' + str(cont) + ' value: ' + str(histo2.GetBinContent(cont))
                histo3.SetBinContent(item,histo2.GetBinContent(cont))
            cont = cont + 1       
    histo3.Draw('SAME')                
        #print binname
    infile.close()    
    ch1.SaveAs('compnoise.C')
