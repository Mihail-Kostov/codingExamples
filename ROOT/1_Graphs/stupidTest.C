#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TLatex.h"

int simpleFunction(const double (&len)[2]);

int stupidTest(){

  double crap[2] = {1,2};
  simpleFunction(crap);
  return 0;
}

int simpleFunction(const double (&len)[2]){
  std::cout << len[0] << std::endl;
  std::cout << len[1] << std::endl;
  return 0;
}
