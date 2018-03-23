#include <iostream>
#include <fstream>
void print_number(int max);
int main (void)
{
  print_number(100);
  return 0;
}

void print_number(int max)
{
  std::ofstream fout("datosej1.txt");
  for(int ii=1; ii<=max;++ii){
    fout << ii << "\t" << 1.0/ii << std::endl;
  }
  fout.close();
}
