#include <iostream>

class A {
 public:
  static const int x = 10;
  class B1 {
   public:
    int data1;
  };

  class B2 {
   public:
    int data2;
  };
};

class C : public A :: B1 {

};

int main() {
  A::B1 b1;
  b1.data1 = 10;
  std::cout << "Data in B1: " << b1.data1 << std::endl;
  std::cout << A::x << std::endl;

  A::B2 b2;
  b2.data2 = 20;
  std::cout << "Data in B2: " << b2.data2 << std::endl;

  C::B1 b3;
  std::cout << "C Class: " << b3.data1 << std::endl;

  return 0;
}
