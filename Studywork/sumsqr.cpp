#include <iostream>
#include <cmath>

int cuadrado(int n, int x2);
int main(void){
  int n=0;
  int x2=0;
  cuadrado(n, x2);
  return 0;
  
}
int cuadrado(int n,int x2){
  while(n<=500){  
    int xi=0;
    xi=n*n;
    n++;
    
    x2=x2+xi;
    std::cout<<n-1<<"\t"<<x2<<std::endl;
  }
  return x2; 
}
