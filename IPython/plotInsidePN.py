
# coding: utf-8

# ## Example code
# Plotting a TCanvas object in browser and example formulas: $a = \sqrt{c+d} - \log{ef}$

# Importing useful stuff

# In[1]:

import ROOT
from IPython.display import Image as Plot
ROOT.gROOT.SetBatch(1)


# Python function to destroy TObjects

# In[2]:

def destruct(object_):
    if issubclass(type(object_), ROOT.TObject):
        object_.IsA().Destructor(object_)


# Creating histogram and filling hit

# In[3]:

h = ROOT.TH1F("gauss","Example histogram",100,-4,4)
h.FillRandom("gaus")


# All the graph personalization should go in one block

# In[8]:

c = ROOT.TCanvas("myCanvasName","The Canvas Title",1280,720)
h.SetLineColor(ROOT.kRed)
h.SetLineWidth(3)
h.Draw("EH")


# Finally this is plotting the histogram on the browser

# In[9]:

c.SaveAs("histo.png")
destruct(c)
Plot("histo.png")


# In[ ]:



