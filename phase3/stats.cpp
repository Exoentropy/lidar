#include "stats.h"
#include "Point.h"
#include <math.h>
#include <vector>

using namespace std;

// usese a simple sum over loop to calculate the average
double calcAverage(vector<Point>& points){
  double sum = 0.0;
  for(int index = 0; index < points.size(); ++index){
    sum += points[index]._i;
  }
  return sum / points.size();
}

/* calculates the standard devation by subtracting the intensity of a given
   point by the average intensity, then adds that value squared and stores the
   sum, then returns the square root of the sums divided by the size - 1
*/
double calcStdDev(vector<Point>& points, double averageIntensity){
  double singleDev = 0.0;
  double sumOfDevs = 0.0;
  for(int index = 0; index < points.size(); ++index){
    singleDev = points[index]._i - averageIntensity;
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
void removeBad(vector<Point>& points, double stdDev, double averageIntensity){
  vector<Point>::iterator it = points.begin();
  while(it != points.end()){
    if((it->_i)  > (averageIntensity + (3 * stdDev))){
      it = points.erase(it);
    }
    else{
      ++it;
    }
  }
}
