#include <iostream>
#include <cmath>
#include <cstdio>

double f (double x);
double fderivforward (double x, double h);
double fderivcentral (double x, double h);
double fderivrichardsonforward (double x, double h);
double fderivrichardsoncentral (double x, double h);

int main (void)

{
  double x=M_PI;
  double h=0.1;
  std::printf("%25.16e\n", std::cos(x));
  std::printf("%25.16e\n", fderivforward(x,h));
  std::printf("%25.16e\n", fderivcentral(x,h));
  std::printf("%25.16e\n", fderivrichardsonforward(x,h));
  std::printf("%25.16e\n", fderivrichardsoncentral(x,h));
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
