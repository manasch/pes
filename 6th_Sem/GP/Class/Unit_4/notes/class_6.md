##### Type Erasure

`vector<type>`
- type can be a class, struct, functor, function pointer, function, pointer....

How to create a vector which has `int`, `class`, `function` as it's members.

- Can create an interface (abstract class). An implementation in a container and using the interface to access the container.
- Can create a vector of interface , an abstract class, which can accept different types of implementations.

`std::unique_ptr`: can point to any pointer. It is called a smart pointer because when the pointer goes out of scope, the thing it is pointing to is deleted. Cannot do reassignment of the pointer.
`std::make_unique`: a type-safe way of connecting you to one object. It gets created on the heap.

```cpp
std::unique_ptr<ITypeErased> erased_int = std::make_unique<TypeErased<int>>(0);
```

Effectively you are cleaning up / erasing the datatype.

---

#### Mixin
- Reverse of CRTP, allowing you to mix types. Check slides

---

#### Tag Dispatch
- Based on the type passed, historical perspective (?).

---

C++ Done