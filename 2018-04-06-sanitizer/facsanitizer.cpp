#include <iostream>

long factorial (long a)
{
  if (a > 1)
    return (a * factorial (a-1));
  else
    return 1;
}

int main ()
{
  long number = 99; //al utilizar sanitizer me dice el error
  std::cout << number << "! = " << factorial (number);
  return 0;
}
