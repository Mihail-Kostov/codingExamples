import numpy as np
import datetime
from subprocess import call

# Useful functions
def Screamer(string):
    scream = 'echo "\033[1;33m-> %s\033[0m"' %(string)
    return scream

def Saver(string):
    now = datetime.datetime.now()
    log = 'echo "%s: %s" >> cLog.log' %(now, string)
    return log

def Notifier(string,curr,tot):
    notification = 'echo "Job \'%s\' has finished." | mutt -s "Job %i of %i finished" salvatore.porzio@postgrad.manchester.ac.uk' %(string,curr,tot)
    return notification

def Run(string,curr,tot):
    log = ' 2>&1 | tee -a rLog.log'
    call(Screamer(string), shell=True)
    call(Saver(string), shell=True)
    call(string + log, shell=True)
    call(Notifier(string,curr,tot), shell=True)



# Execution
njobs = 3

call('rm rLog.log; rm cLog.log', shell=True)
call('touch rLog.log; touch cLog.log', shell=True)
for i in range(njobs):
    string = ''
    string += 'echo'
    string += ' "Hello World!"'

    Run(string,i,njobs)
