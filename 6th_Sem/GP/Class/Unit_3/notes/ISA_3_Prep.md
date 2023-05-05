STL Philosophy

- Type-Safe access to data.
- Fast
- Easy traversal

Generalize Algorithms: Lifting the algorithm

- Only 4 standard algorithms specifically do computation:
    - Accumulate
    - inner_product
    - partial_sum
    - adjacent_difference

- Algorithms are separate, Containers are separate. Integrate them together using iterators.

- 10 containers, 60 algorithms.
- The iterator to the end of a container points to `last + 1`;

---

##### Predicate
- A function or a function object that takes an arguement and returns a bool.
---

- Iterators
    - subscript style doesn't work for lists.

---

### Containers

- An object that allows us to collect other objects together and interact with them in some way.

Types of containers:
- Sequence:
    Accessed sequentially, anything with order

- Associative:
    Not necessarily in a sequential order, easily searched, maps sets

- STL is fast because there's no boundry checking.

For vectors, once it passes the initially allocated space, the vector resizes to adjust for new values, hence.
```cpp
std::vector<int> v1 {1, 2, 3};
auto it = v1.begin();
v1.push_back(4); // Invalidates iterator 'it'
if (it == v1.begin()) {
    std::cout << "They are the same\n";
} else {
   std::cout << "Not the same\n";
}
```

- This will print `not same`. There is no `iterator safety`
- Also no type safety

---

##### Container Adaptors

- Stack and Queue: Can be implemented by using a dequeue.
---

- Copy function
```cpp
copy(v1.begin(), v1.end(), std::back_insertor(v2));
```

Just mentioning v2.begin() was throwing an error;

list
`merge()`- Requires list to be sorted.

##### Vectors

- If objects passed to a vector, it is pass by value by default.
- To change this behaviour, make it pass by reference.
- If a vector is of base class type, and it holds derived class objects, then the objects begin to behave as base class. To change this behaviour, pass it by reference.
- But if a base class pointer is poined to a derived class object, with the derived class overriding a function from the base class, it will use the derived class function.

##### Maps

- When using `[]` it will replace the existing value with the new value.
- When using `.insert({first, second})` it will just ignore the new value.

---

### Associative Containers

- Sort their elements based on specific order criterion
- Typically implemented as binary trees.

### Unordered Containers

- `unordered_set`,`unordered_map` are implemented with the help of hash table. Thus internally it is an array of linked lists.

---

### Iterators

- Iterators allow traversal / iteration over any container. Be it seqential, associative or unordered
- Iterators help us to view a non-linear collection in a linear manner.


- list's iterator can't perform math.

Types of iterators:
    - Input
    - Output
    - Forward
    - Bidirectional
    - Random Access

- Input Iterator: Can be dereferenced on the rhs.
```cpp
vector<int>::iterator itr = v.begin();
int val = *itr;
```

- Ouptut Iterator: Lhs
```cpp
Vector<int>::iterator itr = v.begin();
*itr = 12;
```

- Forward Iterator: Combines input and output

- Bidirectional:
```cpp
++itr;
--itr;
```

- Random Access:
```cpp
itr = itr + 3;
```

---

### Functors

- Objects that behave like functions
- They are just classes or structs with just one operator (typically) overloaded function.
- They maintain state.

```cpp
for_each(v.begin(), v.end(), addOne{})
```

---

#### type-traits

- Compile time template metafunctions.
- Useful in conditional compiliation