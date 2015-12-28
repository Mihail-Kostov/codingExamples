#ifndef Point_h
#define Point_h

#include <iosfwd>

class Point {

 public:

  Point();

  Point(double ax, double ay);

  double x() const { return x_; }
  double y() const { return y_; }

  void set(double ax, double ay);
  void set(Point const& p);

  double mag() const;
  double phi() const;
  void scale(double factor);

 private:

  double x_;
  double y_;
};

std::ostream& operator<<(std::ostream& ost,
                         Point const& p);

#endif /* Point_h */
