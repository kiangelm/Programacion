//from http://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
#include <random> //se inluye para usar random numbers
#include <iostream>

int main()
{
  int seed=0; //la semilla es cero para que sea reproducible
  std::mt19937 gen (seed);
  //std::uniform_real_distribution <> dis(1,2); //aleatoria (grafica valores en y entre 1.5 y 0.3
  std::normal_distribution <> dis(1.5,0.3); //normal (grafica todos los valores)
  for(int n=0 ; n<10000 ; ++n){
    std::cout << dis(gen) << '\n'; /*se usa dis para transformar el int generado por gen en un numero acorde con la distribucion elegida*/
  }
  std::cout << '\n';
}
