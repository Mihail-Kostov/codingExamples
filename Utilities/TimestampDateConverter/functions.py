import ROOT
import array
import math
import pytz
import time
from pytz import timezone
from datetime import datetime as dt

CST = timezone("US/Central")
GMT = timezone("Europe/London")
EUR = timezone("Europe/Rome")
nullSensitivity = 0.005 # Where to find the "feet" of the peak (0 finds them on the 0 axis)

# Get string with date
def GetDateString(iTime):
    # year = ROOT.TDatime(int(iTime)).GetYear()
    # month = datetime.date(1900, ROOT.TDatime(int(iTime)).GetMonth(),1).strftime('%B')
    # day = ROOT.TDatime(int(iTime)).GetDay()
    naive = dt.utcfromtimestamp(iTime)
    aware = pytz.UTC.localize(naive)
    local = aware.astimezone(CST).strftime('%d %B %y')
    return local


# Get string with time
def GetTimeString(iTime):
    # hour = ROOT.TDatime(int(iTime)).GetHour()
    # minute = ROOT.TDatime(int(iTime)).GetMinute()
    # second = ROOT.TDatime(int(iTime)).GetSecond()
    # sTime = "%i:%i:%i" %(hour,minute,second)
    naive = dt.utcfromtimestamp(iTime)
    aware = pytz.UTC.localize(naive)
    local = aware.astimezone(CST).strftime('%H:%M:%S')
    return local

def GetChicagoTimestamp(year,month,day,hour,minute,second):
    naive = dt(year,month,day,hour,minute,second)
    aware = CST.localize(naive).astimezone(pytz.utc)
    unixtime = time.mktime(aware.timetuple())
    return unixtime
