void read_ntuple_from_file(){

  int i,j,k,n;

  TFile *in = new TFile("ntupleoutputsample.root");
  TNtuple *data = (TNtuple*) in->GetObjectChecked("data","TNtuple");

  double pot,cur,temp,pres;
  float *row_content; //Must necessarily be float and not a double... WHY?

  TH1D *histo = new TH1D("histo","HISTO",100,0,10);

  cout << "Potential\tCurrent\tTemperature\tPressure" << endl;
  for(i=0;i<data->GetEntries();++i){
      data->GetEntry(i);
      row_content = data->GetArgs();
      pot = row_content[0];
      cur = row_content[1];
      temp = row_content[2];
      pres = row_content[3];
      cout << pot << "\t" << cur << "\t" << temp << "\t" << pres << endl;
      histo->Fill(pot);
  }

  histo->Draw();
}
