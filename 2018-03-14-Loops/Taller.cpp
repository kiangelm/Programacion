#include <iostream>
#include <cmath>
#include <cstdio>

double f (double x);
double fderivforward (double x, double h);
double fderivcentral (double x, double h);
double fderivrichardsonforward (double x, double h);
double fderivrichardsoncentral (double x, double h);
double error (double x , double exact);
 
int main (void)

{
  double x=M_PI/3;
  double h=0.0;
  double exact = std::cos(x);
  for(h=0.1;h>=10e-8;h=h/10)
    {
      std::cout << h << "\t"
		<< error(fderivforward(x, h), exact) << "\t"
		<< error(fderivcentral(x, h), exact) << "\t"
		<< error(fderivrichardsonforward(x, h), exact) << "\t"
		<< error(fderivrichardsoncentral(x, h), exact) << "\t"
		<< std::endl;
    }

  return 0;
}

double f (double x)
{
  double result = std::sin(x);
  return result;
}

double fderivforward (double x, double h)
{
  double result = (f(x+h) - f (x))/h;
  return result;
}
double fderivcentral (double x, double h)
{
  double result = (f(x-h/2) + f (x- h/2))/h;
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
