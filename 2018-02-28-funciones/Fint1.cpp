#include <iostream>
#include <string>

int max(int a, int b)

{
  int m = a;
  if(b>=a){
    m=b;
   }
  return m;
}

int main(void)
{
  std::cout <<max(5,1) << std::endl;
  std::cout <<max(-2,2) << std::endl;

  return 0;
}
