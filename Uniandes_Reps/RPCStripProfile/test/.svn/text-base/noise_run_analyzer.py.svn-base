#! /usr/bin/env python
from Tkinter import *
import commands
import sys, os, string, fileinput
from sys import argv
from ROOT import *

if __name__ == '__main__':

    run = sys.argv[1]
    wh = ['0-2','0-1','00','01','02']
    wh1 = ['W-2','W-1','W+0','W+1','W+2']
    for item in wh:
        if ( item == '0-2'):
            fn = 'W-2'
        else:
            if( item == '0-1'):
                fn = 'W-1'
            else:
                if (item == '00'):
                    fn = 'W+0'
                else:
                    if (item == '01'):
                        fn = 'W+1'
                    else:
                        if( item == '02'):
                            fn = 'W+2'
        os.system('./wheel_noise_producer.py ' + str(run) + '_' + str(item) + '.root ' + str(fn))
        os.system('./plot_producer1.py ' + str(run) + '_' + str(item) + '.root_out1.root ' + str(fn))
    os.system('hadd ' + str(run) + '.root_out1.root ' + str(run) + '_*.root_out1.root' )
    os.system('rm ' + str(run) + '_*.root_out1.root')
    os.system('hadd ' + str(run) + '.root_out2.root ' +  str(run) + '_*.root_out1.root_*.root')
    os.system('rm ' + str(run) + '_*.root_out1.root_*.root')
    for item in wh1:
        os.system('./summary_plot_producer.py ' + str(run) + '.root_out1.root '+ str(item))
    os.system('hadd ' + str(run) + '.root_out1.root_summary_out.root '  + str(run) + '.root_out1.root_*_summary_out.root' )
    os.system('rm ' + str(run) + '.root_out1.root_*_summary_out.root')
    os.system('./plot_davide.py ' + str(run) + '.root_out1.root_summary_out.root')
    os.system('hadd ' + str(run) + '_final.root ' + str(run) + '.root_out2.root '  + str(run) + '.root_out1.root_summary_out.root_davide.root ' +  str(run) + '.root_out1.root_summary_out.root')
    os.system('rm ' + str(run) + '.root_out2.root '  + str(run) + '.root_out1.root_summary_out.root_davide.root ' +   str(run) + '.root_out1.root_summary_out.root')
