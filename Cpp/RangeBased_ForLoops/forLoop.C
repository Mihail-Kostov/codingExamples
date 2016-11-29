#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>

int main(){
  std::vector<int> vec;
  vec.push_back( 10 );
  vec.push_back( 20 );

  for (int i : vec ){
      std::cout << i << std::endl;
  }
  return 0;
}
