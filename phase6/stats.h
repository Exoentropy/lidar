#ifndef _STATS_H_
#define _STATS_H_

#include <list>
#include <math.h>

double calcAverage(Point** samples, int numPoints)
{
  double sum = 0;
  for (int i = 0; i < numPoints; ++i) {
    sum += samples[i]->z();
  }
  return sum / numPoints;
}

double calcStdDev(Point** samples, int numPoints, double avg)
{
  double sum = 0;
  for (int i = 0; i < numPoints; ++i) {
    double d = avg - samples[i]->z();
    sum += d*d;
  }
  return sqrt(sum / numPoints);
}

#endif
