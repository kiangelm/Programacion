#include <iostream>
#include <cmath>
#include "complex.h"
int main(void)
{
  complex a, b;
  a.real=4.5;
  b.real=3.1;
  a.imag=-5.6;
  b.imag=-1.11;
  std::cout<< a.norm() << "\t" << b.norm() << std::endl;

  complex c;
  c= a + b;
  c.print();
  
  return 0;
}
