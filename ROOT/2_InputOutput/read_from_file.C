void read_from_file(){

  TFile *in = new TFile("outputsample.root");
  TH1D *h = (TH1D*) in->Get("histo");
  h->Draw();

}
