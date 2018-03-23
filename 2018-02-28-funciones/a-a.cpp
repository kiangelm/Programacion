#include <iostream>

int addition (int a, int b)
{
  std::cout << &a << std::endl;
  int r;
  r = a + b;
  return r;
}

int main(void)
{
  int c, a, b;
 std::cout << &a << std::endl;
  a = 3;
  b = 5;
  c = addition(a,b);
  std::cout << "the result is" << c;
  return 0;
}
  
  
