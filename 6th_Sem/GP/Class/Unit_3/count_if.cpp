#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {1, 3, 3, 4, 5, 5, 6};
    int duplicates = 0;

    for (auto it = arr.begin(); it != arr.end(); ++it) {
        int count = 0;
        for (auto jt = it + 1; jt != arr.end(); ++jt) {
            if (*it == *jt) {
                ++count;
            }
        }

        if (count >= 1) {
            ++duplicates;
        }
    }
}

// Convert this to count_if in the inner loop
