> 23/02/23

###### Separation of behaviours from containers.
- Separate functionality that operates on the container and the container itself.
    - Functionality that operates on the container, the behavior
    - From the container class itself

- Encapsulation
- Separation of concerns
- Algo different, Data management (algo) different, connect them through *iterators*

---

##### Sequence Containers
- Adaptor: Basically wrappers (dominantly of two types)
    - Queue
    - Stack
- Containers put data together to use them in some meaningful way.

- Keeping related data together.
- Naturally there exists a standardized way to manage them.
- Helps abstracting complex ideas.
  
    > Arrays are static, Vectors are dynamic, static creation is faster.

---

##### Safety vs Speed

- STL is built for speed.
- They don't do type checking.
- Performance guarantee.
- No iterator safety.
- Expects programmer to by intelligent.

---

##### Vectors

- Custom structs must have the equality operator, unequality operators.
- *Can keep this, but won't be able to perform any meaningful operations.*
- Not required to have any boolean operations.
- The dereferencing / referencing operator must be handled.
- Need to be iterable.

    - `v.begin()`: Pointer to the starting element.
    - `v.end()`: Pointer to the last + 1 element.
    - `v.front()`: Value of the first element.
    - `v.back()`: Value of the last element.

- Vectors don't have boundry checks.

---

##### Dequeue

- No specific implementation of dequeue.
- Allocator: Already keeps some prefetched allocations: `Capacity`.
- Supports `push_front` operator.

---

##### Lists

- They have mixed behaviors with containers.
    - Good for inserting elements in the middle.