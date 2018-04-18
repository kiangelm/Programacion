#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

const int M = 100; //Valor que se va a usar como número de elementos


void initialize(std::vector<double> & a); //Función que va a llenar los elementos del vector
void print(const std::vector<double> & a); //Función para imprimir el vector

double mean(std::vector<double> & a); //Cálculo de la media
double desvest(std::vector<double> &a, const double nu); //Cálculo de la desviación estándar
double maximum(std::vector<double> & a);//Cálculo del máximo 
double minimum(std::vector<double> & a);//Cálculo del mínimo

int main(void)
{
  
  std::vector<double> data(M); //Vector llamado data con M entradas (se llena con 0s originalmente)
  std::vector<double> v{1,3,5,7,9,11,13}; //Vector de prueba (Se puede borrar)
  double nu,sigma,min,max; 
  
  
  initialize(data);//Se llama esta función con el vector llamado data para que sea llenado, que como se definió arriba es un vector de M entradas
  print(data);//Se imprime el vector data
  
  //Se calculan y posteriormente imprimen las funciones para el vector data
  nu=mean(data); 
  sigma=desvest(data,nu);
  max=maximum(data);
  min=minimum(data);
  std::cout<<"Media: "<<nu<<std::endl;
  std::cout<<"Desviación estándar: "<<sigma<<std::endl;
  std::cout<<"Máximo valor : "<<max<<std::endl;
  std::cout<<"mínimo valor : "<<min<<std::endl;
      
  return 0;
}





//Funciones

//Se pasa por referencia (&) el vector data y se le asigna la variable de memoria "a". 
void initialize(std::vector<double> & a){
  for(int i=0; i<a.size();i++){
    a[i]=i*i;//Aquí se describe como se quieren los elementos del vector a, en este caso el elemento a(i)=i^2.
  }
}

void print(const std::vector<double> & a)
{
  // print the array
  std::cout<<"[";
  for(int ii = 0; ii < a.size(); ++ii){
    std::cout << a[ii] << "\t";
  }
  std::cout<<"]";
}


double mean(std::vector<double> & a)
{
  double suma=0.0;
  int N=a.size();  //Se define la variable N como el tamaño [a.size()] del arreglo que se le pasa a la función (En este caso a=data, por lo cual N=M)
  for(int i=0; i<N;i++){
    suma=suma+a[i];
  }
  return suma/N;
}

double desvest(std::vector<double> &a, const double nu){
  double suma=0.0;
  int N=a.size();

  for (int i=0; i<N; i++){
    suma+=std::pow((a[i]-nu),2);
  }
  return std::sqrt(suma/(N-1));
}

double maximum(std::vector<double> & a){
  double M=a[0];
  int N=a.size();
  for(int i=0; i<N; i++){
    if (a[i]>M) M=a[i];
  }
  return M;
}

double minimum(std::vector<double> & a){
  double m=a[0];
  int N=a.size();
  for(int i=0; i<N; i++){
    if (a[i]<m) m=a[i];
  }
  return m;
}
