#include <iostream>
#include <cmath>
#include <cstdio>

double f (double x);
double fderivcentral (double x, double h);
double fderivforward (double x, double h);
double fderivrichardsoncentral (double x, double h);
double fderivrichardsonforward (double x, double h);
double error (double x , double exact);

int main (void)

{

  double x=2.0;
  double h=0.0;
  double exact = -2*std::exp(-2*x)-1 ;

 std::cout.precision(16);
 std::cout.setf(std::ios::scientific);

  for(h=0.001;h<=0.501;h=h+0.001) {
    
      std::cout << h << "\t"
        << error(fderivcentral(x, h), exact) << "\t"
        << error(fderivforward(x, h), exact) << "\t"
        << error(fderivrichardsoncentral(x, h), exact) << "\t"
        << error(fderivrichardsonforward(x, h), exact) << "\t"
        << std::endl;
    }

  return 0;
}

double f (double x)
{
  double result= std::exp(-2*x)-x;
  return result;
}

double fderivforward (double x, double h)
{
  double result = (f(x+h) - f (x))/h;
  return result;
}
double fderivcentral (double x, double h)
{
  double result = (f(x+h/2) - f (x- h/2))/h;
  return result;
}

double fderivrichardsonforward (double x, double h)
{
  double h2 = h/2;
  double result1 = fderivforward (x,h);
  double result2 = fderivforward (x,h2);
  double result = (4*result2- result1)/3.0;
  return result;
}

double fderivrichardsoncentral (double x, double h)
{
  double h2 = h/2;
  double result1 = fderivcentral (x,h);
  double result2 = fderivcentral (x,h2);
  double result = (4*result2- result1)/3.0;
  return result;
}

double error (double x, double xexact)
{
  double result = std::fabs(1 - x/xexact);
  return result;
}

