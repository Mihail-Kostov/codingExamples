void write_to_file(){

  TH1D *h = new TH1D("histo","Title; X; Y",100,-5,5);
  h->FillRandom("gaus");
  TFile out("output_sample.root","RECREATE");
  h->Write();
  out.Close();

}
