//MAIN FUNCTION
void simpleMakeTree(){
  srand(time(NULL));

  int event;
  double length;
  double vector[3];
  int nHits;
  std::vector<double> hitWidth_v;

  TFile *f = new TFile("OutTree.root","RECREATE");
  TTree *tree = new TTree("Tree","Tree for data from HV");
  tree->Branch("Event",&event,"event/I");
  tree->Branch("Length",&length,"length/D");
  tree->Branch("Vector",&vector[0],"x/D:y/D:z/D");
  tree->Branch("N_Hits",&nHits,"nHits/I");
  tree->Branch("HitWidth",&hitWidth_v,"vector<double>");

  int i = 0;
  int j = 0;
  int rand_nHits;
  int rand_hitWidth;
	for(i=0;i<10;i++) {
    event = i;
		length = (rand() % 100) + 1;
    vector[0] = (rand() % 100) + 1;
    vector[1] = (rand() % 100) + 1;
    vector[2] = (rand() % 100) + 1;
    rand_nHits = (rand() % 10) + 1;
    hitWidth_v.clear();
    for(j=0;j<rand_nHits;j++) {
      rand_hitWidth = (rand() % 10) + 1;
      hitWidth_v.push_back(rand_hitWidth);
    }
    nHits = hitWidth_v.size();
    tree->Fill();
	}
  f->Write();
  f->Close();
}
