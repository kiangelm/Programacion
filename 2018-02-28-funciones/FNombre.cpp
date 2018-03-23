#include <iostream>
#include <string>

void printhw(std::string name1, std::string name2)
{
  std::cout<< "Hola " <<name1<<" "<<name2<< "\n";
}
int main(void)
{
  std::string k= "Karen", i="Ivon";
  
  printhw(k,i);

  return 0;
}
