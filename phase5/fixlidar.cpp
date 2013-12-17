#include <iostream>
#include <fstream>
#include <list>
#include "Point.h"
#include "Point2.h"
#include "xyzi.h"
#include "stats.h"

using namespace std;

// template to get I
template <typename P>
double getI(const P& p) {
  return p.get_i();
}

// template to get Z
template <typename P>
double getZ(const P& p) {
  return p.get_z();
}

// template for scores
template <typename P>
int getScore(const P& p) {
  return p;
}

// function to calc avg inten and standard dev
template <class T, class Function>
void run(T begin, T end, Function f, char** argv){
  /* Calculate the average and standard deviation here.
  Using these statistics, remove all bad points.  */
  // gets the average intensity and stores the result
  double averageIntensity = calcAverage(begin, end, f);
  cout << averageIntensity << ", ";
  // gets the standard deviation and stores the result
  double standardDev = calcStdDev(begin, end, averageIntensity, f);
  cout << "standard dev =  " << standardDev << endl;
}

// main
int main(int argc, char** argv)
{
  // error checking
  if (argc < 2) {
    cout << "Usage: ./fixlidar infilename outfilename" << endl;
    return -1;
  }
  ifstream in(argv[1]);
  // stores file names
  string fIn = argv[1];
  // tests for .xyzict
  if(fIn.size() >= 8 && fIn.substr(fIn.size() - 7, fIn.size() - 1) == ".xyzict"){
    list<Point2> points = readxyzi<Point2>(in);
    in.close();
    cout << "average I = ";
    run(points.begin(), points.end(), getI<Point2>, argv);
    cout << "average Z = ";
    run(points.begin(), points.end(), getZ<Point2>, argv);
  }
  // tests for .xyzix
  else if(fIn.size() >= 5 && fIn.substr(fIn.size() - 5, fIn.size() - 1) == ".xyzi"){
    list<Point> points = readxyzi<Point>(in);
    in.close();
    cout << "average I = ";
    run(points.begin(), points.end(), getI<Point>, argv);
    cout << "average Z = ";
    run(points.begin(), points.end(), getZ<Point>, argv);
  }
  // checks for .dat
  else if(fIn.size() >= 4 && fIn.substr(fIn.size() - 4, fIn.size() - 1) == ".dat"){
    vector<int> scores;
    int score;
    while (in >> score) {
      scores.push_back(score);
    }
    const double avg = calcAverage(scores.begin(), scores.end(), getScore<int>);
    const double stdDev = calcStdDev(scores.begin(), scores.end(), avg, getScore<int>);
    cout << "average = " << avg << ", standard dev = " << stdDev << endl;
  }
  // error message
  else{
    cout << "Error: please use valid file extension" << endl;
  }
  return 0;
}
