# Class 1

- Converting cpp to c code

```cpp
#include <iostream>

using namespace std;

class X {
    public:
        int a;
        void foo() {
            cout << "My a is " << a << endl;
            boo();
        }
    
    private:
        int boo() {
            cout << "Boo !" << endl;
        }
};

int main() {
    X a;
    return 0;
}

// Convert to C

/*
#include <stdio.h>

struct X {
    int a;
    void foo() {
        printf("My a is %d\n", a);
        boo();
    }

    int boo() {
        printf("Boo !\n");
    }
};

int main() {
    struct X a;
    return 0;
}

struct X {
    int a;
}

void foo(struct X* x) {
    printf("My a is %d\n", x->a);
}

int boo(struct X* x) {
    printf("Boo !");
}

*/
```

- Some instantiation

```cpp
#include <iostream>

using namespace std;

template<class T> class X {
    public:
        X* p;
        void f() {int i = 0;}
        void g() {int j = 0;}
};

int main() {
    X<int> *p;
    X<int> r;
    X<float> *q;
    // r.f();
    // q->g();
    return 0;
}
```

- Static var function

```cpp
#include <iostream>

using namespace std;

template<typename T>
class MyClass {
    public:
        static int counter;
        MyClass() {
            ++counter;
        }
};

template<typename T>
int MyClass<T>::counter = 0; // Doesn't get instantiated here, it's kept somewhere.

int main() {
    MyClass<int> x;
    MyClass<double> y;

    cout << MyClass<int>::counter << endl;
    cout << MyClass<double>::counter << endl;

    return 0;
}
```
