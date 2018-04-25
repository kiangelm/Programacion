#include <iostream>
#include <eigen3/Eigen/Dense>

int main()
{
  // X = Dynamic size
  // d = double
  Eigen::MatrixXd m(3,3); 
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  m(0,2) = m(1,1) + m (0,0);
  m(1,2) = m(1,1)+1;
  m(2,0) = 3;
  m(2,1) = 1;
  m(2,2) = 2;
  std::cout << m << std::endl;
}
