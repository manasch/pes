### Meta Programming

- The input is a program, the process is a program, the output is a program.
- Program is treated as data.
- Everything is done at compile time. Nothing at runtime.
- Examples: `templates, partial specialization, traits, SFINAE`

- Traits: `type`, `value`.

- No mutability, no variables, no virtual functions. Everything has to be const.
- No runtime polymorphism, everything is compile time polymorphism.
- Don't try to inspect the code using RTTI, Run-time Type Inspection (Only when the classes have virtual functions, atleast one).
- Basically no dynamic, runtime binding.

---

- A metafunction is a templatized class or struct, parameters that are supplied to a template. Return is a particular member you inspect, by convention called `value` or `type`.

- `decltype`: declaration type, uses the type of n in `decltype(n)`
- `sizeof` is runtime compilation.
- `constexpr`: As far as possible, evalue these expressions at compile time. It is not a mandate.

- constexpr function, the whole function is evalutated at compile time.
- Everything that is passed to it should be const, if it is not const, then it will be evaluated at runtime. There will be a call during runtime.
```cpp
#include <iostream>

constexpr int fib(int n) {
    .
    .
}

int main() {
    int n = fib(10); // Compile time
    int a = 10;
    const int fib(a); // Run Time call.
}
```
