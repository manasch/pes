#include <iostream>

template<typename Derived>
class Base {
    public:
    void foo() {
        static_cast<Derived*>(this)->fooImpl();
    }
};

class DerivedA : public Base<DerivedA> {
    public:
        void fooImpl() {
            std::cout << "DerivedA::fooImpl() called" << std::endl;
        }
};

class DerivedB : public Base<DerivedB> {
    public:
        void fooImpl() {
            std::cout << "DerivedB::fooImpl() called" << std::endl;
        }
};

int main() {
    DerivedA d1;
    DerivedB d2;

    d1.foo();
    d2.foo();

    return 0;
}
