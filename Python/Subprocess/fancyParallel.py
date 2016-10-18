import os
import datetime
import numpy as np
from subprocess import Popen

# Useful functions
def Notifier(string,curr,tot):
    string += '; echo "Job \'%s\' has finished." | mutt -s "Job %i of %i finished" salvatore.porzio@postgrad.manchester.ac.uk' %(string,curr,tot)
    return string

def Temp2Perm(temp,perm,name,start,end):
    temp.seek(0)
    perm.write('%s\n%s -> %s\n' %(name,start,end))
    perm.write(temp.read())
    perm.write('\n')
    temp.close()

# Settings
njobs = 3
logIn = open('logIn.log', 'w')
logOut = open('logOut.log', 'w')
logErr = open('logErr.log', 'w')

# Execution
processes = []
for i in range(njobs):
    string = ''
    string += 'echo'
    string += ' "Hello World!"'

    inl = os.tmpfile()
    outl = os.tmpfile()
    errl = os.tmpfile()
    start = datetime.datetime.now()
    proc = Popen(Notifier(string,i+1,njobs),shell=True,stdin=inl,stdout=outl,stderr=errl)
    processes.append((start,string,proc,inl,outl,errl))

for start, name, proc, inl, outl, errl in processes:
    proc.wait()
    end = datetime.datetime.now()
    Temp2Perm(inl,logIn,name,start,end)
    Temp2Perm(outl,logOut,name,start,end)
    Temp2Perm(errl,logErr,name,start,end)
