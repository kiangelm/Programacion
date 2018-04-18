#include <iostream>
#include <vector>
#include <cmath>

using fptr = double(double); 

double f(double x);
double simpson(const double a, const double b, const int n, fptr func); 

int main(void)
{
  double exact=0;
  double intes=0;
  intes=simpson(0,1,20,f);
  exact=0.6022980709793;
  
  std::cout << "Simpson integral (n = 20) is : " << simpson(0, 1, 20, f) << std::endl;
  std::cout<<"error is: "<< fabs(intes-exact/exact)<< std::endl;
  
  return 0;
}

double f(double x)
{
  return (std::pow(x,0.1))*(1.2-x)*(1-std::exp(20*(x-1)));
}

double simpson(const double a, const double b, const int n, fptr func) 
{
  double sum = 0, result = func(a) + func(b);
  double x;
  const double h = (b-a)/n;
  
  sum = 0;
  for(int ii = 1; ii <= n/2 - 1; ++ii ) {
    x = a + 2*ii*h;
    sum += func(x);
  }
  result += 2*sum;
  
  sum = 0;
  for(int ii = 1; ii <= n/2; ++ii ) {
    x = a + (2*ii-1)*h;
    sum += func(x);
  }
  result += 4*sum;  
  
  return result*h/3;
}
