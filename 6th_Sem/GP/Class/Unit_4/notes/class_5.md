> 28/03/23

#### Conventions, Idioms and Patterns

- Always use an available library / your own template class. Don't try to define that functionality again.

```cpp
#include<iostream>
#include<type-traits>

template <typename T>
struct identity {
    using type = T;
}

template <typename T>
struct add_pointer : identity<T*> ();
.
.
.
```

Hidden Parameters

- The second parameter may or may not be derived from the first parameter.
- One of the practices is to derive hidden parameters.

---

One use case is limiting number of instances

```cpp
#include<atomic>
#include<stdexcept>

template<typename T, size_t N>
struct limited_instances {
    static std::atomic<size_t> count;
    if (count >= N) {
        throw std::logic_error("Too many instances");
        ++count;
    }
    ~limited_instances() {--count;}
}

template<typename  T, size_t N>
std::atomic<size_t> limited_instances<T, N>::count = 0;

struct exaclibur : limited_instances<excalibur, 1>();
struct book_of_magic : limited_instances<book_of_magic, 3>();

int main() {
    excalibur e1;
    book_of_magic b1;
    book_of_magic b2;
    book_of_magic b3;
}
```

- This is often combined with run time polymorphism

```cpp
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
```

- Here the static_case is done at compile time but the calls in main are run time.
- This is LSP ? (Liskov Substitution Principle)

#### Type Erasure

