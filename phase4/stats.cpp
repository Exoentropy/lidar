#include "stats.h"
#include "Point.h"
#include <math.h>
#include <vector>
#include <list>

using namespace std;

// usese a simple sum over loop to calculate the average
template <class T>
double calcAverage(const list<T>& points){
  double sum = 0.0;
  typename list<T>::const_iterator iter = points.begin();
  for(; iter != points.end(); ++iter){
    sum += iter->_i;
  }
  return sum / points.size();
}

/* calculates the standard devation by subtracting the intensity of a given
   point by the average intensity, then adds that value squared and stores the
   sum, then returns the square root of the sums divided by the size - 1
*/
template <class T>
double calcStdDev(const list<T>& points, double averageIntensity){
  double singleDev = 0.0;
  double sumOfDevs = 0.0;
  
  typename list<T>::const_iterator iter = points.begin();
  for(; iter != points.end(); ++iter){
    singleDev = iter->_i - averageIntensity;
    sumOfDevs += singleDev * singleDev;
  }
  return sqrt(sumOfDevs / (points.size() - 1));
}

/* 
   creates an iterator, then removes all of the elements that are more than
   three times larger than the standard deviation
*/

/*
   The biggest inefficency is that it searches point by point.  I feel like
   you could be clever in detecting groups of 'bad' points rather than
   iterating through the entire grid.  It is also
   limited by how tight of a standard deviation you can compute.
*/
template <class T>
void removeBad(list<T>& points, double stdDev, double averageIntensity){
  typename list<T>::iterator iter = points.begin();
  for(; iter != points.end();){
    if((iter->_i)  > (averageIntensity + (3 * stdDev))){
      iter = points.erase(iter);
    }
    else{
      ++iter;
    }
  }
}
