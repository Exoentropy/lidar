#include <iostream>
#include <fstream>
#include <vector>
#include "Point.h"
#include "xyzi.h"
#include "stats.h"

using namespace std;

int main(int argc, char** argv)
{
  if (argc < 3) {
    cout << "Usage: ./fixlidar infilename outfilename" << endl;
    return -1;
  }

  ifstream in(argv[1]);
  vector<Point> points = readxyzi(in);
  in.close();

  /* Calculate the average and standard deviation here.
     Using these statistics, remove all bad points.  */

  // gets the average intensity and stores the result
  double averageIntensity = calcAverage(points);

  // gets the standard deviation and stores the result
  double standardDev = calcStdDev(points, averageIntensity);
  
  // removes all of the bad points
  removeBad(points, standardDev, averageIntensity);
  
  
  ofstream out(argv[2]);
  writexyzi(out, points);
  out.close();

  return 0;
}
