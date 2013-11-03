#! /usr/bin/env python
import commands
import sys, os, string, fileinput
from ROOT import *


#
# main
#

if __name__ == "__main__":
    


    cmd = 'ls *.root'#'rfdir $CASTOR_HOME/PRUEBA/LM0 | grep -v pat | awk \'{print $9}\''
    the_files = [item[:-1] for item in os.popen(cmd)]
    print the_files
    for i in the_files:
        os.system('rfcp ' + str(i) +' $CASTOR_HOME/ROOT_Files/')

    
