#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
  return 2*x*(1-x*x+x)*log(x)-(x*x)+1; 
}

double fprima(double x){
  return -2*(x-1)*(x+3*x*log(x)+log(x)+1);
}

double newton(double eps, int NMax)
{
  int i; 
  double x0,error, xold, xnew;

  x0=0.1;
  xnew=x0;
  for(i=0;i<=NMax;i++)
    {
      if(fabs(f(xnew)<=eps)) break;

      xold=xnew;
      xnew=xnew-f(xnew)/fprima(xnew);
      cout <<i<<"\t"<<xold<<"\t"<<xnew<<endl;
    }
 return xnew;
}

int main(void)
  
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  cout <<"La raiz es: "<<newton(1e-12,80)<<endl;
 
  return 0;
}
