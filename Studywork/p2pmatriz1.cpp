#include <iostream>
#include <cmath>

const int M=4; 
const int N=4;

bool is_orthogonal(const double M[][4], const double eps); 
		   
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
  double I[M][N]={{1,0,0,0},
		  {0,1,0,0},
		  {0,0,1,0},
		  {0,0,0,1}};
  double AP[M][N]={{0.0}}; 
  double eps=0.012; 
  
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
   if(is_orthogonal(AP,eps)==true) { 
    std::cout<<"La matriz es ortogonal con error: "<<eps<<std::endl;
  } 
   else { 
    std::cout<<"La matriz no es ortogonal en el rango +-: "<<eps<<std::endl;
  }
  return 0;
}

bool is_orthogonal(const double MAT[][4], const double eps)
{
  bool b=true;
  double I[M][N]={{1,0,0,0}, 
		  {0,1,0,0},
		  {0,0,1,0},
		  {0,0,0,1}}; 
  for(int i=0; i<M ;i++){ 
    for(int j=0; j<N ;j++){
      
      if (std::fabs(MAT[i][j]-I[i][j])>eps){
	std::cout<<"El elemento ("<<i<<","<<j<<") de M difiere del valor de la matriz Identidad"<<std::endl;
	b=false;
	break;
      }
    }
  }
  return b;
}
  
