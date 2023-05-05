> 13/02/23

- Inner classes have a life of their own without instantiating the outer class.
```cpp
#include <iostream>

class A {
 public:
  class B1 {
   public:
    int data1;
  };

  class B2 {
   public:
    int data2;
  };
};

int main() {
  A::B1 b1;
  b1.data1 = 10;
  std::cout << "Data in B1: " << b1.data1 << std::endl;

  A::B2 b2;
  b2.data2 = 20;
  std::cout << "Data in B2: " << b2.data2 << std::endl;

  return 0;
}
```

- Think of the outer class as a namespace.
