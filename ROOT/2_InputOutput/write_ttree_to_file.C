void write_ttree_to_file(std::string outputfilename = "ttree_output_sample.root", unsigned int numdatapoints = 10000){

  int i,j,k,n;

  // Create TTree
  TTree *data = new TTree("data", "Example TTree");
  
  // Define variable and book them for ttree
  float pot,cur,temp,pres;
  data->Branch("Potential",&pot,"Potential/F");
  data->Branch("Current",&cur,"Current/F");
  data->Branch("Temperature",&temp,"Temperature/F");
  data->Branch("Pressure",&pres,"Pressure/F");

  for(i=0;i<numdatapoints;i++){
    // Generate fake data
    pot = gRandom->Uniform(0.,10.);
    temp = gRandom->Uniform(250.,350.);
    pres = gRandom->Uniform(0.5,1.5);
    cur = pot / (10. + 0.05 * (temp - 300.) - 0.2*(pres-1.));
    // Add random smearing
    pot *= gRandom->Gaus(1.,0.01); // 1% error
    temp += gRandom->Gaus(0.,0.3); // 0.3 absolute error
    pres *= gRandom->Gaus(1.,0.02); // 2% error
    cur *= gRandom->Gaus(1.,0.01); // 1% error
    // Write to ntuple
    data->Fill();
  }

  // Save to file
  TFile in(outputfilename.c_str(),"RECREATE");
  data->Write();
  in.Close();

}
