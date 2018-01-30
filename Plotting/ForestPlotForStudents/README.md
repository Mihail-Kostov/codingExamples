In order to use ForestPlot, you will have to prepare a .csv file with three columns:

value,error,label

There must be no space between commas and values. There is a sample csv file called "sampleData.csv", that you can use as a guideline.

After the .csv file is ready, all you need to do is run the following command from the terminal.

python ForestPlot.py -i csvFile.csv -x "xlabel"

Where csvFile.csv is the name of the file with your data and "xlabel" is the label that you want to give to the x axis. The -x argument is optional and you don't have to specify it (in which case, 'None' will be used).
