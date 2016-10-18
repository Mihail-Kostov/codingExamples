import numpy as np
import datetime
import os
from subprocess import call, Popen

# Useful functions
logIn = open('logIn.log', 'w')
logOut = open('logOut.log', 'w')
logErr = open('logErr.log', 'w')
def Notifier(string,curr,tot):
    string += '; echo "Job \'%s\' has finished." | mutt -s "Job %i of %i finished" salvatore.porzio@postgrad.manchester.ac.uk' %(string,curr,tot)
    return string

# Execution
njobs = 3
processes = []
for i in range(njobs):
    string = ''
    string += 'echo'
    string += ' "Hello World!"'

    inl = os.tmpfile()
    outl = os.tmpfile()
    errl = os.tmpfile()
    stringNot = Notifier(string,i,njobs)
    p = Popen(stringNot,shell=True,stdin=inl,stdout=outl,stderr=errl)
    now = datetime.datetime.now()
    processes.append((now,string,p,inl,outl,errl))

for start, name, proc, i, o, e in processes:
    p.wait()
    end = datetime.datetime.now()
    logIn.write('%s\n%s -> %s\n' %(name,start,end))
    logIn.write('\n')
    o.seek(0)
    logOut.write('%s\n%s -> %s\n' %(name,start,end))
    logOut.write(o.read())
    logOut.write('\n')
    e.seek(0)
    logErr.write('%s\n%s -> %s\n' %(name,start,end))
    logErr.write(e.read())
    logErr.write('\n')
    i.close()
    o.close()
    e.close()
