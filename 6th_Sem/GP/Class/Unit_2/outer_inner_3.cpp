#include <iostream>
template <typename T>
class A {
 public:
  template <typename U>
  class B1 {
   public:
    U d1;
  };
  template <typename V = T> 
  class B2 {
   public:
    V d1;
  };
};

int main() {
  A<double>::B1<int> b1;
  b1.d1 = 10;
  std::cout << "Data in B1: " << b1.d1 << std::endl;

  A<double>::B2<> b2;
  b2.d1 = 20.0;
  std::cout << "Data in B2: " << b2.d1 << std::endl;

  return 0;
}
