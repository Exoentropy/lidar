#include <iostream>
#include <iomanip>
#include <vector>

Vector<int> makeQuartile(int start, int end, Vector<int> numbers, Vector<int> temp){
    for(int i = start; i < end; ++i){
      temp.push_back(numbers[start]);
    }
    return temp;
}

int main(int argc, char** argv)
{
  /* 
    uses the std namespace for less code, a constant for the quartiles, an integer for the user input,
    integers to store the current indices, a vector to store all of the numbers, a temporary vector to make each
    quartiles, and a vector of vectors to store all of the quartiles
  */
  using namespace std;
  const int NUM_QRTS = 4;
  int input;
  int start;
  int end;
  vector<int> numbers;
  vector<int> temp;
  vector<vector<int> > quartiles;
  
  /* 
    loop to get all of the inputs from the user, until the EOF is reached.
  */
  while(cin >> input){
    numbers.push_back(input);
  }
  
  /*
    loop to go through and call makeQuartile and store each quartile in the vector of vectors
  */
  for(int qrt = 0; qrt < NUM_QRTS; ++qrt){
    start = qrt * (numbers.size() / 4);
    end = ((qrt + 1) * (numbers.size() / 4)) - 1;
    temp.clear();
    quartiles.push_back(makeQuartile(start, end, numbers, temp));
  }
  
  /*
    loop to go through and find the min, max, median and average of each quartile
  */
  
  for(int qrt = 0; qrt < NUM_QRTS; ++qrt){
    quartiles[qrt].sort();
    int min = quartiles[qrt][0];
    int max = quartiles[qrt][quartiles[qrt].size() - 1];
    int med;
    if(quartiles[qrt].size() % 2 == 0){
      med = (quartiles[qrt][quartiles[qrt].size() / 2 - 1] + quartiles[qrt][quartiles[qrt].size() / 2]) / 2;
    }
    else{
      med = quartiles[qrt][quartiles[qrt].size() / 2];
  }
  return 0;
}