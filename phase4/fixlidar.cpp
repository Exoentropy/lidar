#include <iostream>
#include <fstream>
#include <list>
#include "Point.h"
#include "Point2.h"
#include "xyzi.h"
#include "stats.h"
#include "stats.cpp"
#include "xyzi.cpp"

using namespace std;

int main(int argc, char** argv)
{
  if (argc < 3) {
    cout << "Usage: ./fixlidar infilename outfilename" << endl;
    return -1;
  }
  // stores file names
  string fIn = argv[1];
  string fOu = argv[2];
  // tests for .xyzict
  if(fIn.size() >= 8 && fOu.size() >= 8 && fIn.substr(fIn.size() - 7, fIn.size() - 1) == ".xyzict" && fOu.substr(fOu.size() - 7, fOu.size() - 1) == ".xyzict"){
    ifstream in(argv[1]);
     list<Point2> points = readxyzi<Point2>(in);
     in.close();
       /* Calculate the average and standard deviation here.
     Using these statistics, remove all bad points.  */
     // gets the average intensity and stores the result
     double averageIntensity = calcAverage(points);
     cout << "Average Intensity: " << averageIntensity << endl;
     // gets the standard deviation and stores the result
     double standardDev = calcStdDev(points, averageIntensity);
     cout << "Standard Deviation: " << standardDev << endl;
     // removes all of the bad points
     removeBad(points, standardDev, averageIntensity);
     ofstream out(argv[2]);
     writexyzi(out, points);
     out.close();
  }
  // tests for .xyzi
  else if(fIn.size() >= 5 && fOu.size() >= 5 && fIn.substr(fIn.size() - 5, fIn.size() - 1) == ".xyzi" && fOu.substr(fOu.size() - 5, fOu.size() - 1) == ".xyzi"){
     ifstream in(argv[1]);
     list<Point> points = readxyzi<Point>(in);
     in.close();
       /* Calculate the average and standard deviation here.
     Using these statistics, remove all bad points.  */
     // gets the average intensity and stores the result
     double averageIntensity = calcAverage(points);
     cout << "Average Intensity: " << averageIntensity << endl;
     // gets the standard deviation and stores the result
     double standardDev = calcStdDev(points, averageIntensity);
     cout << "Standard Deviation: " << standardDev << endl;
     // removes all of the bad points
     removeBad(points, standardDev, averageIntensity);
     ofstream out(argv[2]);
     writexyzi(out, points);
     out.close();
  }
  // error message
  else{
    cout << "Error: please use valid file extension" << endl;
  }
  return 0;
}
