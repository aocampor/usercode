#! /usr/bin/env python
import commands
import sys, os, string, fileinput
from ROOT import *


#
# main
#

if __name__ == "__main__":

    cmd = 'rfdir $CASTOR_HOME/PRUEBA/LM0 | grep -v RA6 | awk \'{print $9}\''
    the_files = [item[:-1] for item in os.popen(cmd)]
    print the_files
    for i in range(len(the_files)):
        os.system('rfdir $CASTOR_HOME/PRUEBA/LM0/RA6_' + str(i+1)+'.root')

    
