#ifndef _POINT_H_
#define _POINT_H_
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// adds four simple doubles as instance variables
struct Point{
  double _x;
  double _y;
  double _z;
  double _i;
  
  bool read(std::istream& in)
  {
    // Read in point location (x,y,z) and intensity i.
    double x, y, z, i;
  
    while (in >> x >> y >> z >> i) {
      _x = x;
      _y = y;
      _z = z;
      _i = i;
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
          << setprecision(8) << _i << endl;
  }
};

#endif
