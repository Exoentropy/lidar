#include <iomanip>

#include "xyzi.h"

Point** readxyzi(istream& in, int numPoints)
{
  Point** points = new Point*[numPoints];
  double x, y, z, i;
  int idx = 0;
  while (in >> x >> y >> z >> i) {
    Point* p = new Point(x, y, z, i);
    points[idx++] = p;
  }
  return points;
}

void writexyzi(ostream& out, Point** points, int numPoints)
{
  for (int i = 0; i < numPoints; ++i) {
    out << setprecision(8) << points[i]->x() << " " 
	<< setprecision(8) << points[i]->y() << " " 
	<< setprecision(8) << points[i]->z() << " " 
	<< setprecision(8) << points[i]->i() << endl;
  }
}
