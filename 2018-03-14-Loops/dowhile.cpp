#include <iostream>
double sumdowhile (int N)

{
  int n=1, sum=0;
  do {
    sum +=n;
    n++;
  }
  while (n<=N);
  return sum;
}

int main (void)
{
  std::cout << sumdowhile (100)<< std::endl;
  return 0;
}
