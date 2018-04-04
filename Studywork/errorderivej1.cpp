#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdio>

double f (double x);
double fderivada(double x, double h);
double error(double x, double exact); //el exact toma todas las cifras decimales calculadas en el proceso para evitar errores de redondeo al aproximar

int main(void)
{
 double x= 1;
 double h=0;
 double exact=1/x;
 for (h=0.1;h>=10e-8;h=h/10){
   std::cout << h << "\t" << error(fderivada(x,h), exact)<< std::endl;
 }

  return 0;
}

double f (double x)
{
  double result= std::log(x);
  return result;
}

double fderivada (double x, double h)
{
  double result=(1/(4*h))*(f(x+3*h)-f(x-h));
  return result;		
}

double error(double x, double xexact)
{
double result = std::fabs(1 - x/xexact);
 return result;
}
