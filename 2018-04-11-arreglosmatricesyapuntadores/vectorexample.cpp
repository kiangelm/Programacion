#include <iostream>
#include <cmath>
#include <vector>

int main(void)
{
  const int N=10;
  int sum = 0;
  double arg=0;
  std::vector<double> x(N);    
  for(int ii=0; ii<N ; ii++) {
    sum += x[ii];
    double arg = sum/N;
  }
  return arg;
  return 0;
}
