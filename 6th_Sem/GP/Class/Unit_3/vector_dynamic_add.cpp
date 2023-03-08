#include <iostream>
#include <vector>

int main() {
    //* Create a vector of integers with initial capacity of 10
    std::vector<int> vec(10);

    std::cout << "Initial capacity: " << vec.capacity() << std::endl;

    //* Add 5 elements to the vector
    for (int i = 0; i < 5; i++) {
        vec.push_back(i);
    }

    std::cout << "Capacity after adding 5 elements: " << vec.capacity() << std::endl;

    std::vector<int>(vec).swap(vec);

    std::cout << "Capacity after trimming excess capacity: " << vec.capacity() << std::endl;

    return 0;
}
