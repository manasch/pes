#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2(5);
    vector<int> v3(5);

    reverse_copy(v1.begin(), v1.end(), v3.begin());
    auto it = copy_if(v3.begin(), v3.end(), v2.begin(), [](int i){return (i % 2 == 1);});

    for (auto x: v2) {
        cout << x << " ";
    }
}
