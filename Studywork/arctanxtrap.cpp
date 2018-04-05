#include <iostream>
#include <cmath>

double trapezoid(const double a, const double b, const int  n);
double f(double x); 

int main(void){
  std::cout.precision(16); 
  std::cout.setf(std::ios::scientific);
  
  double a=0.0; 
  double b=1; 
  const int n=100;
  double exact=1.7182818;
  double I; 

  I=trapezoid(a,b,n); 
  std::cout<<"El valor de Int es aprox= "<<I<<std::endl;
  
  
  return 0;
}

double f(double x){
  return std::exp(x); //función que se integra
}

double trapezoid(const double a, const double b, const int  n){
  double h,sum=0.0; 
  double x; 
  h=(b-a)/n;
  for(int ii=1;ii<=n-1;++ii)
    { x=a+h*ii;
      sum+=f(x);
    }
  return h*(0.5*(f(a)+f(b))+sum); 
}
