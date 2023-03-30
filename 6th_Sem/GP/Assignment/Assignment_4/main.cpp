/*C++ Metaprogramming Library

Assignment: Implement a compile-time metaprogramming library using macros, variadic templates, constexpr, and specialization in C++. The library should support the following functionality:

Compute the Nth Fibonacci number at compile-time, where N is a compile-time constant integer.
Generate a compile-time sequence of prime numbers up to a given limit, where the limit is a compile-time constant integer.
Implement a type trait that determines if a type is a container type (i.e. a class that provides a size() and operator[] member function).
Implement a compile-time sorting algorithm for an array of compile-time constant integers using variadic templates and constexpr.
Implement a function that takes a function object and a compile-time constant integer as arguments and returns the result of applying the function object to itself N times, where N is the compile-time constant integer.
To complete the assignment, follow these steps:

Create a new C++ project in your preferred development environment.
Implement the functionality listed above using macros, variadic templates, constexpr, and specialization.
Test the library by writing test cases for each of the functions and running them to ensure they produce the expected results.
Optimize the code for performance by using techniques like memoization, lazy evaluation, and loop unrolling.
Submit your code along with a brief report outlining your design choices and performance optimizations.
Good luck! This assignment is intended to be challenging, but it will also give you a chance to practice your C++ skills and learn about the power of compile-time metaprogramming.  */
#include <iostream>
#include <array>
#include <type_traits>

// Problem 1: Compute the Nth Fibonacci number at compile-time, where N is a compile-time constant integer.

// TODO: Implement a compile-time template function that computes the Nth Fibonacci number.
template<int N>
constexpr int fibonacci = fibonacci<N - 1> + fibonacci<N - 2>;

template<>
constexpr int fibonacci<0> = 0;

template<>
constexpr int fibonacci<1> = 1;

// Problem 2: Generate a compile-time sequence of prime numbers up to a given limit, where the limit is a compile-time constant integer.

// TODO: Implement a compile-time template struct that generates a sequence of prime numbers up to the given limit.
template<int Limit>
struct primes {
    constexpr static std::array<int, Limit> value = []() constexpr {
        std::array<int, Limit> val{};
        size_t i = 2;
        size_t index = 0;
        while (i < Limit) {
            bool flag = true;
            for (size_t j = 2; j < i; ++j) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                val[index++] = i;
            }
            ++i;
        }
        
        return val;
    }();
};

// Problem 3: Implement a type trait that determines if a type is a container type (i.e. a class that provides a size() and operator[] member function).

// TODO: Implement a compile-time template struct that determines if a type is a container type.
template<typename T>
struct is_container {
    template<typename U>
    static std::true_type container(typename U::iterator*);
    
    template<typename U>
    static std::false_type container(...);
    
    static constexpr bool value = decltype(container<T>(nullptr))::value;
};

// Problem 4: Implement a compile-time sorting algorithm for an array of compile-time constant integers using variadic templates and constexpr.

// TODO: Implement a compile-time sorting algorithm for an array of compile-time constant integers.
template<int... Numbers>
struct sort {
    static constexpr size_t size = sizeof...(Numbers);
    static constexpr int arr[size] = {Numbers...};
    static constexpr int temp;

    constexpr int i, int j;
    for (constexpr i = 0; constexpr i < size - 1; constexpr ++i) {
        for (constexpr j = 0; constexpr j < size - 1; constexpr ++j) {
            if (arr[j] > arr[j + 1]) {
                constexpr temp = arr[j];
                constexpr arr[j] = arr[j + 1];
                constexpr arr[j + 1] = temp;
            }
        }
    }
};

// TODO: Define a type alias that uses the sorting algorithm to generate a sorted array of compile-time constant integers.
// template<int... Numbers>
// using sorted_array = sort<...Numbers>;

// Problem 5: Implement a function that takes a function object and a compile-time constant integer as arguments and returns the result of applying the function object to itself N times, where N is the compile-time constant integer.

// TODO: Implement a compile-time template struct that applies a function object to itself N times.
template<int N, typename F>
struct self_apply {
    // ...
};

// TODO: Define a constexpr variable template that uses the self_apply struct to apply a function object to itself N times.
template<int N, typename F>
constexpr auto self_apply_v = ;

int main() {
    // Problem 1: Test the implementation of fibonacci.

    static_assert(fibonacci<0> == 0, "fibonacci<0> should be 0");
    static_assert(fibonacci<1> == 1, "fibonacci<1> should be 1");
    static_assert(fibonacci<2> == 1, "fibonacci<2> should be 1");
    static_assert(fibonacci<3> == 2, "fibonacci<3> should be 2");
    static_assert(fibonacci<4> == 3, "fibonacci<4> should be 3");
    static_assert(fibonacci<5> == 5, "fibonacci<5> should be 5");

    // Problem 2: Test the implementation of primes.

    constexpr auto primes_10 = primes<10>::value;
    static_assert(primes_10[0] == 2, "primes<10>[0] should be 2");
    static_assert(primes_10[1] == 3, "primes<10>[1] should be 3");
    static_assert(primes_10[2] == 5, "primes<10>[2] should be 5");
    static_assert(primes_10[3] == 7, "primes<10>[3] should be 7");

    // Problem 3: Test the implementation of is_container.

    static_assert(is_container<std::array<int, 5>>::value, "std::array<int, 5> should be a container type");
    // Add your own for 4 and 5

    return 0;
}
