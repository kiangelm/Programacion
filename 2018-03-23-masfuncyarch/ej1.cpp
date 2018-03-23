#include<iostream>
#include<cmath>
void print_number (double max);
int main(void)
{
  print_number(100);
  
  return 0;
 }
void print_number (double max)
{
  for (double ii=1.0;ii<=max; ++ii){
    std::cout << ii << "\t" << 1.0/ii << std::endl;}
}
