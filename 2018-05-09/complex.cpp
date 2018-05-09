#include "complex.h"
void complex::print(void)
{
  std::cout<< real << std::endl
	   << imag << std::endl;
}

complex complex::operator+ (complex b)
{
  complex sum;
  sum.real = real + b.real;
  sum.imag = imag + b.imag;
  return sum;
}

complex complex::operator- (complex b)
{
  complex dif;
  dif.real = real - b.real;
  dif.imag = imag - b.imag;
  return dif;
}

complex complex::operator* (complex b)
{
  complex mult;
  mult.real = (real*b.real - imag*b.imag);
  mult.imag = (real*b.imag + b.real*imag);
  return  mult;
}

complex & complex::operator= (complex b)
{
  real = b.real;
  imag = b.imag;
  return *this;
}

double complex::norm (void)
{
  double norm = 0.0;
  norm = std::sqrt( real*real + imag*imag );
  return norm;
}

double complex::ang(void)
{
  double ang = 0.0;
  ang = std::atan2(imag,real);
  return ang;
}
double complex::sin(void)
{
  double sin=0.0;
}

double complex::cos(void)
{
  double cos=0.0;
}
