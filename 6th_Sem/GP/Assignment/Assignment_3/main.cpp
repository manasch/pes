#include <bits/stdc++.h>
#include "PES1UG20CS111_1.h"
#include "PES1UG20CS111_2.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v1{1, 3, 6};
    list<int> l1{2, 4, 5};

    cout << "Merging Containers" << endl << endl;

    // for (auto x: merged1) {
    //     cout << x << " ";
    // }
    // cout << endl;

    auto merged1 = merge_containers(v1, l1);
    assert((merged1 == vector<int>{1, 2, 3, 4, 5, 6}));
    
    vector<int> v2{1, 2, 3};
    list<int> l2{4, 5, 6};

    auto merged2 = merge_containers(l2, v2);
    assert((merged2 == vector<int>{1, 2, 3, 4, 5, 6}));

    vector<int> v3{1, 2, 3};
    list<int> l3{3, 4, 5};

    auto merged3 = merge_containers(v3, l3);
    assert((merged3 == vector<int>{1, 2, 3, 3, 4, 5}));

    vector<int> v4{};
    list<int> l4{};

    auto merged4 = merge_containers(v4, l4);
    assert((merged4 == vector<int>{}));

    vector<int> v(1000000, 0);
    list<int> l(1000000, 1);

    auto start = chrono::high_resolution_clock::now();
    auto result = merge_containers(v, l);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    cout << "Time: " << elapsed_seconds.count() << "s" << endl;
    cout << "Space: " << result.size() * sizeof(int) << "bytes" << endl;

    int score = 0;
    if (result.size() == v.size() + l.size()) {
        score += 5;
    }
    bool sorted = true;
    for (long unsigned int i = 1; i < result.size(); ++i) {
        if (result[i] < result[i-1]) {
            sorted = false;
            break;
        }
    }
    if (sorted) {
        score += 5;
    }
    if (elapsed_seconds.count() < 0.01) {
        score += 5;
    }
    if (result.size() * sizeof(int) < 2000000) {
        score += 5;
    }

    cout << "Score: " << score << "/20\n";

    // --------------------------------

    cout << endl << "-------" << endl;
    cout << "Unique Pairs" << endl << endl;;

    auto start1 = chrono::high_resolution_clock::now();

    vector<int> nums1 = {1, 2, 3, 4, 5, 6};
    int target_sum1 = 7;

    auto res1 = unique_pairs(nums1, target_sum1);

    if (!res1.empty()) {
        for (auto x: res1) {
            cout << x.first << " " << x.second << endl;
        }
    } else {
        cout << "Result is empty" << endl;
    }
    cout << endl;
    
    vector<int> nums2 = {-1, 2, 3, 4, 0, 6, -3};
    int target_sum2 = 3;

    auto res2 = unique_pairs(nums2, target_sum2);

    if (!res2.empty()) {
        for (auto x: res2) {
            cout << x.first << " " << x.second << endl;
        }
    } else {
        cout << "Result is empty" << endl;
    }
    cout << endl;

    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1};
    int target_sum3 = 2;

    auto res3 = unique_pairs(nums3, target_sum3);

    if (!res3.empty()) {
        for (auto x: res3) {
            cout << x.first << " " << x.second << endl;
        }
    } else {
        cout << "Result is empty" << endl;
    }
    cout << endl;

    vector<int> nums4 = {};
    int target_sum4 = 3;

    auto res4 = unique_pairs(nums4, target_sum4);

    if (!res4.empty()) {
        for (auto x: res4) {
            cout << x.first << " " << x.second << endl;
        }
    } else {
        cout << "Result is empty" << endl;
    }
    cout << endl;

    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds1 = end1 - start1;
    cout << "Time: " << elapsed_seconds1.count() << "s" << endl;

    return 0;
}
