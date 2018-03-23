#include <iostream>
#include <cmath>
#include <cstdio> // para usar std::printf

double f (double x);
double fderivforward (double x, double h);

int main (void)
{
  double x = M_PI;
  double h = 0.1;
  std::printf("%f\n",fderivforward(x,h));
    //%f es un cout y especifico tipo de datos f es float
    //%25.16e 25 espacios 16 cifras y e notación científica 
    return 0;
}
double f (double x)
{
  return std:: sin(x);
}

double fderivforward (double x, double h)
{
  double result = (f(x+h) - f (x))/h;
  return result;
}
//para el resultado se puede hacer de esas dos formas


