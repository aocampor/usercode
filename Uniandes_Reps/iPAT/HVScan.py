#! /usr/bin/env python
import commands
import sys, os, string, fileinput
from Tkinter import *
from array import array
from ROOT import TCanvas, TH1F, gROOT, TFile, gDirectory, TMath, TGraphErrors, TF1, TMath
from math import sqrt,fabs
import ROOT

class HVScan(Frame):
    def __init__(self,dataset,runs,hvlist):

        print "Constructor"

        ROOT.gROOT.SetBatch(ROOT.kTRUE)

        self.RootFileOut = TFile("prova.root","RECREATE")

        self.hvmax = TH1F("Eff Max","Eff max",100,0.,100);
        self.Svalue = TH1F("Svalue","Svalue",400,-0.5,0.5);
        self.HVeff50 = TH1F("HVeff50","HVeff50",100,8500,9500);
        self.HVeff90 = TH1F("HVeff90","HVeff90",100,8500,11500);
        self.HVeff95 = TH1F("HVeff95","HVeff95",100,8500,11500);
        
        self.EffMaxExp1 = TH1F("Eff Max exp 1","Eff max exp 1",100,0.,100);
        self.EffMaxExp2 = TH1F("Eff Max exp 2","Eff max exp 2",100,0.,100);

        self.DeltaEffMaxExp1 = TH1F("Delta Eff Max exp 1"," Delta Eff max exp 1",100,-10.,10);
        self.DeltaEffMaxExp2 = TH1F("Delta Eff Max exp 2"," Delta Eff max exp 2",100,-10.,10);
                
        self.hvlist = hvlist
        self.RootFilesEff = []
        self.RootFilesNoise = []
        effMap = []
        noiseMap = []

        count = 0
        print "Loop of runs"

        ds = str(dataset).replace('/','')

        for run in runs:

            RootFileNameEff = 'rfio:/castor/cern.ch/cms/store/caf/user/ccmuon/RPC/GlobalRuns/'+ds+'/'+run+'/root/Merge_DQM_SRPC.root?svcClass=cmscafuser'
            RootFileNameNoise = 'rfio:/castor/cern.ch/cms/store/caf/user/ccmuon/RPC/GlobalRuns/'+ds+'/'+run+'/noise/'+run+'_final.root?svcClass=cmscafuser'
                
            tempEff = TFile.Open(RootFileNameEff)
            tempNoise = TFile.Open(RootFileNameNoise)
            self.RootFilesEff.append(tempEff)
            self.RootFilesNoise.append(tempNoise)
            count += 1


        detList = self.fillDetList()

        for root in self.RootFilesEff:
            effMap.append(self.createEffMap(root,detList))

        self.producePlots(effMap,"efficiency")


        for casa in self.RootFilesNoise :
            noiseMap.append(self.createNoiseMap(casa,detList))
        self.producePlots(noiseMap,"noise")
        
    def func(self,x,par):

        effmax = par[0]
        S = par[1]
        HV50 = par[2]

        return effmax/(1.0 + TMath.Exp( S * ( x[0] - HV50 )))

    def func1(self,x,par):
        return (1/par[1])*(TMath.Log((par[0]/x)-1))+par[2]

    def producePlots(self,effMap,dataType):

        loop = 0
        mast = 0
        for k in (effMap[0]).keys():
            loop += 1
            efferrlist = []
            efflist =[]
            errlist = []
            
            for imap in effMap:
                efferrlist.append(imap.get(k))


            for iv in range(len(efferrlist)):
                vals = efferrlist[iv]                
                efflist.append(vals[0])
                errlist.append(vals[1])

            eff = []
            err = []
            hverr = []
            for ca in range(len(self.hvlist)):
                hverr.append(0)

            hv = array("d",self.hvlist)
            hvr = array("d",hverr)
            eff = array("d",efflist)
            err = array("d",errlist)

            self.RootFileOut.cd()

            nGood = 0
            for vals in eff:
                if vals>0:
                    nGood += 1

            if nGood>1:
                canName = 'c'+ str(dataType)+'_'+ k 
                histoName = 'h'+ str(dataType)+'_'+ k 
                c1 = TCanvas(canName,canName,1)
                c1.SetHighLightColor(2);
                c1.SetBorderMode(0);
                c1.SetBorderSize(2);
                c1.SetFrameBorderMode(0);
                
                bins = ((float(hv[len(hv)-1])-float(hv[0]))/100.)+1
                min = int(hv[0])-50
                max = int(hv[len(hv)-1])+50
                gr = TH1F(histoName,histoName,int(bins),min,max)                
                gr.GetXaxis().SetTitle("HV (Volt)");
                gr.GetXaxis().SetLabelFont(32);
                gr.GetXaxis().SetTitleFont(32);
                if str(dataType) == "efficiency": gr.GetYaxis().SetTitle("Efficiency (%)")
                if str(dataType) == "noise": gr.GetYaxis().SetTitle("Rate (Hz)")
                gr.GetYaxis().SetLabelFont(32);
                gr.GetYaxis().SetTitleFont(32);
                
                gre = TGraphErrors(len(eff),hv,eff,hvr,err)
                gre.SetFillColor(1);
                gre.SetMarkerColor(2);
                gre.SetMarkerStyle(22);
                gre.SetTitle(str(dataType)+'_'+ k)
                gre.GetXaxis().SetTitle("HV (Volt)");
                gre.GetXaxis().SetLabelFont(32);
                gre.GetXaxis().SetTitleFont(32);
                
                if str(dataType) == "efficiency": gre.GetYaxis().SetTitle("Efficiency (%)")
                if str(dataType) == "noise": gre.GetYaxis().SetTitle("Rate (Hz)")
                
                gre.GetYaxis().SetLabelFont(32);
                gre.GetYaxis().SetTitleFont(32);
                
                for i in range(len(hv)):

                    gr.SetBinContent(int(((float(hv[i])-float(hv[0]))/100)+1),eff[i])
                    gr.SetBinError(int(((float(hv[i])-float(hv[0]))/100)+1),err[i])


                if str(dataType) == "efficiency":    
                    fit_effmax = 90
                    fit_S = -0.02
                    fit_HV50 = 80

                    print "About to fitting: ",k, efflist
                
                    self.f1 = TF1("f1",self.func,8500,9500,3)
                    self.f1.SetFillColor(19);
                    self.f1.SetFillStyle(0);
                    self.f1.SetMarkerStyle(22);
                    self.f1.SetMarkerSize(2.5);
                    self.f1.SetLineWidth(2);
                   
                    self.f1.SetParameter(0,fit_effmax)
                    self.f1.SetParLimits(0,0.,100) 
                    self.f1.SetParameter(1,fit_S)
                    self.f1.SetParLimits(1,-0.5,0.5)  
                    self.f1.SetParameter(2,fit_HV50)
                    self.f1.SetParLimits(2,8500,9500)
                
                    gr.Fit(self.f1)
                    gre.Fit(self.f1)
                    self.hvmax.Fill(self.f1.GetParameter(0))
                    self.Svalue.Fill(self.f1.GetParameter(1))
                    self.HVeff50.Fill(self.f1.GetParameter(2))

                    x90 = self.f1.GetParameter(0)*0.90
                    x95 = self.f1.GetParameter(0)*0.95

                    p = [self.f1.GetParameter(0),self.f1.GetParameter(1),self.f1.GetParameter(2)]

                    hv90 = self.func1(x90,p)
                    hv95 = self.func1(x95,p)
                
                    self.HVeff90.Fill(hv90)
                    self.HVeff95.Fill(hv95)
                    self.EffMaxExp1.Fill(eff[len(eff)-1])
                    self.EffMaxExp2.Fill(eff[len(eff)-2])
                    
                    self.DeltaEffMaxExp1.Fill(fabs(self.f1.GetParameter(0)-eff[len(eff)-1]))
                    self.DeltaEffMaxExp2.Fill(fabs(self.f1.GetParameter(0)-eff[len(eff)-2]))

                elif str(dataType) == "noise":
                    pass
                  
                gr.Draw("AP*")
                self.RootFileOut.WriteTObject(gr)
                c1.Clear()
                gre.Draw("AP*")
                c1.Write()
                
            else: print "Won't fit ", k, efflist
            
        self.hvmax.Write()
        self.Svalue.Write()
        self.HVeff50.Write()
        self.HVeff90.Write()
        self.HVeff95.Write()
        self.EffMaxExp1.Write()
        self.EffMaxExp2.Write()
        self.DeltaEffMaxExp1.Write()
        self.DeltaEffMaxExp2.Write()
        
    def createEffMap(self,rootfile,detList):
        print "Inside create map"
        detMap = {}
        wheels = ["W-2","W-1","W+0","W+1","W+2"]
        for wheel in wheels:
            for det in detList:
                chname = wheel+'_'+det
                histoname = 'LocalEfficiencyFromSegments_'+chname
                efferr = self.getMedia(rootfile,histoname)
                eff = efferr[0]
                err = efferr[1]
                detMap[chname+'_Forward'] = [eff[0],err[0]]
                detMap[chname+'_Backward'] = [eff[1],err[1]]

                if len(eff) == 3:
                    detMap[chname+'_Middle'] = [eff[2],err[2]]

        return detMap

    def createNoiseMap(self,rootfile,detList):
        print "Inside create map"
        detMap = {}
        wheels = ["W-2","W-1","W+0","W+1","W+2"]
        for wheel in wheels:
            for det in detList:
                chname = wheel+'_'+det
                listRoll = [chname+'_Forward',chname+'_Backward',chname+'_Middle']
                histonameNear = wheel+'_Near_Side'
                histonameFar = wheel+'_Far_Side'
                if self.findNear(chname):
                    rootfile.cd()
                    histo = gDirectory.FindObjectAny(histonameNear)
                    for j in range(histo.GetNbinsX()):
                        lab = histo.GetXaxis().GetBinLabel(j+1)
                        for i in listRoll:
                            if lab == i:
                                detMap[i] = [histo.GetBinContent(j+1),sqrt(histo.GetBinContent(j+1))]
                else:
                    rootfile.cd()
                    histo = gDirectory.FindObjectAny(histonameFar)
                    for j in range(histo.GetNbinsX()):
                        lab = histo.GetXaxis().GetBinLabel(j+1)
                        for i in listRoll:
                            if lab == i:
                                detMap[i] = [histo.GetBinContent(j+1),sqrt(histo.GetBinContent(j+1))]

        return detMap
    
        
    def getMedia(self,rootfile,histoname):
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
        elif (cmp(inputname[1],'W-1') == 0 or cmp(inputname[1],'W+0') == 0 or cmp(inputname[1],'W+1') == 0) and cmp(inputname[2],'RB2in') == 0: 
            histo_middle = histoname + '_Middle'
            rolls_in_chamber.append(histo_middle)

        meanvalue = []
        errvalue = []
        mediavals = []
        rootfile.cd()
        for roll in rolls_in_chamber:
            try:
                histo = gDirectory.FindObjectAny(roll)
                eff = 0
                err = 0
                media = 0
                ermedia = 0
                strips = histo.GetNbinsX()
                dead = 0
                gnum = 0

                for j in range(histo.GetNbinsX()):
                    eff = eff + histo.GetBinContent(j+1)
                    err = err + (histo.GetBinError(j+1))**2

                    if histo.GetBinContent(j+1) == 0:
                        dead += 1 
                gnum = strips - dead
                deadPerc=float(gnum)/float(strips)
                if deadPerc>0.5 and gnum > 0:   
                    media = eff/gnum
                    ermedia = sqrt(err/float(gnum))
                    meanvalue.append(media)
                    errvalue.append(ermedia)
                else:
                    meanvalue.append(0)
                    errvalue.append(0)
            except AttributeError:
                meanvalue.append(-1)
                errvalue.append(-1)

        mediavals.append(meanvalue)
        mediavals.append(errvalue)
        return mediavals
        
    def fillDetList(self):

        print "inside fillDetLIst"
        
        cmd = "pwd"
        homedir = [item[:-1] for item in os.popen(cmd)]
        f = open(str(homedir[0])+'/wheel_coord.txt', 'r')
        
        detList = []
        for line in f:
            coord = line.rstrip().split("  ")
            detList.append(coord[0])

        f.close()
        return detList


    def plotHisto(self):
        listWheel = ['W-2','W-1','W+0','W+1','W+2']
        listBarrel = self.fillListBarrel()
        histoBx = TH1F("Barrel Bunch Crossing","",16,-7.5,7.5)
        diagn = Diagnostic(self.RootFileName)
        for k in listWheel:
            for j in listBarrel:
                
                histoname_bx = 'BXN_'+k+'_' + j
                
                histoBx.Fill(diagn.getMeanValue(histoname_bx)[0])
                histoBx.Fill(diagn.getMeanValue(histoname_bx)[1])
        c1 = TCanvas("c1","c1",1)        
        histoBx.Draw()
        c1.SaveAs("/tmp/trentad/Barrel_Bx.gif")

    def fillListBarrel(self):

        cmd = "pwd"
        homedir = [item[:-1] for item in os.popen(cmd)]
        f = open(str(homedir[0])+'/wheel_coord.txt', 'r')
        
        detMap = []
        for line in f:
            coord = line.rstrip().split("  ")
            chname = ''
            detMap.append(str(coord[0]))

        f.close()            
        return detMap

    def fillListEndcap(self):

        cmd = "pwd"
        homedir = [item[:-1] for item in os.popen(cmd)]
        f = open(str(homedir[0])+'/disk_coord.txt', 'r')
        
        detMap = []
        for line in f:
            coord = line.rstrip().split("  ")
            chname = ''
            detMap.append(str(coord[0]))

        f.close()            
        return detMap

    def findNear(self,name):
        coord = name.rstrip().split("_")
        near = False
        sec = ["S01","S02","S03","S04","S05","S06","S07","S08","S09","S10","S11","S12"]
        counter = 0
        for i in sec:
            if str(i) == str(coord[2]) and (counter < 3 or counter > 8):
                near = True
                break
            else:
                near = False
            counter+=1
        return near


    
if __name__ == "__main__":

    runs = [ "110315","109817","109624","108889","109562","110409" ]
    hvlist   = [ 8800,9000,9100,9200,9300,9400 ]

    HVScan('/StreamExpress/CRAFT09-RpcCalHLT-v1/ALCARECO',runs,hvlist)
    
