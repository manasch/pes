#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Balanced BST with DST
// Overall time constant: O(m + n * log(m))
class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            int n = nums.size();
            map<int, int> d;

            // O(n * log(m)), gives the frequencies
            for (int i = 0; i < n; i++) {
                d[nums[i]]++;
            }

            // O(m), Calculates the distribution array
            int prev = 0;
            for (auto& keyval : d) {
                int temp = prev + keyval.second;
                keyval.second = prev;
                prev = temp;
            }

            // O(n * log(m))
            vector<int> sorted(n);
            for (int i = 0; i < n; i++) {
                sorted[d[nums[i]]] = nums[i];
                d[nums[i]]++;
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
