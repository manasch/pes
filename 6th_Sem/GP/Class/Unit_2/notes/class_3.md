- Need to use full scope resolution operator to access parent class methods.

## About constructors

- Parameterised: 
```cpp
Grandfather(const T1&a, const T2&b): x(a), y(b) {}
```
- Copy
```cpp
class C;
C c1; // shallow copy
C c2(c1); // copy constructor (deep) [2 different locations created]
```
