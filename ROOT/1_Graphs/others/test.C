void test(){

  struct Dataset{
    std::string filename[20];
    std::string experiment[20];
    Int_t id_no;
  };

  Dataset cosmicds[5];
  strcpy(cosmicds[0].filename,"filename1");
  strcpy(cosmicds[0].experiment,"experiment1");
  cosmicds[0].id_no = 1;

  std::cout << " ---PRINT INFO---" << endl;
  std::cout << " Filename: \t" << cosmicds[0].filename << endl;
  std::cout << " Experiment: \t" << cosmicds[0].experiment << endl;
  std::cout << " ID Number: \t" << cosmicds[0].id_no << endl;
}


