#ifndef _XYZI_H_
#define _XYZI_H_

#include <iostream>
#include <list>
#include "Point.h"

Point** readxyzi(istream& in, int numPoints);
void writexyzi(ostream& out, Point** points, int numPoints);

#endif
