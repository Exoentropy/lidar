#ifndef _POINT2_H_
#define _POINT2_H_
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// adds four simple doubles as instance variables
class Point2{
 private:
  double _x;
  double _y;
  double _z;
  double _i;
  int _c;        // classification
  double _t;     // time
 
 public:
  bool read(std::istream& in)
  {
    // Read in point location (x,y,z) and intensity i.
    int c;
    double x, y, z, i, t;  
    if (in >> x >> y >> z >> i >> c >> t) {
      _x = x;
      _y = y;
      _z = z;
      _i = i;
      _c = c;
      _t = t;
      return true;
    }
    return false;
  }

  // Writes xyzi-style lidar data to an ascii.
  void write(std::ostream& out) const
  {
      out << setprecision(8) << _x << " " 
	  << setprecision(8) << _y << " " 
	  << setprecision(8) << _z << " "
	  << setprecision(8) << _i << " " 
	  << setprecision(8) << _c << " "  
	  << setprecision(8) << _t << endl;
  }

  double get_x() const{
    return _x;
  }
  double get_y() const{
    return _y;
  }
  double get_z() const{
    return _z;
  }
  double get_i() const{
    return _i;
  }
  int get_c() const{
    return _c;
  }
  double get_t() const{
    return _t;
  }
};

#endif
