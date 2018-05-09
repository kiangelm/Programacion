#include <iostream>
#include <cmath>

struct complex {
  void print(void);
  double real, imag;
  complex operator+ (complex b);
  complex operator- (complex b);
  complex operator* (complex b);
  complex & operator= (complex b);
  double norm(void);
  double ang(void);
  double sin(void);
  double cos(void);
  
};
  
