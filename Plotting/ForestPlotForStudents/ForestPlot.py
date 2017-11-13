#******************************************************************************
# Copyright (C) 2017, Salvatore Davide Porzio                                 *
# For any query, please contact salvatore.porzio@postgrad.manchester.ac.uk    *
#                                                                             *
# Permission is hereby granted, free of charge, to any person                 *
# obtaining a copy of this software and associated documentation files        *
# (the "Software"), to deal in the Software without restriction,              *
# including without limitation the rights to use, copy, modify, merge,        *
# publish, distribute, sublicense, and/or sell copies of the Software,        *
# and to permit persons to whom the Software is furnished to do so,           *
# subject to the following conditions:                                        *
#                                                                             *
# The above copyright notice and this permission notice shall be              *
# in all copies or substantial portions of the Software.                      *
#                                                                             *
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,             *
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES             *
# OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, *
# DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,               *
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE  *
# OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *
#******************************************************************************

import os, sys, argparse
import numpy as np
import matplotlib.pyplot as plt
plt.rcParams['font.family']='serif'
plt.rcParams['font.weight']='light'
plt.rcParams['font.size']=14
figsize = (12,8)

def ForestPlot(data,errors,labels,xlabel=''):
    data = np.flip(np.array(data),0)
    errors = np.flip(np.array(errors),0)
    mean = np.average(data,weights=np.power(1./errors,2.))
    meanErr = np.sqrt((1./np.sum(np.power(1./errors,2.))))
    labels.append(r'$\bf{Combined}$')
    labels = np.flip(np.array(labels),0)
    datastrings = [r'%.3g $\pm$ %.3g' %(x,w) for x,w in zip(data,errors)]
    datastrings.insert(0,r'$\bf{%.3g \pm %.3g}$' %(mean,meanErr))
    index = np.linspace(2,len(data)+1,len(data))
    fig, ax1 = plt.subplots(figsize=figsize)
    plt.axvline(mean,ls='--',color='gray',label='Weighted mean: %f' %(mean))
    plt.errorbar(data,index,xerr=errors,color='C0',ls='',marker='o',markersize=8,elinewidth=2,capsize=10,markeredgewidth=2)
    plt.errorbar([mean],[1],xerr=[meanErr],color='C3',ls='',marker='o',markersize=8,elinewidth=2,capsize=10,markeredgewidth=2)
    plt.ylim(0.5,index[-1]+0.5)
    index = np.linspace(1,len(data)+1,len(data)+1)
    plt.yticks(index, labels)
    plt.xlabel(xlabel)
    ax2 = ax1.twinx()
    plt.ylim(0.5,index[-1]+0.5)
    plt.yticks(index, datastrings)
    fig.tight_layout()
    plt.gcf().subplots_adjust(bottom=0.15)
    plt.show()

def ReadCsvData(filename,dtype='str'):
    with open(filename,'rb') as fileIn:
        data = []
        lines = fileIn.read().split('\n')[:-1]
        nColumns = len(lines[0].split(','))
        if nColumns>1:
            for i in range(nColumns):
                if dtype=='int': data.append([int(line.split(',')[i]) for line in lines])
                if dtype=='float': data.append([float(line.split(',')[i]) for line in lines])
                if dtype=='str': data.append([str(line.split(',')[i]) for line in lines])
        else:
            for line in lines:
                if dtype=='int': data.append(int(line))
                if dtype=='float': data.append(float(line))
                if dtype=='str': data.append(str(line))
    values = [float(el) for el in data[0]]
    errors = [float(el) for el in data[1]]
    labels = [str(el) for el in data[2]]
    return values,errors,labels

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-i','--input',required=True,help='Input directory',type=str)
    parser.add_argument('-x','--xLabel',required=False,help='Label for the x axis',type=str)
    args = parser.parse_args()
    values,errors,labels = ReadCsvData(args.input)
    ForestPlot(values,errors,labels,args.xLabel)

if __name__ == '__main__':
    main()