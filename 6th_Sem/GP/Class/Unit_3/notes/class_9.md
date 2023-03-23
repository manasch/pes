> 13/03/23

#### Policies
- Custom
- Execution
- Evaluation
- Optimization
- Allocation

If I receive a certain condition, what should I do ?
- Has a fundamental difference on how the algorithm performs
- Implemented as a functor, a function pointer or lambda.

- Policy concept has been formalized in Cpp20, to separate implementation from interface.

69 of the 100 algorithms have an `execution policy`

```cpp
int main() {
    std::vector<int> v {1, 5, 2, 4, 3};
    std::sort(std::execution::seq, v.begin(), v.end());
    std::sort(std::execution::par, v.begin(), v.end());
    std::sort(std::execution::par_seq, v.begin(), v.end());
    
}
```

#### Vectorization

- Normally when performing operation on two vectors, the operation is done one by one.
- Vectorization allows for SIMD instruction with parallel instructions. By using a `_mm_load_ps` a special kind of register that allows for 128 bits, which can store 4 values at once, therefore speeding up the operations.
- Applying one instruction on multiple data at register level.
- Use `par_unseq`

---

- Allocators are also policies.
- Error Handling mechanisms through class interfaces are also policies.
- Exceptional Handler
```cpp
void myterminate() {
    std::cerr << "terminate handler called\n" << endl;
    abort();
}

int main (void) {
    std::set_terminate (myterminate);
    throw 0; // unhandled exception: calls terminate handler.
    return 0;
}
```

- Can continue running programs even if it causes an exception by forking the program, replacing the bad parts and continuing.

Evaluation Policy
- Transitive
- Irreflexive
- Asymmetric