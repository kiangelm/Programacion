#include <iostream>
#include <cmath>

using fptr = double(double);

double f(double x);
double bisection(double xl, double xu, double eps, int nmax, fptr func);

int main(void)
{
  const double eps = 1.0e-8; //Tolerancia
  int NMAX = 50; //Iteraciones Máximas
  double xl = 12, xu = 18, xr=0;  //escógase xu(up) y xl(low) tal que: f(xu)>0;f(xl)<0
  xr = bisection(xl, xu, eps, NMAX, f); //f es la función a la que se le calcula la raiz
  return 0;
}


double f(double x)
{
  return (9.81*68.1/x)*(1-std::exp(-10*x/68.1)) - 40; //función a calcularle la raiz 
}
double bisection(double xl, double xu, double eps, int nmax, fptr func)
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  double xr = 0; //Este es un valor de inicialización,realmente no afecta mucho
  
  for(int ii = 0; ii <= nmax; ++ii) {
    xr = 0.5*(xu + xl);
    std::cout << ii << "  " << xl << " " << xu << " " << xr << " " << f(xr) << std::endl;
    if (std::fabs(f(xr)) < eps) break;
    if (f(xr)*f(xl) < 0)
      xu = xr;
    else
      xl = xr;
  }
  std::cout <<"La raíz de f(x) es: "<< xr << std::endl;
  
  return xr;
}
