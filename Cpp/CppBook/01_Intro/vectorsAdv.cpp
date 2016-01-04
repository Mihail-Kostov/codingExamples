#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm> // for std::sort() and other algorithms
#include <cassert> // for assert()

int main(){
  
  // Declare variables
  std::vector<int> data;
  std::string uinput;
  int x(0);
  bool exit = true;
  
  // Read integers while inserting them in a vector
  std::cout << " Insert data (x to exit):" << std::endl;
  std::copy(std::istream_iterator<int>(std::cin),
	    std::istream_iterator<int>(),
	    std::back_inserter(data));

  for(std::vector<int>::iterator i(data.begin()); i<data.end(); ++i) *i = *i * 2;

  // Sort the data in the vector
  std::sort(data.begin(),data.end());

  // Print out data in the vector
  std::cout << std::endl << " Your sorted vector: ";
  std::copy(data.begin(),
	    data.end(),
	    std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;


  return 0;
}
