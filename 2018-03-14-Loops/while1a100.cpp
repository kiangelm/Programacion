#include <iostream>
double sumwhile (int N)

{
  int n=0, sum= 0;
  while (n<=N)//condición, mientra n sea menor o igual a N
    {
      sum+= n;//operador
    n++;
    }
  return sum;
 }

int main (void)
{
  std::cout<< sumwhile(100)<<std::endl;
  return 0;
}
