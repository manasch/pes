> 23/03/23

#### Early binding

```cpp
class A {
    public:
        void disp() {
            cout << "Message A";
        }
};

class B : public A {
    public:
        void disp() {
            cout << "Message B";
        }
};

int main() {
    A *obj1;
    B obj2;
    obj1 = &obj2;
    obj1->disp();
    return 0;
}
```

- This will print `Message A`

If the A class disp function is declared virtual, then it will print `Message B`
- Virtual allows you to change the disp() at `runtime`, that is `late binding` or `dynamic binding`.
- Virtual delays the binding to `runtime`.

- Virtual contructors don't exist, but virtual destructors do exist.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Base class's destructor." << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived class's destructor." << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr; // Call the base class destructor
    return 0;
}
```

- if base destructor is not virtual, then only the base classes' memory is deleted. But if virtual is mentioned, then first child's then parent's get deleted.

Pure Virtual
```cpp
virtual func() = 0;
```

- This has to be overridden.
- As many number of virtual tables as there are virtual functions.

---

CRTP - Curiously Recurring Template Parameters.

```cpp
template <typename... Args>
class Tuple {
public:
    Tuple(Args... args) : values(args...) {}

private:
    std::tuple<Args...> values;
}
```

Args - Contains the types
args - Contains the values