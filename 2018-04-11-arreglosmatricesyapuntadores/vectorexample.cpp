#include <iostream>
#include <cmath>
#include <vector>

 const int N=10;

void print (const std::vector<double> & a);
void initialize (std::vector<double> & a);
void average (const std::vector<double> & a);

int main(void)
{
 std::vector<double>data(N); 

 initialize(data);
 print(data);
 average(data);
 
  return 0;
}

void print(const std::vector<double> & a)
{
  // print the array
  for(int ii = 0; ii < a.size(); ++ii){
    std::cout << a[ii] << std::endl;
  }
}

void average(const std::vector<double> & a)
{
  double sum = 0.0;
  for(int ii = 0; ii < a.size(); ++ii){
    sum += a[ii];
  }
  std::cout << "Average = " << sum/a.size() << std::endl;
}

void initialize(std::vector<double> & a)
{
  for(int ii = 0; ii < a.size(); ++ii){
    a[ii] = 2*ii;
  }
}
