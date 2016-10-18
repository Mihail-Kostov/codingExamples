import os
import datetime
import numpy as np
from subprocess import call

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
for i in range(njobs):
    string = ''
    string += 'echo'
    string += ' "Hello World!"'

    inl = os.tmpfile()
    outl = os.tmpfile()
    errl = os.tmpfile()
    print '\033[1;33m-> %s\033[0m' %(string)
    start = datetime.datetime.now()
    proc = call(Notifier(string,i+1,njobs),shell=True,stdin=inl,stdout=outl,stderr=errl)
    end = datetime.datetime.now()
    print 'Process %i of %i completed. Time: %s' %(i+1,njobs,end-start)
    Temp2Perm(inl,logIn,string,start,end)
    Temp2Perm(outl,logOut,string,start,end)
    Temp2Perm(errl,logErr,string,start,end)
