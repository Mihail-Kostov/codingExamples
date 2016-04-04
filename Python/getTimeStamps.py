# The script gets the timestamp for interesting events from the root files in
# sporzio@ubdaq-prod-ws01.fnal.gov:/home/gahs/torscopemon.
import ROOT

fRoot = ROOT.TFile("tormon_20160101_020001.root","READ")
fOut = open("listTime.txt","w")
tree = fRoot.torscope_tree

for eventNumber in range(tree.GetEntries()):
    tree.GetEntry(eventNumber)
    for timestamp in tree.unixtime:
        fOut.write(str(timestamp) + "\n")
