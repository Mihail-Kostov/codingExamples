#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main(){
  
  const std::string degreeCode("PHYS");
  std::vector<int> courseNumber;
  std::vector<std::string> courseName;
  std::vector<std::string> fullCourse;
  std::vector<std::string>::iterator stringCurrent, stringBegin, stringEnd;
  std::vector<int>::iterator intCurrent, intBegin, intEnd;


  // Gather list of courses and their codes from user,
  // storing data as a vector of strings
  bool not_finished(true);
  do{
    std::string inputString1, inputString2;
    int inputInt;
    std::cout << "Please enter a course name (or x to finish): ";
    cin >> inputString1;
    if(inputString1=="x") not_finished = false;
    else{
      cin >> inputString2;

      stringstream buffer(inputString1);
      buffer >> inputInt;

      courseNumber.push_back(inputInt);
      courseName.push_back(inputString2);

      stringstream sbuffer;
      sbuffer << degreeCode << inputInt << " " << inputString2;
      // std::string test(buffer.str());
      std::cout << sbuffer.str() << std::endl;
      fullCourse.push_back(sbuffer.str());
    }
  } while(not_finished);

  // Print out full list of courses
  std::cout << "List of courses:" << std::endl;
  stringBegin = fullCourse.begin();
  stringEnd = fullCourse.end();
  for(stringCurrent=stringBegin;stringCurrent<stringEnd;stringCurrent++) std::cout << *stringCurrent << std::endl;

  // // Extract courses belonging to a certain year
  // string yearChoice;
  // cout<<"Please enter year: ";
  // cin>>yearChoice;
  // cout>>"Sort by code or name: ";
  // cin>>sortOption;

  return 0;
}
