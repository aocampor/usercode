#! /usr/bin/env python
from Tkinter import *
from quitter import Quitter
import os 
from sys import argv

import tkFileDialog 
import tkSimpleDialog
from tkFileDialog   import askopenfilename        # get standard dialogs
from DrawColWheel import DrawWheel
from slideShowNew import SlideShow
from StatusReportFrame import StatusReportFrame

from tkMessageBox import *

#from StatusReport import StatusReport

class Demo(Frame):
##    def __init__(self, options, parent=None):
    def __init__(self, parent=None):        
        my_window = Toplevel()
        Frame.__init__(self, my_window)
        self.pack(expand=YES, fill=BOTH)
        Label(self, text="RPC Prompt Analysis Tool",font=('times',15,'bold italic')).pack()

        self.bt1 = Button(self, text='Open and Load File', command=self.AskOpenFile).pack(side=TOP) ##, fill=BOTH)

        self.fields = ['DataSet','Run Number']
        self.ents = self.makeform(self, self.fields)
        self.FileName = ''
 

        self.bind('<Return>', (lambda event: self.fetch(self.ents)))   
        self.btn = Button(self, text='Load Root File', 
                    command= (lambda: self.fetch(self.ents))).pack(side=TOP)

        self.var = IntVar()
        self.ck = Checkbutton(self,
                         text='RFIO',    
                         variable=self.var,
                         command=(lambda: self.addRFIO())).pack(side=TOP)

        self.btn2 = Button(self, text='Save Status report', 
                    command= (lambda: self.statusReport(self.ents))).pack(side=TOP)

        self.btn3 = Button(self, text='Global Plots', 
                    command= (lambda: self.globalPlots(self.ents))).pack(side=TOP)



        demosBarrel = {
            'Wheel +2': lambda: self.selectDet(self.FileName,'W+2'),
            'Wheel +1': lambda: self.selectDet(self.FileName,'W+1'),
            'Wheel 0': lambda: self.selectDet(self.FileName,'W+0'),
            'Wheel -1': lambda: self.selectDet(self.FileName,'W-1'),
            'Wheel -2': lambda: self.selectDet(self.FileName,'W-2'),
            }

        demosEndCap = {
            'Disk -1': lambda: self.selectDetDisk(self.FileName,'RE-1'),
            'Disk -2': lambda: self.selectDetDisk(self.FileName,'RE-2'),
            'Disk -3': lambda: self.selectDetDisk(self.FileName,'RE-3'), 
            'Disk +1': lambda: self.selectDetDisk(self.FileName,'RE+1'),
            'Disk +2': lambda: self.selectDetDisk(self.FileName,'RE+2'),
            'Disk +3': lambda: self.selectDetDisk(self.FileName,'RE+3')
            }


        pos = [TOP,LEFT,RIGHT,LEFT,TOP]
        i = 0
        for (key, value) in demosBarrel.items():
            Button(self, text=key, command=value).pack(side=TOP, fill=BOTH)
            i += 1
            
        for (key, value) in demosEndCap.items():
            Button(self, text=key, command=value).pack(side=BOTTOM, fill=BOTH)

    def notdone(self):
        showerror('Missing file', 'The file selected does not exist')
        
    def makeform(self,root, fields):
        entries = []
        i = 0
        default = ['/Cosmics/Commissioning09-PromptReco-v9/RECO','118621']

        for field in fields:
            row = Frame(root)                           # make a new row
            lab = Label(row, width=10, text=field)       # add label, entry
            ent = Entry(row)
            ent.insert(0, default[i])
            row.pack(side=TOP, fill=X)                  # pack row on top
            lab.pack(side=LEFT)
            ent.pack(side=RIGHT, expand=YES, fill=X)    # grow horizontal
            entries.append(ent)
            i = i + 1
        return entries

    def addRFIO(self):
        pass

    def statusReport(self,entries):
        inp = []
        for entry in entries:
            inp.append(entry.get())
        ds = str(str(inp[0]).replace('/',"")).strip()

        StatusReportFrame(str(self.FileName),str(inp[0]),str(inp[1]))

##        cmd = './StatusReportFrame.py ' + str(self.FileName) +' '+ str(inp[0])+' '+str(inp[1])+'&'
##        os.system(cmd)

    def globalPlots(self,entries):
        inp = []
        for entry in entries:
            inp.append(entry.get())
        ds = str(str(inp[0]).replace('/',"")).strip()

        print inp[1]
        SlideShow(ds,str(inp[1]))
        
    def fetch(self,entries):
        filename = ''
        inp = []
        
        for entry in entries:
            inp.append(entry.get())

        me = [item[:-1] for item in os.popen('whoami')]
        print str(inp[1])
        tmpath = '/tmp/' + me[0] +'/' + str(inp[1])+'/'
        os.system('mkdir ' + tmpath)

        ds = str(str(inp[0]).replace('/',"")).strip()
        print ds
        if self.var.get() == 0:
            filename = '/tmp/'+ me[0] + '/'+ ds +'/'+str(inp[1])+'/root/Merge_tot_new.root'
            self.FileName = filename
        elif self.var.get() == 1:
            castorFile = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms/store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/root/Merge_tot_new.root')]
            castorFile1 = [item[:-1] for item in os.popen('rfdir /castor/cern.ch/cms/store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/root/Merge_DQM_SRPC.root')]
            noi = [item[:-1] for itme in os.popen('rfdir /castor/cern.ch/cms/store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/noise/'+str(inp[1])+'_final.root ')]



            if castorFile != []:
                os.system('cmsStageIn /store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/root/Merge_tot_new.root ' + tmpath)

                

                #      if(noi != [] and castorFile != []):
                #         os.system('cmsStageIn /store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/noise/'+str(inp[1])+'_final.root ' + tmpath)
                
                #                os.system('cmsStageIn /store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/noise/Merge_Strips_00.root ' + tmpath)
                #               os.system('cmsStageIn /store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/noise/Merge_Strips_01.root ' + tmpath)
                #              os.system('cmsStageIn /store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/noise/Merge_Strips_02.root ' + tmpath)
                #             os.system('cmsStageIn /store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/noise/Merge_Strips_0m1.root ' + tmpath)
                #            os.system('cmsStageIn /store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/noise/Merge_Strips_0m2.root ' + tmpath)
                #           
                #                os.system('cmsStageIn /store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/noise/Merge_Strips_11.root ' + tmpath)
                #               os.system('cmsStageIn /store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/noise/Merge_Strips_12.root ' + tmpath)
                #              os.system('cmsStageIn /store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/noise/Merge_Strips_13.root ' + tmpath)
                #             os.system('cmsStageIn /store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/noise/Merge_Strips_m11.root ' + tmpath)
                #            os.system('cmsStageIn /store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/noise/Merge_Strips_m12.root ' + tmpath)
                #           os.system('cmsStageIn /store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/noise/Merge_Strips_m13.root ' + tmpath)
                
                #        os.system('hadd Merge.root Merge_tot_new.root ' + str(inp[1]) + '_final.root ')
                #         os.system('mv Merge.root ' + tmpath)
                #        os.system('mv Merge_Strips_00.root '+ tmpath +  str(inp[1]) + '_00.root ')
                #       os.system('mv Merge_Strips_01.root '+ tmpath +  str(inp[1]) + '_01.root ')
                #      os.system('mv Merge_Strips_02.root '+ tmpath +  str(inp[1]) + '_02.root ')
                #     os.system('mv Merge_Strips_0m1.root '+ tmpath + str(inp[1]) + '_0m1.root ')
                #    os.system('mv Merge_Strips_0m2.root '+ tmpath + str(inp[1]) + '_0m2.root ')
                
                #   os.system('mv Merge_Strips_11.root '+ tmpath +  str(inp[1]) + '_11.root ')
                #  os.system('mv Merge_Strips_12.root '+ tmpath +  str(inp[1]) + '_12.root ')
                #                os.system('mv Merge_Strips_13.root '+ tmpath +  str(inp[1]) + '_13.root ')
                #               os.system('mv Merge_Strips_m11.root '+ tmpath + str(inp[1]) + '_m11.root ')
                #              os.system('mv Merge_Strips_m12.root '+ tmpath + str(inp[1]) + '_m12.root ')
                #             os.system('mv Merge_Strips_m13.root '+ tmpath + str(inp[1]) + '_m13.root ')
                
                #            os.system('rm -f '+ str(inp[1]) + '_final.root ')
                #           os.system('rm -f Merge_tot_new.root')
                
                #        self.FileName = tmpath + 'Merge.root'
                #   elif noi == [] and castorFile != []:
                os.system('mv Merge_tot_new.root ' + tmpath)
                self.FileName = tmpath + 'Merge_tot_new.root'
            elif (castorFile1 != []):
                os.system('cmsStageIn /store/caf/user/ccmuon/RPC/GlobalRuns/'+ds +'/'+str(inp[1])+'/root/Merge_DQM_SRPC.root ' + tmpath)
                os.system('mv Merge_DQM_SRPC.root ' + tmpath)
                self.FileName = tmpath + 'Merge_DQM_SRPC.root'                
            else:
                self.notdone()
                
    def AskOpenFile(self, title='Choose File', mode='rb', initialdir='.', filetypes=None):
        if filetypes==None:
            filetypes = [
                ('Text File','*.txt'),
                ('Data File','*.dat'),
                ('Output File','*.out'),
                ('Any File','*.*')]
        
        fileobj = askopenfilename(filetypes=[("all files", "*")])
        self.FileName = str(fileobj) # <-- an opened file, or the value None


    def selectDet(self,file_name,wheel):
        cmd = './DrawColWheel.py ' + str(file_name) + ' ' + str(wheel) +'&'
        os.system(cmd)


    def selectDetDisk(self,file_name,wheel):
        cmd = './DrawColDisk.py ' + str(file_name) + ' ' + str(wheel) +'&'
        os.system(cmd)

                        
if __name__ == '__main__': Demo().mainloop()

