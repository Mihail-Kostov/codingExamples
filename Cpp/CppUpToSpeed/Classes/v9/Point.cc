#include "Point.h"

#include <cmath>
#include <ostream>

Point::Point(): x_(0.), y_(0.) {}

Point::Point(double ax, double ay):
  x_(ax),
  y_(ay) {
}

void Point::set(double ax, double ay) {
  x_ = ax;
  y_ = ay;
}

void Point::set(Point const& p) {
  x_ = p.x_;
  y_ = p.y_;
}

double Point::mag() const {
  return std::sqrt(x_ * x_ + y_ * y_);
}

double Point::phi() const {
  return std::atan2(y_, x_);
}

void Point::scale(double f) {
  x_ *= f;
  y_ *= f;
}

std::ostream& operator<<(std::ostream& ost,
                         Point const& p) {
  ost << "( "
      << p.x() << ", "
      << p.y()
      << " )";

  return ost;
}
