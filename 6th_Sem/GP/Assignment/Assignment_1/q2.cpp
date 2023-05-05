//correct the following code 1 point
// template <typename T> T f2(int &T);
// inline template <typename T> T foo(T, unsigned int*);

template <typename T>
inline T foo(T arg, unsigned int* size)  {
    return f2<T>(arg, size);
}

template <typename T>
T f2(T &arg, unsigned int* size) {
    // function implementation
}
