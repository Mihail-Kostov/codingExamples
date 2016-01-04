#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <map>

int main(){
  // Define variables
  std::map<std::string,int> counts;
  std::string word;

  // Read in input
  while (std::cin >> word) ++counts[word];

  // Print out counts
  for(std::map<std::string,int>::iterator iter(counts.begin()); iter != counts.end(); ++iter){
    std::cout << iter->first << "\t" << iter->second << std::endl;
  }

  return 0;
}
