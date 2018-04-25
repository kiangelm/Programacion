#include <iostream>
#include <cmath>

const int M=4; //Tama�o de las matriz, definidas como variables globales
const int N=4;

bool is_orthogonal(const double M[][4], const double eps); //Recive una matriz de dimension M*4 y el intervalo de error epsilon
		   
int main (void)
{
  double A [M][N]={{1,0,0,0},
		   {0,0.8,0.3,-0.52},
		   {0,-0.6,0.4,-0.69},
		   {0,0,0.86,0.5}};
  double AT[M][N]={{1,0,0,0},
		   {0,0.8,-0.6,0},
		   {0,0.3,0.4,0.86},
		   {0,-0.52,-0.69,0.5}};
  double I[M][N]={{1,0,0,0},//Solo se define aqu� por claridad, no es necesaria
		  {0,1,0,0},
		  {0,0,1,0},
		  {0,0,0,1}};
  double AP[M][N]={{0.0}}; //Una matriz de M*N que se llena con ceros
  double eps=0.12; //Intervalo de error en la ortogonalidad
  
  //Se imprimen las matrices
  std::cout<<"Matriz original: \n";
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      std::cout << A[i][j] <<"\t";
    }
    std::cout << "\n";
  }
  
  std::cout<<"Matriz transpuesta: \n";
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      std::cout<<AT[i][j]<< "\t";
    }
    std::cout << "\n";
  }
  
  std::cout<<"Matriz identidad: \n";
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      std::cout<<I[i][j]<< "\t";
    }
    std::cout << "\n";
  } 
  
  std::cout<<"Matriz del producto: \n";
  double sum=0;
  for(int i=0; i<M; i++){
    for(int j=0;j<N;j++){
      sum =0;
      for (int k=0;k<M;k++){
	sum += A[i][k]*AT[k][j];
      }
      AP[i][j]=sum;
      std::cout << AP[i][j]<< "\t";
    }
    std::cout << "\n";
  }
  
  std::cout<<"Ortogonalidad:"<<std::endl;
  //Le env�o la matriz producto AP a la funci�n booleana, tambi�n el margen de error o tolerancia eps, y compruebo si es o no ortogonal
  if(is_orthogonal(AP,eps)==true){ 
    std::cout<<"La matriz es ortogonal con error: "<<eps<<std::endl;
  } 
  else{ //Si retorna falso, la matriz no es ortgonal
    std::cout<<"La matriz no es ortogonal en el rango +-: "<<eps<<std::endl;
  }
  return 0;
}



bool is_orthogonal(const double MAT[][4], const double eps){
  //A priori mi matriz es ortogonal b=true
  bool b=true;
  double I[M][N]={{1,0,0,0}, //Defino la matriz identidad, aqu� si es necesaria
		  {0,1,0,0},
		  {0,0,1,0},
		  {0,0,0,1}}; 
  for(int i=0; i<M ;i++){ //Empiezo a recorrer la matriz
    for(int j=0; j<N ;j++){
      
      if (std::fabs(MAT[i][j]-I[i][j])>eps){//Compruebo que cada elemento de la matriz que le env�e (en este caso AP) est� a una distancia eps del elemento correspondiente de la matriz Identidad. Si se sale de ese rango, b cambia a falso.
	std::cout<<"El elemento ("<<i<<","<<j<<") de M difiere del valor de la matriz Identidad"<<std::endl;
	b=false;
	break; //Con solo un elemento que no cumpla la condici�n, la matriz ya no ser� ortogonal, por eso rompo de una vez el proceso de iteraci�n
      }
    }
  }
  return b; //Si el if de arriba nunca se cumpli�, b qued� como verdadera, si el if se cumpli�, es decir, alg�n elemento de la matriz se sali� del rango de tolerancia respecto a la identidad, b cambi� a falso
}
