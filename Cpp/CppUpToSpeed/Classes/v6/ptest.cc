#include "Point.h"

#include <iostream>

int main() {

  Point p0(1, 2);
  std::cout << "Before p0: (" << p0.x() << ", " << p0.y() << ")"
            << "  Magnitude: " << p0.mag()
            << "  Phi: "       << p0.phi()
            << std::endl;

  p0.scale(3.);
  std::cout << "After  p0: (" << p0.x() << ", " << p0.y() << ")"
            << "  Magnitude: " << p0.mag()
            << "  Phi: "       << p0.phi()
            << std::endl;

  Point p1(0, 1.);;
  std::cout << "p1: (" << p1.x() << ", " << p1.y() << ")"
            << "  Magnitude: " << p1.mag()
            << "  Phi: "       << p1.phi()
            << std::endl;
  p1.set(1., 0.);
  std::cout << "p1: (" << p1.x() << ", " << p1.y() << ")"
            << "  Magnitude: " << p1.mag()
            << "  Phi: "       << p1.phi()
            << std::endl;
  p1.set(p0);
  std::cout << "p1: (" << p1.x() << ", " << p1.y() << ")"
            << "  Magnitude: " << p1.mag()
            << "  Phi: "       << p1.phi()
            << std::endl;

  return 0;
}
