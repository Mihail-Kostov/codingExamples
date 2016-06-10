#! /usr/bin/env python
import numpy as np
from math import exp, sqrt

# Adday of filenames
filename_list = ["runjobh","jaceeh","sokolh"]

# Define GSHL parameters and formula as a function
def gshl(x):
    a,b,c,d = 14900,2.15,-0.22,2.74
    return a*(x + b*exp(c*sqrt(x)))**(-d)

# Loop through the files
for filename in filename_list:
    # Generate input and output file names
    namein = "OriginalData/%s.dat" %(filename)
    nameout = "ModifiedData/%s.dat" %(filename)

    # Create an array and fill it with data from file (array[row][column])
    data = np.genfromtxt(namein) #Original data
    n_rows = data.shape[0] #Number of rows
    n_columns = data.shape[1] #Number of columns
    newdata = np.empty(shape=[n_rows,n_columns]) #Create empty array to save modified data

    # Convert original data into modified data
    for i in range(0, n_rows):
        newdata[i][0] = data[i][0]
        newdata[i][1] = gshl(data[i][0])*(1 + data[i][1]/100.)
        newdata[i][2] = gshl(data[i][0])*(1 + data[i][2]/100.)
        newdata[i][3] = gshl(data[i][0])*(1 + data[i][3]/100.)
            
    # Save modified data on new file
    np.savetxt(nameout,newdata)
