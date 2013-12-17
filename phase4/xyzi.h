#ifndef _XYZI_H_
#define _XYZI_H_
#include <list>
#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;

// Reads xyzi-style ascii lidar data from a file and returns as a vector
// of points.
template<class T>
list<T> readxyzi(istream& in);
// Writes xyzi-style lidar data to an ascii.
template<class T>
void writexyzi(ostream& out, const list<T>& points);

#endif
