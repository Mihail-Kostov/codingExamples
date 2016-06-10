import numpy as np
from functions import GetDateString as GDS
from functions import GetTimeString as GTS
from functions import GetChicagoTimestamp as GCT
dates = np.genfromtxt("inDate.dat",delimiter="\t",names=True,dtype=None)
dtStart = []
dtEnd = []
for event in dates:
    dtStart.append(GCT(event['Year'],event['Month'],event['Day'],event['Hour'],event['Minute'],event['Second']))
timestamps = np.array((dtStart)).transpose()
np.savetxt("outTimestamps.dat",timestamps,fmt='%i',delimiter=' ',header='Timestamps')
