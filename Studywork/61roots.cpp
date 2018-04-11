#include <iostream>
#include <cmath>

double f(double x); //función original
double g(double x); //x=g(x) (según el método)
double fixpoint(double x0, double N, double eps); //recibe parámetro inicial x0, número de iteraciones máximas N, y tolerancia eps

int main(void){
  double x0=0.5; //Parámetro inicial o semilla
  int N=100; //Si no converge, haga a lo máximo 100 iteraciones
  double eps=0.01; //Nivel de tolerancia f(raiz encontrada)=eps 
  std::cout<<"La raíz de f(x) es: "<<fixpoint(x0,N,eps)<<std::endl; 
  
  return 0;
}

double f(double x){
  return std::sin(std::sqrt(x))-x; //f(x)=sin((x)^1/2)-x
}

double g(double x){
  return std::sin(std::sqrt(x));//g(x)=sin((x)^1/2)
}

double fixpoint(double x0, double N, double eps){
  double xi=x0; //Inicializo la variable xi=x0 
  for(int ii=0;ii<=N;++ii){
    if(fabs(f(xi))<=eps) break; //Si f(x) approx 0, según el criterio eps, acabe las iteraciones a través de break
    xi=g(xi);  //x_i+1=g(xi)
  }
  return xi; //Envía el valor encontrado de la raiz (no siempre converge)
}
