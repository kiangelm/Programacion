#include <cmath>
#include <iostream>

double f(double x);
double deriv2_exact(double x);
double deriv2a(double x, double h);
double deriv2b(double x, double h);

int main (void)
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  
  const double x=M_PI/6.0;
  double h=0;
  double delta1,delta2;
  
  for(int i=1;i<=16;++i){
    
    h=M_PI*std::pow(10.0,-i);
    delta1=std::fabs(1.0-deriv2a(x,h)/deriv2_exact(x));
    delta2=std::fabs(1.0-deriv2b(x,h)/deriv2_exact(x));
    std::cout<<h<<"\t"<<delta1<<"\t"<<delta2<<"\n";
  }
      return 0;     
}

double f(double x)
{
  return std::cos(x);
}

double deriv2_exact(double x)
{
  return -1*std::cos(x);
}

double deriv2a(double x, double h)
{
  return ((f(x+h)-f(x))-(f(x)-f(x-h)))/(h*h);
}

double deriv2b(double x, double h)
{
 return (f(x+h)+f(x-h)-2*f(x))/(h*h); 
}
