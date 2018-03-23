#include <iostream>
#include <fstream>
#include <string>

void print_number(int max, std::string name); // para crear más de un archivo
int main (void)
{
  print_number(100, "datosfout.txt");
  print_number(200, "datosfout2.txt");

  return 0;
}

void print_number(int max, std::string name)
{
  std::ofstream fout(name);
  fout.precision(16); fout.setf(std::ios::scientific);
  for(int ii=1; ii<=max;++ii){
    fout << ii << "\t" << 1.0/ii << std::endl;
  }
  fout.close();
}
