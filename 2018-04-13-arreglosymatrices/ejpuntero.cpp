#include <iostream>

 int main(void)
 {
   int a = 67; //valor a
   int * ptr = 0; 
 
   ptr = &a; //guarda la direccion de a
 
   std::cout << a << std::endl;  //imprime el valor de a=67
   std::cout << &a << std::endl; //direccion de memoria de a 
 
   std::cout << ptr << std::endl; //direccion de memoria de a
   std::cout << *ptr << std::endl; //imprime el avor de a=67
   std::cout << &ptr << std::endl; //imprime direccion de memoria de ptr
 
   *ptr = 32; // igual a hacer a = 32;
   std::cout << a << std::endl;
 
   return 0;
 }
