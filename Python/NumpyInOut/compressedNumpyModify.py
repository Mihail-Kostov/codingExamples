import numpy as np
import math

# Define converters
xConverter = lambda x: x+x
yConverter = lambda y: math.sqrt(float(y))
zConverter = lambda z: float(z)**2

# INPUT OUTPUT
data = np.genfromtxt("dataIn.dat",delimiter=" ",names=True,dtype=None,converters={0:xConverter,1:yConverter,2:zConverter})
np.savetxt("dataOut.dat",data,delimiter=' ',fmt='%s',header='Col1 Col2 Col3')
