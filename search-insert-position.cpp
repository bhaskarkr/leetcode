class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto k = lower_bound(nums.begin(), nums.end(), target);
        return k - nums.begin();
    }
};
