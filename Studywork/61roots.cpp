#include <iostream>
#include <cmath>

double f(double x); //funci�n original
double g(double x); //x=g(x) (seg�n el m�todo)
double fixpoint(double x0, double N, double eps); //recibe par�metro inicial x0, n�mero de iteraciones m�ximas N, y tolerancia eps

int main(void){
  double x0=0.5; //Par�metro inicial o semilla
  int N=100; //Si no converge, haga a lo m�ximo 100 iteraciones
  double eps=0.01; //Nivel de tolerancia f(raiz encontrada)=eps 
  std::cout<<"La ra�z de f(x) es: "<<fixpoint(x0,N,eps)<<std::endl; 
  
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
    if(fabs(f(xi))<=eps) break; //Si f(x) approx 0, seg�n el criterio eps, acabe las iteraciones a trav�s de break
    xi=g(xi);  //x_i+1=g(xi)
  }
  return xi; //Env�a el valor encontrado de la raiz (no siempre converge)
}
