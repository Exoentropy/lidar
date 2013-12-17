#ifndef _XYZI_H_
#define _XYZI_H_

#include <iostream>
#include <vector>
#include "Point.h"

// Reads xyzi-style ascii lidar data from a file and returns as a vector
// of points.
std::vector<Point> readxyzi(std::istream& in);
// Writes xyzi-style lidar data to an ascii.
void writexyzi(std::ostream& out, const std::vector<Point>& points);

#endif
