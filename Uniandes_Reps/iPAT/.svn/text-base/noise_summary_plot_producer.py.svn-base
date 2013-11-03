#! /usr/bin/env python
#from Tkinter import *
import commands
import sys, os, string, fileinput
from sys import argv
from ROOT import *

def findArea(name):
    cmd = "pwd"
    homedir = [item[:-1] for item in os.popen(cmd)]
    area = 0
    f=open(str(homedir[0])+'/area_noise.txt', 'r')
    for line in f:
        coord = line.rstrip().split(" ")
        if str(coord[0]) == str(name):
            area = float(coord[2])
    f.close()
    return area
                                                


if __name__ == '__main__':  



    ds = str(sys.argv[1]).replace('/','')
    path1 = '/store/caf/user/ccmuon/RPC/GlobalRuns/' + ds + '/' + str(sys.argv[2]) + '/noise'
    RootFile=TFile.Open('rfio:/castor/cern.ch/cms' + path1 + '/Merge_Noise.root?svcClass=cmscafuser')
    RootOut=TFile.Open(str(sys.argv[2]) + '_final.root',"RECREATE")
    wheels = ['W-2','W-1','W+0','W+1','W+2',]
    sectors = ['S04','S05','S06','S07','S08','S09','S10','S11','S12','S01','S02','S03']
    title2 = 'wheels_summary_' + str(sys.argv[1])
    plot2 = TH1F(title2,title2,5,0,5)
    bin2 = 1
    timehist = RootFile.FindObjectAny('Timeperbin')
    for item in wheels:
        cont2 = 0
        ncont2 = 0
        title1 = str(item) + '_summary'
        titlel = str(item) + '_layer_summary'
        plotl = TH1F(titlel,titlel,4,0,4)
        plot1 = TH1F(title1,title1,12,0,12)
        bin1 = 1
        contl1 = 0
        ncontl1 = 0
        contl2 = 0
        ncontl2 = 0
        contl3 = 0
        ncontl3 = 0
        contl4 = 0
        ncontl4 = 0
        for ob in sectors:
            cont1 = 0
            ncont1 = 0
            if(ob == 'S04' or ob == 'S10'):
                bin = 1
                if(ob=='S04'):
                    title = str(item)+'_Far_Side'
                else:
                    title = str(item)+'_Near_Side'
                plot = TH1F(title,title,110,0,110)
            histname = str(item)+'_'+str(ob)
            
            histo = RootFile.FindObjectAny(histname)
            NumBins = histo.GetYaxis().GetNbins()
            for i in range(NumBins):
                binname = histo.GetYaxis().GetBinLabel(i+1)
                proy = histo.ProjectionX(binname,i+1,i+1)
                pnumbins = proy.GetXaxis().GetNbins()
                cont = 0
                ncont = 0
                for j in range(pnumbins):
                    
                    if timehist.GetBinContent(j+1) != 0 : 
                        cont = cont + proy.GetBinContent(j+1)*1000000000/175/timehist.GetBinContent(j+1)
                        ncont = ncont + 1
                        cont1 = cont1 + proy.GetBinContent(j+1)*1000000000/175/timehist.GetBinContent(j+1)
                        ncont1 = ncont1 + 1
                        cont2 = cont2 + proy.GetBinContent(j+1)*1000000000/175/timehist.GetBinContent(j+1)
                        ncont2 = ncont2 + 1
    
                        if binname[6] == '1':
                            contl1 = contl1 + proy.GetBinContent(j+1)*1000000000/175/timehist.GetBinContent(j+1)
                            ncontl1 = ncontl1 + 1
                        else:
                            if binname[6] == '2':
                                contl2 = contl2 + proy.GetBinContent(j+1)*1000000000/175/timehist.GetBinContent(j+1)
                                ncontl2 = ncontl2 + 1
                            else:
                                if binname[6] == '3':
                                    contl3 = contl3 + proy.GetBinContent(j+1)*1000000000/175/timehist.GetBinContent(j+1)
                                    ncontl3 = ncontl3 + 1
                                else:
                                    if binname[6] == '4':
                                        contl4 = contl4 + proy.GetBinContent(j+1)*1000000000/175/timehist.GetBinContent(j+1)
                                        ncontl4 = ncontl4 + 1
                if ncont == 0 :
                    plot.GetXaxis().SetBinLabel(bin,binname)
                    plot.SetBinContent(bin,0)
                else:
                    if float(findArea(binname)) > 0 :
                        plot.GetXaxis().SetBinLabel(bin,binname)
                        plot.SetBinContent(bin,cont/ncont/float(findArea(binname)))
                        print 'value ' + str(cont/ncont/float(findArea(binname)))
                        plot.SetBinError(bin,cont/ncont/float(findArea(binname))/sqrt(ncont))
                        print 'error ' + str(cont/ncont/float(findArea(binname))/sqrt(ncont))
                bin = bin + 1
                plot.GetXaxis().SetLabelSize(0.03)
                plot.GetYaxis().SetTitle('Hz')
            if(ob == 'S09' or ob == 'S03'):
                plot.GetXaxis().LabelsOption("V")
                gStyle.SetOptStat(0)
                if(RootOut.cd()):
                   plot.Write()
            if ncont1 == 0:
                plot1.GetXaxis().SetBinLabel(bin1,str(item)+'_'+str(ob))
                plot1.SetBinContent(bin1,0)
            else:
                plot1.GetXaxis().SetBinLabel(bin1,str(item)+'_'+str(ob))
                plot1.SetBinContent(bin1,cont1/ncont1)
                plot1.SetBinError(bin1,sqrt(ncont1))
            bin1 = bin1 +1    
        plot1.GetXaxis().LabelsOption("V")
        plot1.GetXaxis().SetLabelSize(0.03)
        plot1.GetYaxis().SetTitle('Hz')
        if(RootOut.cd()):
            plot1.Write()
        if ncont2 == 0:
            plot2.GetXaxis().SetBinLabel(bin2,str(item))
            plot2.SetBinContent(bin2,0)
            bin2 = bin2 + 1
        else:
            plot2.GetXaxis().SetBinLabel(bin2,str(item))
            plot2.SetBinContent(bin2,cont2/ncont2)
            plot2.SetBinError(bin2,sqrt(ncont2))
            bin2 = bin2 +1
        if ncontl1 == 0:
            plotl.GetXaxis().SetBinLabel(1,'Layer 1')
            plotl.SetBinContent(1,0)
        else:
            plotl.GetXaxis().SetBinLabel(1,'Layer 1')
            plotl.SetBinContent(1,contl1/ncontl1)
            plotl.SetBinError(bin1,sqrt(ncontl1))
        if ncontl2 == 0:
            plotl.GetXaxis().SetBinLabel(2,'Layer 2')
            plotl.SetBinContent(2,0)
        else:
            plotl.GetXaxis().SetBinLabel(2,'Layer 2')
            plotl.SetBinContent(2,contl2/ncontl2)
            plotl.SetBinError(2,sqrt(ncontl2))
        if ncontl3 == 0:
            plotl.GetXaxis().SetBinLabel(3,'Layer 3')
            plotl.SetBinContent(3,0)
        else:
            plotl.GetXaxis().SetBinLabel(3,'Layer 3')
            plotl.SetBinContent(3,contl3/ncontl3)
            plotl.SetBinError(3,sqrt(ncontl3))
        if ncontl4 == 0:
            plotl.GetXaxis().SetBinLabel(4,'Layer 4')
            plotl.SetBinContent(4,0)
        else:
            plotl.GetXaxis().SetBinLabel(4,'Layer 4')
            plotl.SetBinContent(4,contl4/ncontl4)
            plotl.SetBinError(4,sqrt(ncontl4))
        plotl.GetYaxis().SetTitle('Hz')
        if(RootOut.cd()):
            plotl.Write()
    plot2.GetYaxis().SetTitle('Hz')



    wheels = ['RE-3','RE-2','RE-1','RE+1','RE+2','RE+3']
    disk = ['R2','R3']
    cham = ['A','B','C']
    sectors = ['CH13','CH14','CH15','CH16','CH17','CH18','CH19','CH20','CH21','CH22','CH23','CH24','CH25','CH26','CH27','CH28','CH29','CH30','CH31','CH32','CH33','CH34','CH35','CH36','CH01','CH02','CH03','CH04','CH05','CH06','CH07','CH08','CH09','CH10','CH11','CH12']
    title2 = 'wheels_summary_' + str(sys.argv[1])
    plot2 = TH1F(title2,title2,5,0,5)
    bin2 = 1
    timehist = RootFile.FindObjectAny('Timeperbin')
    for item in wheels:
        cont2 = 0
        ncont2 = 0
        title1 = str(item) + '_summary'
        titlel = str(item) + '_layer_summary'
        plotl = TH1F(titlel,titlel,4,0,4)
        plot1 = TH1F(title1,title1,12,0,12)
        bin1 = 1
        contl1 = 0
        ncontl1 = 0
        contl2 = 0
        ncontl2 = 0
        contl3 = 0
        ncontl3 = 0
        contl4 = 0
        ncontl4 = 0
        for  r in disk:
         for c in cham:   
          for ob in sectors:
            cont1 = 0
            ncont1 = 0
            if(ob == 'CH13' or ob == 'CH31'):
                bin = 1
                if(ob=='CH13'):
                    title = str(item)+'_Far_Side'
                else:
                    title = str(item)+'_Near_Side'
                plot = TH1F(title,title,110,0,110)
            histname = str(item)+'_'+str(r)+'_'+str(ob)+'_'+str(c)
            
            histo = RootFile.FindObjectAny(histname)
            NumBins = histo.GetYaxis().GetNbins()
            for i in range(NumBins):
                binname = histo.GetYaxis().GetBinLabel(i+1)
                proy = histo.ProjectionX(binname,i+1,i+1)
                pnumbins = proy.GetXaxis().GetNbins()
                cont = 0
                ncont = 0
                for j in range(pnumbins):
                    
                    if timehist.GetBinContent(j+1) != 0 : 
                        cont = cont + proy.GetBinContent(j+1)*1000000000/175/timehist.GetBinContent(j+1)
                        ncont = ncont + 1
                        cont1 = cont1 + proy.GetBinContent(j+1)*1000000000/175/timehist.GetBinContent(j+1)
                        ncont1 = ncont1 + 1
                        cont2 = cont2 + proy.GetBinContent(j+1)*1000000000/175/timehist.GetBinContent(j+1)
                        ncont2 = ncont2 + 1
    
                        if binname[6] == '1':
                            contl1 = contl1 + proy.GetBinContent(j+1)*1000000000/175/timehist.GetBinContent(j+1)
                            ncontl1 = ncontl1 + 1
                        else:
                            if binname[6] == '2':
                                contl2 = contl2 + proy.GetBinContent(j+1)*1000000000/175/timehist.GetBinContent(j+1)
                                ncontl2 = ncontl2 + 1
                            else:
                                if binname[6] == '3':
                                    contl3 = contl3 + proy.GetBinContent(j+1)*1000000000/175/timehist.GetBinContent(j+1)
                                    ncontl3 = ncontl3 + 1
                                else:
                                    if binname[6] == '4':
                                        contl4 = contl4 + proy.GetBinContent(j+1)*1000000000/175/timehist.GetBinContent(j+1)
                                        ncontl4 = ncontl4 + 1
                if ncont == 0 :
                    plot.GetXaxis().SetBinLabel(bin,binname)
                    plot.SetBinContent(bin,0)
                else:
                    if float(findArea(binname)) > 0 :
                        plot.GetXaxis().SetBinLabel(bin,binname)
                        plot.SetBinContent(bin,cont/ncont/float(findArea(binname)))
                        print 'value ' + str(cont/ncont/float(findArea(binname)))
                        plot.SetBinError(bin,cont/ncont/float(findArea(binname))/sqrt(ncont))
                        print 'error ' + str(cont/ncont/float(findArea(binname))/sqrt(ncont))
                bin = bin + 1
                plot.GetXaxis().SetLabelSize(0.03)
                plot.GetYaxis().SetTitle('Hz')
            if(ob == 'CH12' or ob == 'CH30'):
                plot.GetXaxis().LabelsOption("V")
                gStyle.SetOptStat(0)
                if(RootOut.cd()):
                   plot.Write()
            if ncont1 == 0:
                plot1.GetXaxis().SetBinLabel(bin1,str(item)+'_'+str(ob))
                plot1.SetBinContent(bin1,0)
            else:
                plot1.GetXaxis().SetBinLabel(bin1,str(item)+'_'+str(ob))
                plot1.SetBinContent(bin1,cont1/ncont1)
                plot1.SetBinError(bin1,sqrt(ncont1))
            bin1 = bin1 +1    
        plot1.GetXaxis().LabelsOption("V")
        plot1.GetXaxis().SetLabelSize(0.03)
        plot1.GetYaxis().SetTitle('Hz')
        if(RootOut.cd()):
            plot1.Write()
        if ncont2 == 0:
            plot2.GetXaxis().SetBinLabel(bin2,str(item))
            plot2.SetBinContent(bin2,0)
            bin2 = bin2 + 1
        else:
            plot2.GetXaxis().SetBinLabel(bin2,str(item))
            plot2.SetBinContent(bin2,cont2/ncont2)
            plot2.SetBinError(bin2,sqrt(ncont2))
            bin2 = bin2 +1
        if ncontl1 == 0:
            plotl.GetXaxis().SetBinLabel(1,'Layer 1')
            plotl.SetBinContent(1,0)
        else:
            plotl.GetXaxis().SetBinLabel(1,'Layer 1')
            plotl.SetBinContent(1,contl1/ncontl1)
            plotl.SetBinError(bin1,sqrt(ncontl1))
        if ncontl2 == 0:
            plotl.GetXaxis().SetBinLabel(2,'Layer 2')
            plotl.SetBinContent(2,0)
        else:
            plotl.GetXaxis().SetBinLabel(2,'Layer 2')
            plotl.SetBinContent(2,contl2/ncontl2)
            plotl.SetBinError(2,sqrt(ncontl2))
        if ncontl3 == 0:
            plotl.GetXaxis().SetBinLabel(3,'Layer 3')
            plotl.SetBinContent(3,0)
        else:
            plotl.GetXaxis().SetBinLabel(3,'Layer 3')
            plotl.SetBinContent(3,contl3/ncontl3)
            plotl.SetBinError(3,sqrt(ncontl3))
        if ncontl4 == 0:
            plotl.GetXaxis().SetBinLabel(4,'Layer 4')
            plotl.SetBinContent(4,0)
        else:
            plotl.GetXaxis().SetBinLabel(4,'Layer 4')
            plotl.SetBinContent(4,contl4/ncontl4)
            plotl.SetBinError(4,sqrt(ncontl4))
        plotl.GetYaxis().SetTitle('Hz')
        if(RootOut.cd()):
            plotl.Write()
    plot2.GetYaxis().SetTitle('Hz')

    
    if(RootOut.cd()):
        plot2.Write()
