#include<iostream>
#include <string>
using namespace std;
int main ()
{
  string str;

  std::cout << "¿Cuál es tu nombre?\n";

  std::cin >> str;

  std::cout << "¡Hola, " <<str<< "!\n";

  return 0;
}
