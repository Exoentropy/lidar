#ifndef _STATS_H_
#define _STATS_H_
#include "Point.h"
#include <math.h>
#include <vector>
#include <list>

using namespace std;

template <class T>
double calcAverage(const list<T>& points);

template <class T>
double calcStdDev(const list<T>& points, double averageIntensity);

template <class T>
void removeBad(list<T>& points, double stdDev, double averageIntensity);

#endif
