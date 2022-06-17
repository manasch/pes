#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> partial;
        vector<vector<int>> all;
        vector<bool> available(nums.size(), true);
        f(nums, available, partial, all);
        return all;
    }

    void f(const vector<int>& nums, vector<bool>& available, vector<int>& partial, vector<vector<int>>& all) {
        //base case
        if (partial.size() == nums.size()) {
            // assert(available vector has no true values) takes linear time
            all.push_back(partial);
            return;
        }

        // try all the available options
        for (int i = 0; i < available.size(); i++) {
            if (available[i]) {
                partial.push_back(nums[i]);
                available[i] = false;
                f(nums, available, partial, all);

                // just undo what was done above f(), try the option
                partial.pop_back();
                available[i] = true;
            }
        }
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = obj.permute(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << '[';
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\b' << ']' << endl;
    }
}