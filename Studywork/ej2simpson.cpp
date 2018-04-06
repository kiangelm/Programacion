#include <iostream>
#include <vector>
#include <cmath>

using fptr = double(double); //Opción para hacer llamado de funciones dentro de otra función 

double f(double x);
double simpson(const double a, const double b, const int n, fptr func); //recibe los límites de integración a y b, # de interaciones n y la función a integrar
double simpson2(const double a, const double b, const int n, fptr func);

int main(void)
{
  // test with Simpson
  std::cout << "Simpson integral (n = 4) is : " << simpson(0, 2*M_PI, 4, f) << std::endl; //Cambié cos(2x) porque en esa parte no va el argumento de la función si no solo el nombre, es decir no se pone f(x) si no solo f, como la función era cos(2x)*exp(x), no podía poner cos*e porque no iba a entender, así que puse más bien f y luego definí f(x) como cos(2x)*exp(x)
  std::cout << "Simpson integral (n = 4) is : " << simpson2(0, 2*M_PI, 4, f) << std::endl; 
  return 0;
}

double f(double x){ //Aquí la definición de f como ya te comentaba 
  return std::cos(2*x)*std::exp(x); 
}

double simpson(const double a, const double b, const int n, fptr func) //En este caso entonces recibe func=f=cos(2x)*exp(x)
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

double simpson2(const double a, const double b, const int n, fptr func)
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
  
  return result*h/3;
}
