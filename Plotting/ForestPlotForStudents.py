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

def ReadCsvData(inputFile):
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

    values = [el[0] for el in data]
    errors = [el[1] for el in data]
    labels = [el[2] for el in data]
    return data

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-i','--input',required=True,help='Input directory',type=str)
    parser.add_argument('-x','--xLabel',required=False,help='Label for the x axis',type=str)
    args = parser.parse_args()
    data,errors,labels = ReadCsvData(args.input)
    print data
    print errors
    print labels
    # ForestPlot(data,errors,labels)

if __name__ == '__main__':
    main()