#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>

using namespace std;

class Point {
public:
  Point() {}
  Point(double x, double y, double z, double i) : _x(x), _y(y), _z(z), _i(i) {
  }
  const double& x() const { return _x; }
  double& x() { return _x; }
  const double& y() const { return _y; }
  double& y() { return _y; }
  const double& z() const { return _z; }
  double& z() { return _z; }
  const double& i() const { return _i; }
  double& i() { return _i; }
  
  friend ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x() << ", " << p.y() << ", " << p.z() << ", " << p.i() << ")";
    return out;
  }

private:
  double _x, _y, _z, _i;
};

#endif
