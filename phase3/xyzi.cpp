#include <iomanip>
#include "Point.h"
#include "xyzi.h"
#include <vector>

using namespace std;

// Reads xyzi-style ascii lidar data from a file and returns as a vector
// of points.
vector<Point> readxyzi(istream& in)
{
  vector<Point> points;
  // Read in point location (x,y,z) and intensity i.
  double x, y, z, i;
  while (in >> x >> y >> z >> i) {
    Point p;
    p._x = x;
    p._y = y;
    p._z = z;
    p._i = i;
    points.push_back(p);
  }
  return points;
}

// Writes xyzi-style lidar data to an ascii.
void writexyzi(ostream& out, const vector<Point>& points)
{
  for (int i = 0; i < points.size(); ++i) {
    out << setprecision(8) << points[i]._x << " " 
	<< setprecision(8) << points[i]._y << " " 
	<< setprecision(8) << points[i]._z << " " 
	<< setprecision(8) << points[i]._i << endl;
  }
}
