#include <iomanip>
#include "Point.h"
#include "Point2.h"
#include "xyzi.h"
#include <vector>
#include <list>

using namespace std;

// Reads xyzi-style ascii lidar data from a file and returns as a vector
// of points.

template<class T>
list<T> readxyzi(istream& in)
{
  list<T> points;
  // Read in point location (x,y,z) and intensity i.
  T p;
  for(; p.read(in) ;){
    points.push_back(p);
  }
  return points;
}

template<class T>
// Writes xyzi-style lidar data to an ascii.
void writexyzi(ostream& out, const list<T>& points)
{
  typename list<T>::const_iterator iter = points.begin();
  for(; iter != points.end(); ++iter){
    iter->write(out);
  }
}
