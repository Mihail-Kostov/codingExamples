void write_ntuple_to_file(){
  int i,j,k,n;

  TNtuple *data = new TNtuple("data","Example N-Tuple","Potential:Current:Temperature:Pressure");

  float pot,cur,temp,pres;

  for(i=0;i<10000;i++){
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
    data->Fill(pot,cur,temp,pres);
  }

  // Save to file
  TFile in("ntuple_output_sample.root","RECREATE");
  data->Write();
  in.Close();

}
