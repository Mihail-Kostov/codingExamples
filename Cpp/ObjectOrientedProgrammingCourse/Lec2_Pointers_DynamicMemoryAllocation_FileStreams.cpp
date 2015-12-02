#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

int determine_nline(std::string filename);
int read_data(std::string filename, float *data, int ndata);
float get_mean(float *data, int ndata);
float get_standev(float mean, float *data, int ndata);
float get_standeverr(float sigma, float ndata);


int main(){
  float *data, temp;
  int ndata(0);
  std::string filename = "millikan.dat";
  ndata = determine_nline(filename);

  data = new float[ndata];
  read_data(filename,data,ndata);

  std::cout << std::setprecision(3) << std::endl;
  std::cout << "Number of datapoints: " << ndata << std::endl;
  float mean = get_mean(data,ndata);
  std::cout << "Mean: " << mean << std::endl;
  float sigma = get_standev(mean,data,ndata);
  std::cout << "Standard deviation: " << sigma << std::endl;
  float err = get_standeverr(sigma,ndata);
  std::cout << "Standard error: " << err << std::endl;
  std::cout << std::endl;

  delete[] data;
  return 0;
}


// Determine number of lines in file
int determine_nline(std::string filename){
  int n(0);
  float temp;
  
  std::fstream myfile;
  myfile.open(filename.c_str());
  if(myfile.good()){
    while(myfile >> temp){
      n++;
    } // Read line from file
  } // Check if file opened successfully 
  else{ // Report error if file is not successfully open
    std::cerr << "ERROR: File could not be opened." << std::endl;
    return 1;
  }
  myfile.close();

  return n;
}


// Read data from file
int read_data(std::string filename, float *data, int ndata){
  int n(0);
  float temp;

  std::fstream myfile;
  myfile.open(filename.c_str());
  if(myfile.good()){
    while(myfile >> temp){
      *(data+n) = temp;
      n++;
    } // Read line from file
  } // Check if file opened successfully 
  else{ // Report error if file is not successfully open
    std::cerr << "ERROR: File could not be opened." << std::endl;
    return 1;
  }
  myfile.close();

  return 0;
}



float get_mean(float *data, int ndata){
  float mean(0);

  for(int i=0;i<ndata;i++){
    mean = mean + *(data+i);
  }
  mean = mean/ndata;

  return mean;
}



float get_standev(float mean, float *data, int ndata){
  float sigma(0), temp;

  for(int i=0;i<ndata;i++){
    temp = *(data+i) - mean;
    temp = pow(temp, 2.);
    sigma = sigma + temp;
  }
  sigma = sigma/(ndata-1);
  sigma = sqrt(sigma);

  return sigma;
}


float get_standeverr(float sigma, float ndata){
  float err;

  err = sigma/sqrt(ndata);

  return err;
}
