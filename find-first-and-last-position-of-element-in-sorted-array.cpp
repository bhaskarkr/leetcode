class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto l = upper_bound(nums.begin(), nums.end(), target - 1);
        auto r = upper_bound(nums.begin(), nums.end(), target);
        if(r != nums.begin())
            r = prev(r);
        if(nums.size() < 1 || l == nums.end() || r == nums.end() || *l != target || *r != target)
            return {-1, -1};
        int a = l - nums.begin();
        int b = r - nums.begin();
        return {a, b};
    }
};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto a = lower_bound(nums.begin(), nums.end(), target);
        if(a == nums.end() ||*(a) != target)
            return {-1, -1};
        int b = prev(upper_bound(a, nums.end(), target)) - nums.begin();
        int f = a - nums.begin();
        return {f, b};
    }
};
