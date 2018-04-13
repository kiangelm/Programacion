#include <iostream>

const int N=5;
const int M=3;

int main (void)
{
  double A [M][N]={{0.0}};
  double AT [N][M] = {{0.0}};
  //fill matrx
  for (int ii=0; ii<M; ++ii){
    for(int jj=0; jj<N ; ++jj){
      A[ii][jj]= 1+ii*jj;
    }
  }
  
  //transpuesta
  for (int ii=0; ii<M; ++ii){
    for(int jj=0; jj<N ; ++jj){
      AT[jj][ii] = A[ii][jj];
    }
  }
  
  //PRINT MATRIX
  std::cout<< "Matriz original: \n";
  for(int ii=0 ; ii<M ; ++ii){
    for(int jj=0 ; jj<N ; ++jj) {
      std::cout << A[ii][jj]<< " ";
    }
    std::cout<< "\n";
      }
  //PRINT TRANSPUESTA
  
  std::cout << "Matriz transpuesta: \n";
  for(int ii=0 ; ii<N ; ++ii){
    for(int jj=0 ; jj<M ; ++jj) {
      std::cout << AT[ii][jj]<< " ";
    }
    std::cout<< "\n";
      }
  return 0;
}

	 
