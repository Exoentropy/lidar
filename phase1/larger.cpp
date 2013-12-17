// Write a program that asks the user to enter two integers. It tells the
// user which integer is larger and then prints all integers between the
// two integers (non-inclusive) in increasing order.  
//
// Before you can build you will need to modify the Makefile file to 
// include a target called "larger."  Copy the first two lines of the file
// and change all "hello" to "larger."  Now you can build and run:
//     make larger
//     ./larger
//
// To test to see if your program is correct, run this way:
//     cat larger.dat | ./larger
//
// This sends the contents of the file larger.dat as input to your program.
// Running this should output:
//     The larger number is 9.
//     6
//     7
//     8
#include <iostream>

int main(int argc, char** argv)
{
  // creates two numbers to store input
  int max;
  int min;
  
  // asks the user for two integers, then stores the two inputs called min and max
  std::cout << "Enter the first number: " << std::endl;
  std::cin >> max;
  std::cout << "Enter the second number: " << std::endl;
  std::cin >> min;
  
  /* checks to see if the initial input is larger or smaller than the second input
     if needed, it switches the values
     prints out which number is larger or if they are equal */
  if(max < min){
    int temp = max;
    max = min;
    min = temp;
    std::cout << "The larger number is " << max << std::endl; 
  }
  else if(max > min){
    std::cout << "The larger number is " << max << std::endl;
  }
  else{
    std::cout << "The two numbers are equal." << std::endl;
  }
  
  // loops through the inclusive numbers, which go from min + 1 to max - 1, and print them out on a separate line
  for(int current = min + 1; current < max; ++current){
    std::cout << current << std::endl;
  }
  return 0;
}