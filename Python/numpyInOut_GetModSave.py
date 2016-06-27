import numpy as np

# INPUT
dataIn = np.genfromtxt("Data/dataIn.dat",delimiter=" ",names=True,dtype=None)

# MODIFICATION
# This intermediate step (x,y,z) is unnecessary but it makes it easier in case you would want only the input or the output part
dataOut = []
for i in range(len(dataIn)):
    x = dataIn['Col1'][i] + dataIn['Col1'][i]
    y = dataIn['Col2'][i]*2
    z = dataIn['Col3'][i]/2
    dataOut.append([x,y,z])

# OUTPUT
np.savetxt("Data/dataOut.dat",np.array((dataOut)),delimiter=' ',header='Col1 Col2 Col3')
# np.savetxt("dataOut.dat",np.array((dataOut)),fmt=['%s','%s','%s'],delimiter=' ',header='Col1 Col2 Col3')
