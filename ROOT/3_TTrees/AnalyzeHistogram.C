#define Analyze_cxx
#include "Analyze.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Analyze::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L Analyze.C
//      Root > Analyze t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   // SETUP CODE!
   TH1D *chi2_h = new TH1D("chi_h","CHI2",100,0,5);
   TH1D *ebeam_h = new TH1D("ebeam_h","EBEAM",100,149,151);
   TH1D *pt_h = new TH1D("pt_h","PT",100,0,40);
   TH1D *theta_h = new TH1D("theta","THETA",100,-0.2,0.2);
   TH2D *chi2ebeam_h = new TH2D("chi2ebeam_h","CHI2vsEBEAM",100,100,0,5,149,151);
   TH2D *chi2theta_h = new TH2D("chi2theta_h","CHI2vsTHETA",100,100,0,15,-0.2,0.2);
   double pt, theta;
   int count;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      //LOOP CODE!
      chi2_h->Fill(chi2);
      if(chi2<1) ebeam_h->Fill(ebeam);
      chi2ebeam_h->Fill(chi2,ebeam);
      if(chi2<1.5 && theta<0.15) chi2theta_h->Fill(chi2,theta);

      pt = TMath::Sqrt(px*px + py*py);
      theta= TMath::ATan2(pt,pz);
      if(pz<145) count = count+1;

      pt_h->Fill(pt);
      theta_h->Fill(theta);
   }

   // WRAPUP CODE!
   // ebeam_h->Fit("gaus");

   TCanvas *c1 = new TCanvas();
   // chi2_h->Draw();
   // pt_h->Draw();
   chi2theta_h->Draw();
   // std::cout << count << endl;

   // TCanvas *c2 = new TCanvas();
   // ebeam_h->Draw("E");
   // TCanvas *c3 = new TCanvas;
   // chi2ebeam_h->Draw();

}
