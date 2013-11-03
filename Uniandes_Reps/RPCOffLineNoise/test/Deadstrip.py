import os
from sys import argv
from ROOT import *

if __name__ == '__main__':  

    print 'ahi vamos'

    RootFile=TFile.Open("RPCDQM_97030_Merged.root")
    file=open("rolls.txt")

    print "Creating a text file with the write() method."
    text_file = open("output_rolls.txt", "w")
   
    while 1:
        line = file.readline()
        if not line: break
        #process(line)
        print str(line)
        histname = 'Occupancy_' + line
        print histname
        histo = RootFile.FindObjectAny(histname)
        NumBins = histo.GetXaxis().GetNbins()
        entries = histo.GetEntries()
        deadstrips = []
        for i in range(NumBins):
            print str(i)
            #text_file.write("Line 1\n")
     
    file.close()
    text_file.close()
