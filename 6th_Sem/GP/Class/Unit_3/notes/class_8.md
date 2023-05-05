> 09/03/23

#### Algorithms
- They operate over iterators rather than the contiainers.

Categories
- Non-mutating
- Mutating
- Sorting & sets
- Numeric

---

##### Non-modifying
```cpp
template <typename InputIterator, typename UnaryPredicate>
typename std::iterator_traits<InputIterator>::difference_type;
count_if(InputIterator first, InputIterator last, UnaryPredicate p);
```

##### Count_if example
```cpp
std::vector<int> vec = {3, 5, 7, 11, 15, 19, 23, 27};

int count = std::count_if(vec.begin(), vec.end(),
     [](int i){return i > 10;});
```

- Iterator type doesn't make a difference with time taken.
- Might be a good idea to not use a const_iterator.

- Use `find_if` instead of `count_if`.
- Recommendation: Use `find_if` in a loop over `count_if`.
---

- minmax - returns a pair of min and max values in a container.
```cpp
auto [min_it, max_it] = std::minmax_element(v.begin(), v.end());
```

- Don't use `it1 - it2`. Always use `std::distance(it1, it2);`

- Search
```cpp
std::search(v.begin(), v.end(), seq.begin(), seq.end(), is_double)
```

- `is_heap()` is not a trait, but a function.

- `reverse_copy()`: Copies the elements in the reverse order.

- `transform()`: Will transform the vector.
- `transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), add);`
