import commands
from Tkinter import *
import sys, os, string, fileinput
from ROOT import TCanvas,TH1F,TH2F,gROOT,TFile,gDirectory,TTree,gStyle,TStyle
from time import ctime
#from array import array


def SetStyle():
    global defa
    defa = TStyle("defa1","defa2")
    defa.SetPalette(1)
    defa.SetOptStat(0)
    gROOT.SetStyle("defa")
    return 


#
#main
#


if __name__ == "__main__":

    ds = str(sys.argv[1]).replace('/','')
    Root = Tk()
    
#    RootFile=TFile::Open('rfio:/castor/cern.ch/user/c/ccmuon/RPC/GlobalRuns/' + sys.argv[1] + '/' + sys.argv[2] + '/noise/merge_Noise.root' )
    RootFile=TFile(sys.argv[1])
    T=RootFile.Get('RPCNoise')

    SetStyle()
    gStyle.SetOptStat(0)
    
    nen = T.GetEntries()
    print 'eventos ' + str(nen)
    min = T.GetMinimum('tempo')
    max = T.GetMaximum('tempo')
    binnum = max-min

    wheels = ['W-2','W-1','W+0','W+1','W+2']
    sec = ['S01','S02','S03','S04','S05','S06','S07','S08','S09','S10','S11','S12']
    rbs = ['RB1in','RB1out','RB2in','RB2out','RB3+','RB3-','RB4+','RB4-','RB4++','RB4+-','RB4--','RB4-+']
    dir = ['Forward','Backward','Middle']
    disks = ['D-3','D-2','D-1','D+1','D+2','D+3']
    RES = ['RE2','RE3']
    secd = ['S01','S02','S03','S04','S05','S06']

    occtot = TH1F('Occtot', 'Occupancy for all RPCs',int(binnum), 0, int(binnum)-1);
    occbarrel =TH1F('Occbarrel','Occupancy for Barrel',int(binnum),0,int(binnum)-1);
    occEnd =TH1F('OccEndcapForward','Occupancy for Endcap',int(binnum),0,int(binnum)-1);    
    occwheelbarrel =TH2F('occwheelbarrel','Global Barrel Plot',int(binnum),0,int(binnum)-1,5,0,5)
    occdiskendcap =TH2F('occdiskendcap','Global Endcap Plot',int(binnum),0,int(binnum)-1,6,0,6)
    occbrlend =TH2F('occbarlend','Global Endcap and Barrel',int(binnum),0,int(binnum)-1,3,0,3)

    wheelhis = []
    diskhis = []
    chamwheelhis = []
    chamdiskhis = []
    
    for w in wheels:
        histowheel = TH2F( w,'Barrel ' + w + ' Noise',int(binnum),0,int(binnum),12,0,12)
        cont =1
        for s in sec:
            histowheel.GetYaxis().SetBinLabel(cont,w + '_' + s)
            cont = cont + 1
        wheelhis.append(histowheel)

    for w in wheels:
        for s in sec:
            if (cmp(s,'S04') == 0):
                chamwheel = TH2F(w + '_' + s ,w + ' ' + s + ' Noise',int(binnum),0,int(binnum),21,0,21)
            else:
                chamwheel = TH2F(w + '_' + s ,w + ' ' + s + ' Noise',int(binnum),0,int(binnum),17,0,17)
            cont = 1    
            for r in rbs:
                for j in dir:
                    if((cmp(r,'RB4++')==0 or cmp(r,'RB4+-')==0 or cmp(r,'RB4--')==0 or cmp(r,'RB4-+')==0) and cmp(s,'S04')!=0):
                        break
                    elif(cmp(s,'S04')==0 and (cmp(r,'RB4+')==0 or cmp(r,'RB4-')==0)):
                        break
                    elif((cmp(r,'RB2in')==0 and (cmp(w,'W+2')==0 or cmp(w,'W-2')==0)) and cmp(j,'Middle')==0):
                        break
                    elif((cmp(r,'RB2out')==0 and (cmp(w,'W+0')==0 or cmp(w,'W+1')==0 or cmp(w,'W-1')==0)) and cmp(j,'Middle')==0):
                        break
                    elif((cmp(r,'RB1in')==0 or cmp(r,'RB1out')==0 or cmp(r,'RB3+')==0 or cmp(r,'RB3-')==0 or cmp(r,'RB4+')==0 or cmp(r,'RB4-')==0 or
                        cmp(r,'RB4++')==0 or cmp(r,'RB4+-')==0 or cmp(r,'RB4--')==0 or cmp(r,'RB4-+')==0) and cmp(j,'Middle')==0):
                        break
                    else:
                        chamwheel.GetYaxis().SetBinLabel(cont,w + '_' + r + '_' + s + '_' + j )
                        cont = cont + 1
            chamwheelhis.append(chamwheel)                
                
            

    for d in disks:
        histodisk = TH2F(d,'Disk ' + d + ' Noise',int(binnum),0,int(binnum),12,0,12)
        cont = 1
        for r in RES:
            for s in secd:
                histodisk.GetYaxis().SetBinLabel(cont,d + '_' + r + '_' + s)
                cont = cont + 1
        diskhis.append(histodisk)        

    occwheelbarrel.GetYaxis().SetBinLabel(1,'W-2')
    occwheelbarrel.GetYaxis().SetBinLabel(2,'W-1')
    occwheelbarrel.GetYaxis().SetBinLabel(3,'W+0')
    occwheelbarrel.GetYaxis().SetBinLabel(4,'W+1')
    occwheelbarrel.GetYaxis().SetBinLabel(5,'W+2')

    occdiskendcap.GetYaxis().SetBinLabel(1,'D-3')
    occdiskendcap.GetYaxis().SetBinLabel(2,'D-2')
    occdiskendcap.GetYaxis().SetBinLabel(3,'D-1')
    occdiskendcap.GetYaxis().SetBinLabel(4,'D+1')
    occdiskendcap.GetYaxis().SetBinLabel(5,'D+2')
    occdiskendcap.GetYaxis().SetBinLabel(6,'D+3')

    occbrlend.GetYaxis().SetBinLabel(1,'E+')
    occbrlend.GetYaxis().SetBinLabel(2,'Barrel')
    occbrlend.GetYaxis().SetBinLabel(3,'E-')

    for i in xrange(nen):
        
        z = T.GetEntry(i)
        occtot.Fill(int(T.tempo-min),T.ndigi)
        nompart = T.nomchamb.split('_')
        for w in wheelhis:
            for k in range(12):
                nom = w.GetYaxis().GetBinLabel(k+1)
                nom1 = nom.split('_')
                if (cmp(nom1[0],nompart[0])==0 and cmp(nompart[2],nom1[1])==0):
                    w.Fill(int(T.tempo-min),k,T.ndigi)

        for w in chamwheelhis:
            for k in range(w.GetYaxis().GetNbins()):
                nom = w.GetYaxis().GetBinLabel(k+1)
                nom1 = nom.split('_')
                if (cmp(nom1[0],nompart[0])==0 and cmp(nom1[2],nompart[2])==0 and cmp(nom1[1],nompart[1])==0 and cmp(nompart[3],nom1[3])==0):
                    w.Fill(int(T.tempo-min),k,T.ndigi)
                                                                        
                    
        for d in diskhis:
            for k in range(12):
                nom = d.GetYaxis().GetBinLabel(k+1)
                nom1= nom.split('_')
                if (cmp(nom1[0],nompart[0])==0 and cmp(nompart[1],nom1[1])==0):
                    nompart1 = nompart[2].split('S')
                    if(0<=k<=5):
                        l=k
                    else:
                        l=k-6
                    mink = 2 + 6*l
                    maxk = mink + 5                    
                    if(mink<=int(nompart1[1])<=maxk):
                        d.Fill(int(T.tempo-min),k,T.ndigi)
                    elif (int(nompart1[1])==1):
                        d.Fill(int(T.tempo-min),5,T.ndigi)
                
        
        
        if(cmp(nompart[0],'W+1')==0 or cmp(nompart[0],'W+2')==0 or cmp(nompart[0],'W+0')==0 or cmp(nompart[0],'W-1')==0 or cmp(nompart[0],'W-2')==0):
            occbarrel.Fill(int(T.tempo-min),T.ndigi)
            if(cmp(nompart[0],'W+1')==0):
                occbrlend.Fill(int(T.tempo-min),1,T.ndigi)
                occwheelbarrel.Fill(int(T.tempo-min),3,T.ndigi)
            elif (cmp(nompart[0],'W+2')==0):
                occbrlend.Fill(int(T.tempo-min),1,T.ndigi)
                occwheelbarrel.Fill(int(T.tempo-min),4,T.ndigi)
            elif (cmp(nompart[0],'W+0')==0):
                occbrlend.Fill(int(T.tempo-min),1,T.ndigi)
                occwheelbarrel.Fill(int(T.tempo-min),2,T.ndigi)
            elif (cmp(nompart[0],'W-1')==0):    
                occbrlend.Fill(int(T.tempo-min),1,T.ndigi)
                occwheelbarrel.Fill(int(T.tempo-min),1,T.ndigi)
            elif (cmp(nompart[0],'W-2')==0):        
                occbrlend.Fill(int(T.tempo-min),1,T.ndigi)
                occwheelbarrel.Fill(int(T.tempo-min),0,T.ndigi)
                
        elif(cmp(nompart[0],'D+1')==0 or cmp(nompart[0],'D+2')==0 or cmp(nompart[0],'D+3')==0 or
             cmp(nompart[0],'D-1')==0 or cmp(nompart[0],'D-2')==0 or cmp(nompart[0],'D-3')==0):
            occEnd.Fill(int(T.tempo-min)+1,T.ndigi)
            if(cmp(nompart[0],'D+3')==0):
                occbrlend.Fill(int(T.tempo-min),0,T.ndigi)
                occdiskendcap.Fill(int(T.tempo-min),5,T.ndigi)
            elif (cmp(nompart[0],'D+2')==0):
                occbrlend.Fill(int(T.tempo-min),0,T.ndigi)
                occdiskendcap.Fill(int(T.tempo-min),4,T.ndigi)
            elif(cmp(nompart[0],'D+1')==0):
                occbrlend.Fill(int(T.tempo-min),0,T.ndigi)
                occdiskendcap.Fill(int(T.tempo-min),3,T.ndigi)
            elif(cmp(nompart[0],'D-1')==0):
                occbrlend.Fill(int(T.tempo-min),2,T.ndigi)
                occdiskendcap.Fill(int(T.tempo-min),2,T.ndigi)
            elif(cmp(nompart[0],'D-2')==0):
                occbrlend.Fill(int(T.tempo-min),2,T.ndigi)
                occdiskendcap.Fill(int(T.tempo-min),1,T.ndigi)
            elif(cmp(nompart[0],'D-3')==0):
                occbrlend.Fill(int(T.tempo-min),2,T.ndigi)
                occdiskendcap.Fill(int(T.tempo-min),0,T.ndigi)
                                                                                            
            
    for i in range(0,int(binnum)):
        if(i%10==0):
            t=ctime(min+i)
            print t
            
            occtot.GetXaxis().SetBinLabel(i+1,t)
            occbarrel.GetXaxis().SetBinLabel(i+1,t)
            occEnd.GetXaxis().SetBinLabel(i+1,t)
            occbrlend.GetXaxis().SetBinLabel(i+1,t)
            occdiskendcap.GetXaxis().SetBinLabel(i+1,t)
            occwheelbarrel.GetXaxis().SetBinLabel(i+1,t)
            for j in wheelhis:
                j.GetXaxis().SetBinLabel(i+1,t)
            for j in diskhis:
                j.GetXaxis().SetBinLabel(i+1,t)
            for j in chamwheelhis:
                j.GetXaxis().SetBinLabel(i+1,t)

    occbrlend.SetOption('COLZ')
    occbrlend.GetXaxis().LabelsOption('v')
    occdiskendcap.SetOption('COLZ')
    occdiskendcap.GetXaxis().LabelsOption('v')
    occwheelbarrel.SetOption('COLZ')
    occwheelbarrel.GetXaxis().LabelsOption('v')

    for j in wheelhis:
        j.SetOption('COLZ')
        j.GetXaxis().LabelsOption('v')

    for j in diskhis:
        j.SetOption('COLZ')
        j.GetXaxis().LabelsOption('v')

    for j in chamwheelhis:
        j.SetOption('COLZ')
        j.GetXaxis().LabelsOption('v')

    canvas = TCanvas('c1','prueba',1)
    occwheelbarrel.Draw('COLZ')
    canvas.SaveAs('prueba.root')
#    Noisefile = TFile('RPCNoiseout_' + str(sys.argv[2]) +'.root','RECREATE')
    Noisefile = TFile('RPCNoiseout_' + '.root','RECREATE')
    occtot.Write()
    occbarrel.Write()
    occEnd.Write()
    occbrlend.Write()
    occdiskendcap.Write()
    occwheelbarrel.Write()

    for i in wheelhis:
        i.Write()

    for j in diskhis:
        j.Write()

    for i in chamwheelhis:
        i.Write()
        
    Noisefile.Close()
#    os.system('rfcp ' + 'RPCNoiseout_' + str(sys.argv[2]) +'.root /castor/cern.ch/user/c/ccmuon/RPC/GlobalRuns/' + sys.argv[1] + '/' + sys.argv[2] + '/noise/')
    print 'Done!!!!!!!!!!!'
    mainloop()
