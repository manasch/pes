// PES1UG20CS111 - Manas Chebrolu

#include <vector>
#include <utility>
#include <unordered_map>

std::vector<std::pair<int, int>> unique_pairs(const std::vector<int>& nums, int target_sum) {
    std::vector<std::pair<int, int>> result;
    int t;

    std::unordered_map<int, bool> hash;
    for (auto v: nums)
        hash[v] = true;
    
    for (auto v: nums) {
        t = target_sum - v;
        if (hash[v] && hash[t]) {
            hash[v] = false;
            hash[t] = false;

            result.push_back(std::pair<int, int> (std::min(v, t), std::max(v, t)));
        }
    }

    return result;
}
