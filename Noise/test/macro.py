import commands
import sys, os, string, fileinput
from ROOT import TCanvas,TH1F,TH2F,gROOT,TFile,gDirectory,TTree
from time import ctime
#from array import array

#
#main
#


if __name__ == "__main__":
    
    RootFile=TFile( 'noise.root' )
    T=RootFile.Get('RPCNoise')

    nen = T.GetEntries()
    print 'eventos ' + str(nen)
    min = T.GetMinimum('tempo')
    max = T.GetMaximum('tempo')
    binnum = max-min

    occtot = TH1F('Occtot', 'Occupancy for all RPCs',int(binnum), 0, int(binnum)-1);
    occbarrel =TH1F('Occbarrel','Occupancy for Barrel',int(binnum),0,int(binnum)-1);
    occEnd =TH1F('OccEndcapForward','Occupancy for Endcap',int(binnum),0,int(binnum)-1);    
    occwheelbarrel =TH2F('occwheelbarrel','Global Barrel Plot',int(binnum),0,int(binnum)-1,5,0,5)
    occdiskendcap =TH2F('occdiskendcap','Global Endcap Plot',int(binnum),0,int(binnum)-1,6,0,6)
    occbrlend =TH2F('occbarlend','Global Endcap and Barrel',int(binnum),0,int(binnum)-1,3,0,3)

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
        
        print T.GetEntry(i)
        occtot.Fill(int(T.tempo-min),T.ndigi)
        nompart = T.nomchamb.split('_')
        
        if(cmp(nompart[0],'W+1')==0 or cmp(nompart[0],'W+2')==0 or cmp(nompart[0],'W+0')==0 or cmp(nompart[0],'W-1')==0 or cmp(nompart[0],'W-2')==0):
            occbarrel.Fill(int(T.tempo-min),T.ndigi)
            if(cmp(nompart[0],'W+1')==0):
                occbrlend.Fill(int(T.tempo-min),2,T.ndigi)
                occwheelbarrel.Fill(int(T.tempo-min),4,T.ndigi)
            elif (cmp(nompart[0],'W+2')==0):
                occbrlend.Fill(int(T.tempo-min),2,T.ndigi)
                occwheelbarrel.Fill(int(T.tempo-min),5,T.ndigi)
            elif (cmp(nompart[0],'W+0')==0):
                occbrlend.Fill(int(T.tempo-min),2,T.ndigi)
                occwheelbarrel.Fill(int(T.tempo-min),3,T.ndigi)
            elif (cmp(nompart[0],'W-1')==0):    
                occbrlend.Fill(int(T.tempo-min),2,T.ndigi)
                occwheelbarrel.Fill(int(T.tempo-min),2,T.ndigi)
            elif (cmp(nompart[0],'W-2')==0):        
                occbrlend.Fill(int(T.tempo-min),2,T.ndigi)
                occwheelbarrel.Fill(int(T.tempo-min),1,T.ndigi)
                
        elif(cmp(nompart[0],'D+1')==0 or cmp(nompart[0],'D+2')==0 or cmp(nompart[0],'D+3')==0 or
             cmp(nompart[0],'D-1')==0 or cmp(nompart[0],'D-2')==0 or cmp(nompart[0],'D-3')==0):
            occEnd.Fill(int(T.tempo-min)+1,T.ndigi)
            if(cmp(nompart[0],'D+3')==0):
                occbrlend.Fill(int(T.tempo-min),1,T.ndigi)
                occdiskendcap.Fill(int(T.tempo-min),6,T.ndigi)
            elif (cmp(nompart[0],'D+2')==0):
                occbrlend.Fill(int(T.tempo-min),1,T.ndigi)
                occdiskendcap.Fill(int(T.tempo-min),5,T.ndigi)
            elif(cmp(nompart[0],'D+1')==0):
                occbrlend.Fill(int(T.tempo-min),1,T.ndigi)
                occdiskendcap.Fill(int(T.tempo-min),4,T.ndigi)
            elif(cmp(nompart[0],'D-1')==0):
                occbrlend.Fill(int(T.tempo-min),3,T.ndigi)
                occdiskendcap.Fill(int(T.tempo-min),3,T.ndigi)
            elif(cmp(nompart[0],'D-2')==0):
                occbrlend.Fill(int(T.tempo-min),3,T.ndigi)
                occdiskendcap.Fill(int(T.tempo-min),2,T.ndigi)
            elif(cmp(nompart[0],'D-3')==0):
                occbrlend.Fill(int(T.tempo-min),3,T.ndigi)
                occdiskendcap.Fill(int(T.tempo-min),1,T.ndigi)
                                                                                            
            
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

    occbrlend.SetOption('colz')
    occbrlend.GetXaxis().LabelsOption('v')
    occdiskendcap.SetOption('colz')
    occdiskendcap.GetXaxis().LabelsOption('v')
    occwheelbarrel.SetOption('colz')
    occwheelbarrel.GetXaxis().LabelsOption('v')
            
    Noisefile = TFile('RPCNoiseout.root','RECREATE')
    occtot.Write()
    occbarrel.Write()
    occEnd.Write()
    occbrlend.Write()
    occdiskendcap.Write()
    occwheelbarrel.Write()
    Noisefile.Close()

