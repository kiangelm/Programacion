#include <iostream>
#include <cmath>

int main(void){
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  int i,N=200;
  double suma,pi1;
  
  suma=0.0;
  for(i=1;i<=N;i++){    
    suma=suma+1.0/(i*i);
    pi1=sqrt(6*suma);
    std::cout <<i<<"\t"<<suma<<"\t"<<pi1<<std::endl;
  }
  return 0;
}
