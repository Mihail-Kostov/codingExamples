#include "Point.h"

#include <iostream>

int main() {

  Point p0;
  std::cout << "p0: (" << p0.x << ", " << p0.y << ")" << std::endl;

  p0.x = 1.0;
  p0.y = 2.0;
  std::cout << "p0: (" << p0.x << ", " << p0.y << ")" << std::endl;

  Point p1;
  p1.x = 3.0;
  p1.y = 4.0;
  std::cout << "p1: (" << p1.x << ", " << p1.y << ")" << std::endl;

  Point p2 = p0;
  std::cout << "p2: (" << p2.x << ", " << p2.y << ")" << std::endl;

  std::cout << "Address of p0: " << &p0 << std::endl;
  std::cout << "Address of p1: " << &p1 << std::endl;
  std::cout << "Address of p2: " << &p2 << std::endl;

  return 0;
}
