#include "Point.h"

#include <iostream>

int main() {

  Point p0(1., 2.);
  std::cout << "p0: (" << p0.x << ", " << p0.y << ")" << std::endl;

  Point p1(p0);
  std::cout << "p1: (" << p1.x << ", " << p1.y << ")" << std::endl;

  return 0;
}
