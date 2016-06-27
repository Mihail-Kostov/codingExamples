#! /usr/bin/env python
from subprocess import call

no_files = 3

for i in range(1,no_files+1):
    command = "mv"
    arg1 = "Data/woa%i.txt" %(i)
    arg2 = "Data/a%i.txt" %(i)
    call(command + arg1 + arg2, shell=True)
