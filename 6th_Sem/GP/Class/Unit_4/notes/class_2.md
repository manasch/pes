### Metaprogramming Using Macros

- They are a pain to use and maintain
```cpp
#define n 10
#define p 10 * 10

int main() {
    cout << p * p << endl;
}
```

This would give 120 instead of 400. Can't use `n` or `p` anywhere else.

Can also generate names say class at compile time. Has string concatenation as well.

`#` Stringification - Converts it to a string.
`##` Stringification + Concatenation - Concatenates the string.

Macros can be used for generating code.

```cpp
#define CLASS
#ifdef CLASS
#include <iostream>
#define DECLARE_CLASS(name) \
class MyClass_##name { \
public:
    void sayHello() {std::cout << "Hello from MyClass_" << #name << std::endl;}
};

DECLARE_CLASS(Foo);
DECLARE_CLASS(Bar);
DECLARE_CLASS(Baz);

int main() {
    MyClass_Foo foo;
    MyClass_Bar bar;
    MyClass_Baz baz;

    foo.sayHello();
    bar.sayHello();
    baz.sayHello();
    
}
#endif
```

`__LINE__`: Will give the current line number.
`__COUNTER__`: Is basically a static variable, an iterator, Increases in value every time it is called.

- Requires one level of indirection for generating variable names.
```cpp

```

- Can also do recursion, loops and so on.
- This is not turing complete. But you can almost generate everything.