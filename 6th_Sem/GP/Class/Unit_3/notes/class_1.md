> 20-02-23

# STL - Standard Library

- STL is type safe
- STL is light weight and fast.
- STL is regular; What do you mean by regular ?
    - Exposing only what is required
    - Not exposing what is not required
    - Separation of implementation from the interface.
    - Ensure that whenever you have a class, you havea default, parametrized, copy constructors, proper moves and proper destructors.
    - If operator overloading, handle them the same way.
 ---
Generalizing algorithms - Lifting an algorithm.

```cpp
++++++n // is a valid statement, increments n by 3
n++++++ // is not
```

- Iterators are basically just pointers, they mesh algos with containers.
- Iterator is a functor, a class. Therefore it has been overloaded.
- Class defined within a container.
