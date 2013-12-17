#ifndef _STATS_H_
#define _STATS_H_
#include "Point.h"
#include <math.h>
#include <vector>
#include <list>

using namespace std;

// usese a simple sum over loop to calculate the average
template <class ItType, class Function>
double calcAverage(const ItType begin, const ItType end, const Function f){
  double sum = 0.0;
  int size = 0;
  for(ItType iter = begin; iter != end; ++iter){
    sum += f(*iter);
    size++;
  }
  return sum / size;
}
/* calculates the standard devation by subtracting the intensity of a given
   point by the average intensity, then adds that value squared and stores the
   sum, then returns the square root of the sums divided by the size - 1
*/
template <class ItType, class Function>
double calcStdDev(const ItType begin, const ItType end, const double averageIntensity, const Function f){
  double singleDev = 0.0;
  double sumOfDevs = 0.0;
  int size = 0;
  for(ItType iter = begin; iter != end; ++iter){
    singleDev = f(*iter) - averageIntensity;
    sumOfDevs += singleDev * singleDev;
    size++;
  }
  return sqrt(sumOfDevs / size);
}

#endif
