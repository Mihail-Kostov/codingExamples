#include <cstdio> // for std::perror()
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm> // for std::sort()

int main(){

  std::ifstream filename("data.dat");
  std::vector<int> data;

  if(not filename) std::perror("data.dat");
  else {
    int x(0);
    while(filename >> x)data.push_back(x);
    filename.close();
  }
  
  std::sort(data.begin(), data.end());

  std::cout << " Printing vector data: ";
  for(std::vector<int>::iterator i(data.begin()); i<data.end(); ++i) std::cout << " " << *i;
  std::cout << std::endl;

  return 0;
}
