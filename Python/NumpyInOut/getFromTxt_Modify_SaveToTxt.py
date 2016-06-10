import numpy as np

npDataIn = np.genfromtxt("dataIn.dat",delimiter=" ",names=True,dtype=None)

# This intermediate step (x,y,z) is unnecessary -
# - but it makes it easier in case you would want only -
# - the input or the output part
data = []
for i in range(len(npDataIn)):
    x = npDataIn['Col1'][i] + npDataIn['Col1'][i]
    y = npDataIn['Col2'][i]*2
    z = npDataIn['Col3'][i]/2
    data.append([x,y,z])
npDataOut = np.array((data))
np.savetxt("dataOut.dat",npDataOut,fmt=['%s','%s','%s'],delimiter=' ',header='Col1 Col2 Col3')
