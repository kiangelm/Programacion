#include <iostream>
#include <vector>
#include <cmath>
 
using fptr = double(double);  //Método definido para poder hacer llamado a funciones dentro de otra función 
 
double trapezoid_irregular(const std::vector<double> & x, const std::vector<double> & fx); // (ItI) No sé, está función incluso tiene punteros  
double trapezoid_regular(const double a, const double b, const int n, fptr func); // Int. Trapecio (It), límites a y b, # Interv=n y la función f 
double trapezoid_richardson(const double a, const double b, const int n, fptr func); //(ItR) Lo mismo de arriba
double simpson(const double a, const double b, const int n, fptr func); //(Is) Lo mismo de arriba arriba 
 
int main(void)
{
  const int N = 20; //Estos parámetros los definen para el método de trapezoide irregular, vectores y punteros que no comprendo
  // test on-iregular (modelled regular to compare)
  std::vector<double> x(N), f(N);
  for (int ii = 0; ii < N; ++ii) {
    x[ii] = 0 + ii*(M_PI-0)/N;
    f[ii] = std::sin(x[ii]);
      }
  std::cout << "Non-regular integral is : " << trapezoid_irregular(x, f) << std::endl; //LLamado a la función de arriba 
  // test on regular
  std::cout << "Regular integral (n = 20) is : " << trapezoid_regular(0, M_PI, 20, std::sin) << std::endl; //Llamado a (It) con la función seno y 20int
  std::cout << "Regular integral (n = 40) is : " << trapezoid_regular(0, M_PI, 40, std::sin) << std::endl; //Llamado a (It) con la función seno y 40int
  // test with Richardson
  std::cout << "Richardson integral (n = 20) is : " << trapezoid_richardson(0, M_PI, 20, std::sin) << std::endl;//LLamdo a (ItR) con f=seno y 20 interv
  // test with Simpson
  std::cout << "Simpson integral (n = 20) is : " << simpson(0, M_PI, 20, std::sin) << std::endl; //LLamdo a (Is) con f=seno y 20 interv
       return 0;
     }
 
double trapezoid_irregular(const std::vector<double> & x, const std::vector<double> & fx) //No hablaré más de esta función 
{
  double sum = 0.0;
  for (int ii = 0; ii < x.size() - 1; ++ii) { // note the upper limit
    sum += (x[ii + 1] - x[ii])*(fx[ii] + fx[ii+1]);
  }
  return 0.5*sum;
}

double trapezoid_regular(const double a, const double b, const int n, fptr func)//Recibe los límites a y b, intervalos n, func=seno (en este caso)
{
  const double h = (b-a)/n; //Definición del tamaño de partición 
  double sum = 0.5*(func(a) + func(b)); //sum es un acumulador, realiza la suma que aparece en la fórmula en la presentación, solo le falta la sumatoria que en dicha fórmula aparece 
  for(int ii = 1; ii < n-1; ++ii) { // note limits. Se realiza la sumatoria que falta 
    double x = a + ii*h; //Se actualiza x según xi=a+i*h
    sum += func(x); // Se va agregando este resultado al acumulador sum 
  }
  return h*sum; //Después de agregar todos los términos de la sumatoria al acumulador sum, está queda completa, solo se multiplica por h según la fórmula y queda la integral de Trapezoide (It)
}

double trapezoid_richardson(const double a, const double b, const int n, fptr func)//Recibe los mismos límites: a,b #interv=n y f=sin
{
  return (4*trapezoid_regular(a, b, 2*n, func) - trapezoid_regular(a, b, n, func))/3; //Se realiza a través de la diferencia entre la función 4*(It) con 2n intervalos - (It) llamada con n intervalos
}

double simpson(const double a, const double b, const int n, fptr func) //Lo mismo que te envié, solo que aquí hacen explícito el llamado a la función sin entre los argumentos que recibe la función simpson. 
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
