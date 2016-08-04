#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TLatex.h"

void tgraphdraw(){
  const int ndata = 10;
  double xvalue[ndata] = {1,2,3,4,5,6,7,8,9,10};
  double yvalue[ndata] = {6,12,14,20,22,24,35,45,44,53};
  double yerr[ndata] = {5,5,4,7,4,4,5,2,4,4};

  // TGraphErrors *graph = new TGraphErrors(ndata,xvalue,yvalue,NULL,yerr);
  TGraph *graph = new TGraph(ndata,xvalue,yvalue); //where x , y are 2 arrays of n points
  // j->SetTitle("Measurement XYZ; length [cm]; Arb. Units");

  // gROOT->SetStyle("Plain");
  // graph->SetMarkerStyle(kOpenCircle);
  // graph->SetMarkerColor(kBlue);
  // graph->SetLineColor(kBlue);

  TCanvas *c1 = new TCanvas();

  graph->Draw("ap");
}
