import numpy as np
import pytz
from pytz import timezone
from datetime import datetime as dt
from functions import GetDateString as GDS
from functions import GetTimeString as GTS
from functions import GetChicagoTimestamp as GCT

CST = timezone("US/Central")
GMT = timezone("Europe/London")
EUR = timezone("Europe/Rome")

dates = np.genfromtxt("inFile.dat",delimiter="\t",names=True,dtype=None)
dtStart = []
dtEnd = []
for event in dates:
    dtStart.append(pytz.UTC.localize(dt.utcfromtimestamp(event['Start'])).astimezone(CST).strftime('%Y-%m-%d %H:%M:%S'))
    dtEnd.append(pytz.UTC.localize(dt.utcfromtimestamp(event['End'])).astimezone(CST).strftime('%Y-%m-%d %H:%M:%S'))

timestamps = np.matrix([dtStart,dtEnd]).transpose()
np.savetxt("outFile.dat",timestamps,fmt='%s',delimiter='\t',header='Start\tEnd')
