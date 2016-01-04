#include "Point.h"

#include <cmath>

Point::Point(): x(0.), y(0.) {}

Point::Point(double ax, double ay):
  x(ax),
  y(ay) {
}

double Point::mag() const {
  return std::sqrt(x * x + y * y);
}

double Point::phi() const {
  return std::atan2(y, x);
}

void Point::scale(double f) {
  x *= f;
  y *= f;
}
