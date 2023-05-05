#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <algorithm>

int main() {
    const int size = 1000000; // number of elements in the data set

    //* create a sorted vector of integers
    std::vector<int> vec;
    for (int i = 0; i < size; ++i) {
        vec.push_back(i);
    }

    //* create a set of integers
    std::set<int> s;
    for (int i = 0; i < size; ++i) {
        s.insert(i);
    }

    //TODO measure the time it takes to 
    //TODO find an element in the sorted vector
    auto start_vec = std::chrono::high_resolution_clock::now();
    //! Hint use binary search
    std::binary_search(vec.begin(), vec.end(), size - 1);
    auto end_vec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_vec = end_vec - start_vec;

    //TODO  measure the time it takes to find an element in the set
    auto start_set = std::chrono::high_resolution_clock::now();
    //! Hint use find
    s.find(size - 1);
    auto end_set = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_set = end_set - start_set;

    std::cout << "Time taken to find an element in a sorted vector: " << time_vec.count() << " seconds\n";
    std::cout << "Time taken to find an element in a set: " << time_set.count() << " seconds\n";

   //! Explain the difference 
   //! both use the same algo
   //! whose time complexity is ???
}
