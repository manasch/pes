> 06/03/23

##### Functors
- A function object , not a combination of functions and constructors.
- Functors are class objects that behave like functions. Perform different actions depending on the data type.
- Functor usually has only one method
```cpp
class MyFunctor() {
public:
    MyFunctor(int x) : value_(x) {}

    int operator()(int x) {
        return x * value_;
    }

private:
    int value_;
}

int main() {
    MyFunctor f(5); // Calls the constructor

    int result = f(10); // Will return 50
}
```

- Functor is not a constructor, they look similar.
- Functors maintain state unlike a regular function.

---

##### for_each()
```cpp
template <class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function fn) {
    while (first != last) {
        fn(*first);
        ++first;
    }
    return fn;
    // or move(fn);
}

void addOne(int& x) {
    x += 1;
    cout << x << " ";
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5};
    for_each(nums.begin(), nums.end(), addOne);
    // The third parameter can either be a function pointer, a functor or a lambda function.
    return 0;
}
```

- Function pointers can't be overloaded.
- For lambda functions, have to pass a separate lamda each type.
- Functors are compile time instantiations.
- To distinguise between function pointers
    - Either change name 
    - Or call with value `addOne(int)` `addOne(float)`

- Functions objects are not always faster.
    - Why would they be faster ?
        - Classes are better inline.
        - They make use of the state.

- Separates out the interface from the implementation.
- Functors do support type safety.
- Functors can be made polymorphic.

```cpp
class Functor {
public:
    virtual in operator()(int) = 0; // This is a pure virtual function
}
```