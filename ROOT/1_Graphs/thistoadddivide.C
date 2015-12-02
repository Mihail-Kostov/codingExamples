#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TLatex.h"


void format_histo(TH1D *h, int linecolor){
  h->SetLineWidth(3);
  h->SetLineColor(linecolor);
}

void thistoadddivide(){
  //Initial stuff
  gROOT->SetStyle("Plain");
  int i, k, j, n;

  //Declare histograms
  TH1D *sig_h = new TH1D("sig_h","Signal Histogram",50,0,10);
  TH1D *gaus_h1 = new TH1D("gaus_h1","Gauss1 Histogram",30,0,10);
  TH1D *gaus_h2 = new TH1D("gaus_h2","Gauss2 Histogram",30,0,10);
  TH1D *bkg_h = new TH1D("bkg_h","Background Histogram",50,0,10);

  //Fill histograms
  TRandom3 rndgen;
  for(i=0;i<4000;i++){
    bkg_h->Fill(rndgen.Exp(4));
    if(i%5==0) gaus_h1->Fill(rndgen.Gaus(5,2));
    if(i%5==0) gaus_h2->Fill(rndgen.Gaus(5,2));
    if(i%10==0) sig_h->Fill(rndgen.Gaus(5,0.5));
  }

  //Format histograms
  TH1D *histos[4] = {sig_h,bkg_h,gaus_h1,gaus_h2};
  for(i=0;i<4;i++){
    histos[i]->Sumw2(); //Store square of weights in the histograms
    format_histo(histos[i], i+1);
  }

  //Sum histograms
  TH1D *sum_h = new TH1D(*bkg_h);
  sum_h->Add(sig_h,1.); //(Histogram to add, weight) [weight can be -1 for subtraction]
  sum_h->SetTitle("Exponential + Gaussian");
  format_histo(sum_h,kBlue);
  //Draw
  TCanvas *c1 = new TCanvas();
  sum_h->Draw("histo");
  bkg_h->Draw("samehisto");
  sig_h->Draw("samehisto");

  //Divide histograms
  TH1D *divide_h =  new TH1D(*gaus_h1);
  divide_h->Divide(gaus_h2);
  //Draw
  divide_h->SetTitle("; X axis; Gaus Histo 1 / Gaus Histo 2");
  format_histo(divide_h,kOrange);
  gaus_h1->SetTitle(";;Gaus Histo 1 and Gaus Histo 2");
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  TCanvas *c2 = new TCanvas();
  c2->Divide(1,2,0,0);
  c2->cd(1);
  c2->GetPad(1)->SetRightMargin(0.01);
  gaus_h1->DrawNormalized("histo");
  gaus_h2->DrawNormalized("histosame");
  c2->cd(2);
  divide_h->GetYaxis()->SetRangeUser(0,2.49);
  c2->GetPad(2)->SetGridy();
  c2->GetPad(2)->SetRightMargin(0.01);
  divide_h->Draw();
  
  
}
