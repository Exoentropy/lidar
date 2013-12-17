#include <iostream>
#include <fstream>
#include <list>
#include <ctime>

#include "xyzi.h"
#include "Point.h"
#include "stats.h"

using namespace std;

int main(int argc, char** argv)
{
  if (argc < 3) {
    cout << "Usage: ./terrace infilename outfilename" << endl;
    return -1;
  }
  // size of Lyon
  const int numPoints = 440354;
  // read the points
  ifstream in(argv[1]);
  // creates an array for the points
  Point** points = readxyzi(in, numPoints);
  in.close();
  // calculates and stores the averages and standard deviations
  const double avg = calcAverage(points, numPoints);
  const double sd = calcStdDev(points, numPoints, avg);
  // print
  cout << "average = " << avg << ", standard dev = " << sd << endl;
  // loop through points
  for (int i = 0; i < numPoints; ++i) {
    // stores the address of the z to change
    double address = points[i]->z();
    // stores the new z
    double newZVal = 0.0;
    // checks to see if it is too far above or below the standard deviation
    // if so, stores a z that is a more a appropriate value
    if (address > avg + 1.5 * sd) {
      newZVal = avg + 1.5 * sd;
    }
    else if (address > avg + 1 * sd) {
      newZVal = avg + 1 * sd;
    }
    else if (address > avg + 0.5 * sd) {
      newZVal = avg + 0.5 * sd;
    }
    else if (address > avg) {
      newZVal = avg;
    }
    else if (address > avg - 0.5 * sd) {
      newZVal = avg - 0.5 * sd;
    }
    else if (address > avg - 1.0 * sd) {
      newZVal = avg - 1.0 * sd;
    }
    else if (address > avg - 1.5 * sd) {
      newZVal = avg - 1.5 * sd;
    }
    else {
      newZVal = avg - 2.0 * sd;
    }
    // stores the new z value
    points[i]->z() = newZVal;
  }
  ofstream out(argv[2]);
  writexyzi(out, points, numPoints);
  out.close();
  delete[] points;
}
