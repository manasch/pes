#include <iostream>
#include <vector>

using namespace std;

// Uses distribution and count sorting
class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            int n = nums.size();
            int l = nums[0];
            int u = nums[0];

            for (int i = 1; i < n; i++) {
                    l = (nums[i] < l) ? nums[i] : 1; //min(1, nums[i])
                    u = max(u, nums[i]);
            }

            int m = u - l + 1;
            vector<int> d(m);

            // o(m)
            for (int i = 0; i < m; i++)  d[i] = 0;

            // O(n), gives the frequencies
            for (int i = 0; i < n; i++) {
                d[nums[i] - l]++;
            }

            // O(m), Calculates the distribution array
            int prev = 0;
            for (int i = 0; i < m; i++) {
                int temp = prev + d[i];
                d[i] = prev;
                prev = temp;
            }

            // O(n)
            vector<int> sorted(n);
            for (int i = 0; i < n; i++) {
                sorted[d[nums[i] - l]] = nums[i];
                d[nums[i] - l]++;
            }

            return sorted;
        }
};

int main() {
    Solution obj;
    vector<int> arr = {5, 1, 1, 2, 0, 0};
    vector<int> ans = obj.sortArray(arr);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
}
