#include <iostream>
#include <vector>
#include <algorithm> // for std::sort() and other algorithms
#include <cassert> // for assert()

int main(){
  
  // Declare variables
  std::vector<int> data;
  std::string uinput;
  int x(0);
  bool exit = true;
  

  // Read integers from manual input
  do{
    std::cout << " Enter a number (x to exit): ";
    std::cin >> uinput;
    if(uinput != "x"){
      x = atoi(uinput.c_str());
      data.push_back(x);
    }
    else exit = false;
  } while(exit==true);

  // Sort the elements in the vector
  std::sort(data.begin(), data.end());

  // Print out the elements in the vector
  std::cout << " Your sorted vector: ";
  for(std::vector<int>::iterator i(data.begin()); i<data.end(); ++i){
    std::cout << " " << *i;
  }
  std::cout << std::endl;

  // Copy your first vector into a second vector (second vector size must be defined!!!)
  std::vector<int> datacopy(data.size()); // Don't forget ".size()"!
  std::copy(data.begin(),data.end(),datacopy.begin());
  
  //Check if two vectors are equal
  assert(data==datacopy);

  // Print out again the elements of the copy vector in a different way
  std::cout << " Your sorted vector: ";
  for(std::vector<int>::size_type i(0); i<datacopy.size(); i++){
    // ".at()" is much safer than "[]"! It will not run if index is out of range!
    std::cout << " " << datacopy.at(i);
  }
  std::cout << std::endl;


  return 0;
}
