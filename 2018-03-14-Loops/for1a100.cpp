#include <iostream>
#include <cmath>
double sumfor (int N)
{
  int n=0, sum=0;
  for(n=1;n<=N;n++) {
    sum += n;
  }
return sum;
}

  int main(void)
  {
    std::cout<< sumfor (100) << std::endl;
  return 0;
}
