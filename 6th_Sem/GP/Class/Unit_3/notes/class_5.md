> 02/03/23

##### Base and Derived container behaviour
- By default when passing objects to a vector, it is pass by value.
- If call an object by reference, the derived object is called, but if you pass by value then the base is called.

- Vector which has base classes, into this if you pass the derived classes, the derived class objects behave as the base class. Pass the pointers to fix this.
- This is known as slicing. Passing derived class to a base class container, this will slice the derived class stuff and only pass the base class.
- To get the expected behaviour, pass pointers.

---

- Creating a dynamic array and trying to delete it twice, might just silently compile, might just crash / hang. Undefined behaviour.
  
- Swap is fast cuz it does a memcopy.
- Let there be a vector with size 10, adding a value to this, will make the size 11, but capacity would be 20 (*or something else*). But if you use swap with a temporary vector, it will have the exact capacity required.
```cpp
std::vector<int>(vec).swap(vec);
```
- The temporary vector will have the same capacity as the original vector, the swap will only create as much capacity required.

---

- Set is faster in search, but in size vector takes lesser size.
- Assign method does memcopy which is faster.

- Maps, inserting using `.insert()` will ignore new values for the same key, it won't check if the key is already in the map. `[]` will reassign the value.

---

##### Iterator

```cpp
std::set<int>::iterator
```

- Iterators let us view a non-linear collection in a linear manner.
- map iterators are different, dereferencing a map iterator will give a pair.
```cpp
std::map<int, int>::iterator i;
(*i).first.
```

- Sort uses an iterator.

##### Types of iterator

1. Forward
2. Random Access
3. Bidirectional
4. Input
5. Output

- Input iterator: The r-value, the value that's in the iterator.
```cpp
auto iter = *itr;
auto *itr = iter;
```