#include <iostream>

template <typename T>
class OuterClass {
 private:
    int val = 1;
 public:
  template <typename U>
  class InnerClass {
   public:
    void printOuter(OuterClass<T>& oc) {
        std::cout << oc.inner.data << std::endl;
    }
    U data;
  };

  InnerClass<T> inner;

  void setData(T data) { inner.data = data; }
  T getData() { return inner.data; }
};

int main() {
  OuterClass<int> outer;
  outer.setData(5);
  std::cout << "Data in outer class: " << outer.getData() << std::endl;
  outer.inner.printOuter(outer);
  return 0;
}
