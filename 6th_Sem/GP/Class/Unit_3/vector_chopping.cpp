#include <iostream>
#include <vector>
#include <chrono>

int main() {
    // create two large vectors
    const int size = 100000000;
    std::vector<int> v1(size);
    std::vector<int> v2(size);
    for (int i = 0; i < size; ++i) {
        v1[i] = i;
        v2[i] = i + size;
    }
    auto start_time = std::chrono::high_resolution_clock::now();
    // for (int i = 0; i < size/2; ++i) {
    //     v1[i] = v2[i + size/2];
    // }
    v1.assign(v2.begin() + size / 2, v2.end());
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Time taken by for loop: " << time_diff.count() << " ms" << std::endl;
    // TODO - Do something to reduce
    // TODO by a factor of 10
    return 0;
}
