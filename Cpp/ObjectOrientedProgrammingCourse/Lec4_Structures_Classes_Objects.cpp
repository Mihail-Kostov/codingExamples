#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

class galaxy{
private:
  std::string hubbletype;
  double redshift, totmass, stellarmassfrac;
  std::vector<galaxy> satellite;
public:
  // Default constructor
  galaxy(){hubbletype="Null"; redshift = 0; totmass = 0; stellarmassfrac = 0;}
  // Parametrized constructor
  galaxy(std::string p_hubbletype, double p_redshift, double p_totmass, double p_stellarmassfrac){
    hubbletype = p_hubbletype;
    redshift = p_redshift;
    totmass = p_totmass;
    stellarmassfrac = p_stellarmassfrac;
  }
  // Destructor
  // ~galaxy(){ std::cout << "Destroying galaxy..." << std::endl;}
  // Member functions
  void PrintData();
  void ChangeGalaxyType(std::string p_hubbletype);
  void AddSatellite(galaxy p_satellite);
  double GetStellarMass();
};



int main(){

  std::vector<galaxy> galassia;
  
  galassia.push_back(galaxy("Sa",5,7,0.03));
  galassia.push_back(galaxy("Sb",4,9,0.04));

  galassia[0].AddSatellite(galaxy("Sb",1,1,0.01));
  galassia[0].AddSatellite(galaxy("Sc",1,1,0.01));

  std::vector<galaxy>::iterator pcur;
  for(pcur=galassia.begin();pcur<galassia.end();++pcur){
    pcur->PrintData();
  }


  return 0;
}





void galaxy::PrintData(){
  std::cout << std::setprecision(3) << std::endl;
  std::cout << "----- GALAXY DATA -----" << std::endl;
  std::cout << "Hubble type: " << hubbletype << std::endl;
  std::cout << "Redshift: " << redshift << std::endl;
  std::cout << "Total mass: " << totmass << std::endl;
  std::cout << "Stellar mass fraction: " << stellarmassfrac << std::endl;
  
  int n(0);
  std::vector<galaxy>::iterator pcur;
  for(pcur=satellite.begin();pcur<satellite.end();++pcur){
    n++;
  }
  std::cout << "Number of satellites: " << n << std::endl;
  if(n!=0){
    int i(0);
    for(pcur=satellite.begin();pcur<satellite.end();++pcur){
      std::cout << "---- SATELLITE " << i << " -----" << std::endl;
      std::cout << "Hubble type: " << satellite[i].hubbletype << std::endl;
      std::cout << "Redshift: " << satellite[i].redshift << std::endl;
      std::cout << "Total mass: " << satellite[i].totmass << std::endl;
      std::cout << "Stellar mass fraction: " << satellite[i].stellarmassfrac << std::endl;
      i++;
    }
  }
  std::cout << std::endl;
}

void galaxy::ChangeGalaxyType(std::string p_hubbletype){
  hubbletype = p_hubbletype;
}

double galaxy::GetStellarMass(){return stellarmassfrac*totmass;}

void galaxy::AddSatellite(galaxy p_satellite){
  satellite.push_back(p_satellite);
}

