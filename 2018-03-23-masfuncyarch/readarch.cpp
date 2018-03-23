#include <iostream>
#include <fstream>
#include <string>
void read_number(std::string name);

int main(void)
{
  read_number("datosfout.txt");
  read_number("datosfout2.txt");
  
  return 0;
}

void read_number(std::string name)
  
{
  std::ifstream fin(name);//fin version de cin, es decir, leer
  int n;
  double x;
  double sum1;
  double sum2;
  while(fin) {
    fin >> n >> x;
    sum1 += n;
    sum2 += x;
  }
  std::cout << sum1 << "\t" << sum2 << std::endl;//imprime las dos sumas de los n y x que leyó read
  fin.close(); //cerrar el fin
}
