#ifndef _STATS_H_
#define _STATS_H_
#include "Point.h"
#include <math.h>
#include <vector>

using namespace std;

double calcAverage(vector<Point>& points);

double calcStdDev(vector<Point>& points, double averageIntensity);

void removeBad(vector<Point>& points, double stdDev, double averageIntensity);

#endif
