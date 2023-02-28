> 21-02-23

- Pairs
```cpp
std::pair<E>()
std::make_pair(first, second)

std::pair<int> x;
x.first;
x.second;
```

- Allocator is more efficient as the memory is already allocated and is just pointed to.
- Malloc and calloc will only give as much memory requested, this will create space for more in the hope of being used more than the memory requested.
- Second arguement is the allocator.
```cpp
std::vector<int, std::allocater<int>>
```

- STL doesn't do out of bounds checking, no type checking.
- Assumes the programmer is intelligent.
- Won't throw an error unless another function is used.
- No virtual functions, (Has to go to a table to resolve, one layer of abstraction)
- .end() points to one element after the last element. (Helps in iterations)