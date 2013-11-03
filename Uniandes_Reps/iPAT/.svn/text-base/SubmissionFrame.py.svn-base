#! /usr/bin/env python   

from Tkinter import *
from quitter import Quitter
import os
from tkMessageBox import *

class Demo(Frame):
##    def __init__(self, options, parent=None):
    def __init__(self, parent=None):
        my_window = Toplevel()
        Frame.__init__(self, my_window)
        self.pack(expand=YES, fill=BOTH)
        Label(self, text="Submit jobs for Run Number").pack()

        self.fields = 'CMSSW Release', 'Dataset', 'Run Number', 'Number of jobs to submit', 'Starting from job number'
        self.ents = self.makeform(self, self.fields)
        self.bind('<Return>', (lambda event: self.fetch(self.ents)))   
        self.btn = Button(self, text='Submit', 
                    command= (lambda: self.fetch(self.ents))).pack(side=TOP)

        self.var1 = IntVar()
        self.var2 = IntVar()
        self.var3 = IntVar()
        self.var4 = IntVar()
        self.var5 = IntVar()
        self.var6 = IntVar()

        self.var3.set(1)
        self.var4.set(1)
        self.var6.set(1)

        
        self.ck1 = Checkbutton(self,
                               text='Eff STAMuon',    
                               variable=self.var1,
                               command=(lambda: self.report() )).pack(side=LEFT)
        self.ck2 = Checkbutton(self,
                               text='Eff DT',    
                               variable=self.var2,
                               command=(lambda: self.report() )).pack(side=LEFT)

        self.ck3 = Checkbutton(self,
                               text='DQM',
                               variable=self.var3,
                               command=(lambda: self.report() )).pack(side=LEFT)

        self.ck4 = Checkbutton(self,
                               text='Noise',    
                               variable=self.var4,
                               command=(lambda: self.report() )).pack(side=LEFT)

        self.ck5 = Checkbutton(self,
                               text='Trigger Monitoring',    
                               variable=self.var5,
                               command=(lambda: self.report() )).pack(side=LEFT)

        self.ck6 = Checkbutton(self,
                               text='Trigger Eff',    
                               variable=self.var6,
                               command=(lambda: self.report() )).pack(side=LEFT)        

    def report(self):
        pass
##        for var in self.vars:
##            print var.get(),   # current toggle settings: 1 or 0
##        print



    def fetch(self,entries):
        try:
            inp = []
            for entry in entries:
                inp.append(entry.get())

            cmd = './RunJobForAGivenRunNumberNew.py ' + str(inp[0]) + ' ' + str(inp[1]) + ' ' + str(inp[2]) + ' ' + str(inp[3]) + ' ' + str(inp[4]) + ' '+str(self.var1.get())+ ' '+str(self.var2.get())+ ' '+str(self.var3.get())+ ' '+str(self.var4.get())+ ' '+str(self.var5.get()) + ' '+str(self.var6.get()) + ' 0 0 0 0 0 0 0 0 0 0 0'
            
            os.system(cmd)
            me = [item[:-1] for item in os.popen('whoami')]
            prev = [item[:-1] for item in os.popen('echo $HOME')]
            dir = prev[0] + '/scratch0/' + str(inp[2])
            os.system('mkdir ' + dir)
            os.system('cp jobtemplate ' + dir + '/Shifter_Job_'+str(inp[2])+'.job ')
            os.system('chmod a+x ' + dir + '/Shifter_Job_'+str(inp[2])+'.job ')
            os.system('replace "----RUN----" "'+str(inp[2])+'" -- ' + dir + '/Shifter_Job_'+str(inp[2])+'.job ')
            os.system('replace "----RELEASE----" "'+str(inp[0])+'" -- ' + dir + '/Shifter_Job_'+str(inp[2])+'.job ')
            os.system('replace "----DATASET----" "'+str(inp[1])+'" -- ' + dir + '/Shifter_Job_'+str(inp[2])+'.job ')
#            os.chdir(dir)
#            os.system('bsub -q cmscaf1nw '+dir+'/Shifter_Job_'+str(inp[2])+'.job ')

#            os.chdir(prev[0])
            return 1
        except ValueError:
            tkMessageBox.showwarning(
                "Wrong input format",
                "Please insert the right input:"
                "Release: CMSSW_2_2_9"
                "Dataset: /Cosmics/Commissioning08-CRUZET4_v1/RECO"
                "Run Number: 58555"
                "Run of job to submit: 58555"
                )
            return 0


    def makeform(self,root, fields):
        entries = []
        i = 0
#       default = ['CMSSW_2_1_10','/Cosmics/Commissioning08_CRAFT_ALL_V4_ReReco-v1/RECO','70195','1','0']
        default = ['CMSSW_3_2_8','/Cosmics/Commissioning09-PromptReco-v9/RECO','118367','-1','0']
        for field in fields:
            row = Frame(root)                           # make a new row
            lab = Label(row, width=25, text=field)       # add label, entry
            ent = Entry(row)
            ent.insert(0, default[i])
            row.pack(side=TOP, fill=X)                  # pack row on top
            lab.pack(side=LEFT)
            ent.pack(side=RIGHT, expand=YES, fill=X)    # grow horizontal
            entries.append(ent)
            i = i + 1
        return entries
     
if __name__ == '__main__': Demo().mainloop()

