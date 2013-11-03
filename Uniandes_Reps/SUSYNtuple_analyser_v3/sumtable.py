#!/usr/bin/python

import sys 

def main():
    listfile = []
    fp=open("tab_temp.txt", "w")
    for i in range(len(sys.argv)-1):
        #print sys.argv[i+1]
        file = open(str(sys.argv[i+1]))
        listsing = []
        while 1:
            line = file.readline()
            if not line:
                break
            #print str(line)
            listsing.append(str(line))
        listfile.append(listsing)    
    #print listfile 
    for i in range(len(listfile[0])):
        row = "\small "
        for j in range(len(listfile)):
            if (i == 0):
                temp1 = str(listfile[j][i]).rstrip('\n')
                temp2 = temp1.split('Significance table for')
                row = row + " & \small " + temp2[-1] 
            else:
                if(j == 0):
                    temp1 = str(listfile[j][i]).rstrip('\n')
                    temp2 = temp1.split('/')
                    temp3 = temp2[-1].split('   ')
                    temp3a = temp3[0] 
                    temp3b = temp3a.split('Salida_')[-1]
                    temp3c = temp3b.split('.root')[0]
                    row = row + temp3c + " & \small " + temp3[-1]    
                else:
                    temp1 = str(listfile[j][i]).rstrip('\n')
                    temp2 = temp1.split('/')
                    temp3 = temp2[-1].split('   ')
                    row = row + " & \small " + temp3[-1]    
        row = row + "\\\\"
        fp.write(row + '\n')
    fp.close()


if __name__ == "__main__":
    main()
