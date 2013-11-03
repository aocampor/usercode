#! /usr/bin/env python
import commands
import sys, os, string, fileinput
from ROOT import *


#
# main
#

if __name__ == "__main__":
    


    cmd = 'rfdir $CASTOR_HOME/PRUEBA/LM0 | grep -v pat | awk \'{print $9}\''
    the_files = [item[:-1] for item in os.popen(cmd)]
    print the_files
    for i in the_files:
        os.system('rfchmod +777 $CASTOR_HOME/PRUEBA/LM0/' + str(i))

    
