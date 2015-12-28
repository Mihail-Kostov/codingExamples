#ifndef Point_h
#define Point_h

class Point {

 public:

  Point();
  Point(double ax, double ay);

  double mag() const;
  double phi() const;
  void scale(double factor);

  double x;
  double y;
};

#endif /* Point_h */
