#include "Point.h"

#include <iostream>

int main() {

  Point p0;
  std::cout << "p0: (" << p0.x << ", " << p0.y << ")" << std::endl;

  p0.x = 3.1;
  p0.y = 2.7;
  std::cout << "p0: (" << p0.x << ", " << p0.y << ")" << std::endl;

  return 0;
}
