#ifndef DECAYVERTEX_H
#define DECAYVERTEX_H

////////////////////////////////////////////////////////////////////////
//
// Class:       DecayVertex
// File:        DecayVertex.h
//
//              The intent of this class is to provide objects where
//              to store temporary vertices in the detector
//
// Created by Davide Porzio (salvatore.porzio@postgrad.manchestera.ac.uk)
// on February 19, 2016
//
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <exception>

// #include "fhiclcpp/ParameterSet.h"
// #include "larcore/Geometry/Geometry.h"
// #include "lardata/DetectorInfoServices/DetectorPropertiesService.h"

namespace AuxVertex
{
// Decay vertex class and functions
  class DecayVertex
  {
  public:
    // Constructor and destructor
    DecayVertex(double x,
                double y,
                double z,
                int parIdx1,
                int parIdx2,
                std::string parType1,
                std::string parType2);
    ~DecayVertex();

    // Getters
    double GetX();
    double GetY();
    double GetZ();
    int GetParIdx1();
    int GetParIdx2();
    std::string GetParType1();
    std::string GetParType2();
    bool IsInsideTPC();
    int GetWireLoc(int plane);
    double GetTickLoc(int plane);

  private:
    bool fIsInsideTPC; // Is the vertex inside the TPC.
    double fX, fY, fZ; // Spatial coordinates of the vertex inside the detector.
    int fParIdx1,  fParIdx2; // Index of parent in track/shower vector (same for origin vertices).
    std::string fParType1, fParType2; // Type of parent ('t'=track,'s'=shower,'n'=neutral).
    std::vector<int> fWireLoc; // Nearest wire in each plane.
    std::vector<double> fTickLoc; // Nearest time tick in each plane.

    // geo::GeometryCore const* fGeometry; // Pointer to the Geometry service
    // detinfo::DetectorProperties const* fDetectorProperties; // Pointer to the Detector Properties
  };

  double Distance(DecayVertex v1, DecayVertex v2);
  DecayVertex MeanVertex(DecayVertex v1, DecayVertex v2);


} //END namespace AuxVertex

#endif