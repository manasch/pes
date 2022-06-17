#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            multiset<int> set; // To allow duplicate values
            for (int i = 0; i < nums.size(); i++) {
                set.insert(nums[i]);
            }

            vector<int> sorted(nums.size());
            int i = 0;
            for (int key : set) {
                sorted[i++] = key;
            }

            return sorted;
        }
};

int main() {
    Solution obj;
    vector<int> arr = {5, 2, 3, 1};
    vector<int> ans = obj.sortArray(arr);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
}
