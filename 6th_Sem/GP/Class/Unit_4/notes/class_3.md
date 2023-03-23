### Trait Nesting

```cpp
template <typename T, typename = typename std::enable_if_t<std::is_arithmetic_v<T>, T>>
struct NnumericalValue {
    const value;
}

template <typename T>
NumericalValue<T> constexpr wrap(const T value) {
    return (value);
}
```

- This doesn't take anything apart from arithmetic.
- Is bool arithmetic ? Yes.

- This can be enabled at compile time. If type T is not arithmetic, it won't compile.
- To make it runtime, just remove `constexpr`

- Can you use `constexpr` in a switch ? It did not accept `constexpr` till cpp 17.

- Virtual functions are runtime instantiations for relevant calls. The overloading is pasted at compile time for normal overloading, but for virtual functions, it's pasted at runtime. An arbitary piece of code can be used at run time.

- Dynamic overloading happens only when the functions are virtual. These can be distinguished with the help of a trai. `is_polymorphic`

- Why do we need this, if we are only given the signature, cannot determine whether it is virtual or not, whether it has to be overrided, it can be inspected and action can be taken. If it is a pure virtual function then it must be overrided.
