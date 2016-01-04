#include <iostream>

#include "Point.h"

int main() {

  Point p0(1, 2);
  std::cout << "p0: " << p0
            << "  Magnitude: " << p0.mag()
            << "  Phi: "       << p0.phi()
            << std::endl;

  return 0;
}
