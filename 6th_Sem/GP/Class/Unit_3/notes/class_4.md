> 27/02/23

##### Container Adaptors
- Queue / Stacks default container as deque.
- Pop shouldn't return something. Just use top to get the value.
- When not sure of the size of the container, use a vector. Returns elements in the order they are insterted.
- Can override what containers stack or queues use by default. (`std::stack<int, std:vector<int>>`)

---

##### Associative Containers
- Automatically sort their elements based on a specific ordering criterion
    - Set
    - Map -> Stores it in a binary tree
    - Unordered Set
    - Unordered Map
        - Both of these have a hash value mapping.

---

##### Iterators

- These are special pointers. They can be associated with any of the standard containers.
