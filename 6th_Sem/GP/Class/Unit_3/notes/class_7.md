> 07/03/23

##### Type Traits
- Gives characteristics about adata type.
- Java has reflection, but cpp doesn't have reflection.
- These are compile time template metafunctions that return info about types.

##### Metaprogramming
- Treating programs as data

---

```cpp
struct A {
    A(const A&) = delete;
    ~A() noexcept(false) {}
};
```
- Doesn't allow it to handle exception.
- Programming about programs.

> There are 14 types in C++

    1. void
    2. integral
    3. floating point
    4. nullptr
    5. class
    6. array
    7. pointer
    8. rvalue reference
    9. lvalue reference
    10. union
    11. enum
    12. function
    13. member object pointer
    14. member function pointer

---

- Basic idea is changing the behaviour based on the data type.

- Trivial Destructor: Can just remove it directly.
- Non-Trivial Destructor: Have to remove ancestors, more expensive.

---

##### SFINAE - Substitution Failure Is Not An Error

- Do this later.
---

