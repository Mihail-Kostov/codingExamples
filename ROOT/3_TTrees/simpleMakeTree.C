//MAIN FUNCTION
void simpleMakeTree(){
  srand(time(NULL));

  int event;
  double length;
  double vector[3];
  int nHits[3];
  std::vector< std::vector<float> > PH_v;
  PH_v = std::vector< std::vector<float> >(3, std::vector<float>(0));

  TFile *f = new TFile("OutTree.root","RECREATE");
  TTree *tree = new TTree("Tree","Tree for data from HV");
  tree->Branch("TrackLength",&length,"length/D");
  tree->Branch("NumHits",&nHits,"nHits_U/I:nHits_V/I:nHits_Y/I");
  tree->Branch("Hit_PulseHeight_U",&PH_v[0]);
  tree->Branch("Hit_PulseHeight_V",&PH_v[1]);
  tree->Branch("Hit_PulseHeight_Y",&PH_v[2]);

  int i = 0;
  int j = 0;
  int k = 0;
  int rand_nHits;
  double rand_val;
	for(i=0;i<10;i++) {
		length = (rand() % 100) + 1;
    PH_v.at(0).clear();
    PH_v.at(1).clear();
    PH_v.at(2).clear();
    nHits[0] = 0;
    nHits[1] = 0;
    nHits[2] = 0;
    for(k=0;k<3;k++) {
      rand_nHits = (rand() % 10) + 1;
      for(j=0;j<rand_nHits;j++) {
        rand_val = (rand() % 10) + 1;
        PH_v.at(k).push_back(rand_val);
      }
      nHits[k] = PH_v.size();
    }
    tree->Fill();

	}
  f->Write();
  f->Close();
}
