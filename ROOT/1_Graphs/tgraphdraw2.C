#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TLatex.h"

void draw2(){
  gROOT->SetStyle("Plain");
  TCanvas *c1 = new TCanvas();
  c1->SetGrid();

  TGraphErrors *graph = new TGraphErrors("data.dat", "%lg %lg %lg");

  graph->SetTitle("Measurement XYZ; length [cm]; Arb. Units");
  graph->SetMarkerStyle(kOpenCircle);
  graph->SetMarkerColor(kBlue);
  graph->SetLineColor(kBlue);
  graph->SetFillColor(kYellow);

  graph->Draw("E3AL");
  graph->Draw("PEsame");

  c1->Print("graphwithbands.pdf");
}
