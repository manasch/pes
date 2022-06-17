#include <iostream>
#include <vector>

using namespace std;

// Using the backtracking method
/*
f(123, 1, [])
--f(23, 2, [1])
----f(3, 3, [12])
------123
----X
--f(13, 2, [2])
----f(3, 3, [21])
------213
----X
--f(12, 2, [3])
----f(2, 3, [31])
------X
----f(1, 1, [32])
------321
*/

class Solution {
    int countArrangement(int n) {
        int all = 0;
        vector<int> available(n + 1, true);
        f(n, available, 1, all);
        return all;
    }

    void f(const int n, vector<int>& available, int idx, int& all) {
        if (idx > n) { // have a valid permutation
            all++;
        } else {
            for (int i = 1; i < available.size(); i++) {
                if (available[i]) {
                    if (i % idx == 0 || idx % i == 0) {
                        available[i] = false;
                        f(n, available, idx + 1, all);
                        available[i] = true;
                    }
                } else {
                    // branch pruning
                }
            }
        }
    }
};