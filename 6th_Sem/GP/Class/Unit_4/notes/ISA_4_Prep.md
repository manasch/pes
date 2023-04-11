RTTI - Run-Time Type Identification: A mechanism where an object's data type can be found out at run time and this is only available to those classes that have atleast one virtual function.

Ex: typeid from typeinfo

Metafunction: A way of expressing compile time computation using template metaprogramming.

`(n) is an lvalue`

therefore
```cpp
int foo();
decltype(n) a = 10;
decltype((n)) b = a // b is of int pointer type
decltype(foo()) c = foo(); // rvalue int
```

```cpp
// This is compile time
fib(10);

// This is runtime
int a = 10;
fib(a);
```

- Can use enum {} and it is supposedly done at compile time , cuz it works :thumbsup:

- Metafunction can also produce a type as its result.
- decltype is used to deduce the type of a an expression at compile time.

```cpp
// This is compile for some reason
int a = Fact<15>();
cout << a << endl;

// But this is not
cout << Fact<15>() << endl;
```

---
I give up

---

- Macros require a layer of indirection

```cpp
#define COUNTER(a, b) COUNTER_INNER(a, b)
#define COUNTER_INNER(a, b) a##b
#define UNIQUE_NAME(base) COUNTER(base, __LINE__)
```

```cpp
#include <iostream>

#define LOG_FUNCTION(func_name) \
void func_name##_impl(); \
void func_name() { \
    std::cout << "Started " << #func_name << std::endl; \
    func_name##_impl(); \
    std::cout << "Finished " << #func_name << std::endl; \
} \
void func_name##_impl()


LOG_FUNCTION(my_function) {
    std::cout << "Hello, World!" << std::endl;
}

int main() {
    my_function();
    return 0;
}
```

- use ##`_impl` to get a function's implementation.

---

```cpp
#include <iostream>
using namespace std;
// is compile time
constexpr fact(int n) {
    return (n == 0) ? 1 : n * fact(n - 1);
}

// is compile time
constexpr unsigned int fact(unsigned int n) {
    return n > 1 ? n * fact(n - 1) : 1;
}

int main() {
    auto x = fact(5);
    cout << x;
    int y = 10;
    auto p = fact(y); // is run time.
}
```

-  Even constructors can be made compile time by using constexpr.

---

- If base class is not polymorphic, then even child class is not polymorphic if inherited normally.

- Tried inheriting virtually from a non-polymorphic class, still not polymorphic.

---

- So supposedly virtual function is not there but it's totally there so idk

If `virtual` is mentioned before the function in the base, then it's binding is delayed till runtime and can be overridden by it's child class hence the same function name will be referred to the child's class.

- virtual constructor's don't exist but virtual destructors do exist.

This is in the context of 
```cpp
Base *p = new Derived();
delete p;
```

if the destructor is not virtual for the base class, then when a base class pointer is created and then later deleted, it won't destroy the child classes.

basically
if virtual base class destructor --> good
as it destroys child class as well.

---

CRTP -- Curiously Recurring Template Pattern

- A way to implement compile time polymorphism

We try to use the derived class's implementation from the base class which is what we achieve if we just use virtual methods.

- Example
```cpp
#include <iostream>
#include <vector>

template <typename Derived>
class Shape {
public:
    void draw() {
        static_cast<Derived*>(this)->draw_impl();
    }
};

class Circle : public Shape<Circle> {
public:
    void draw_impl() {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape<Square> {
public:
    void draw_impl() {
        std::cout << "Drawing a square." << std::endl;
    }
};

int main() {
    Circle circle;
    Square square;

    std::vector<Shape<Circle>*> circle_shapes;
    circle_shapes.push_back(&circle);

    std::vector<Shape<Square>*> square_shapes;
    square_shapes.push_back(&square);

    for (const auto& shape : circle_shapes) {
        shape->draw();
    }

    for (const auto& shape : square_shapes) {
        shape->draw();
    }

    return 0;
}
```

---

Variadic

in template and function calls of Args
`template<typename...Args>` `sizeof...(Args)`
everywhere else
`Args... args` `args...`

When variadic templates are used. It should be expanded again by using `...`

##### Types of folds
- Unary right fold: (pack op ...) --> (1 + (2 + (3 ....(n-1 + n))))
- Unary left fold: (... op pack) --> (((1 + 2) + 3) ...)
- Binary right fold: (pack op ... op init) --> (arg1 op (arg2 ( op arg3 ...)))
- Binary left fold: (init op ... op pack) --> ((((init op arg1) op arg2) op arg3))

---

Refer to [class_6](./class_6.md) notes for type erasure.


---

Forgot something

std::function allows you to store a free function pointers

```cpp
void my_func(int x) {...}

std::function<void(int)> fp;
```

void is the return type and int is the parameter type.


Mixin: Upside down of CRTP, they inherit from the classes that they are supposed to add functionality to.

---

CRTP identify:

```cpp
// base class

template<typename Derived>
struct base {
    void some_func() {...}
};

struct derived : public base<derived> // here you specialize the class you're trying to define itself. {
    void func() {...} // some_func will call this.
}
```

Mixin identify:

```cpp
// They are the exact opposite of CRPT, the child class derived from the class they are supposed to define the functionality of.

struct t1
{
    ...
}

struct t2
{
    ...
}

template<typename T> // T could be t1 or t2
struct mix : T {
    // Define common functionality
}
```