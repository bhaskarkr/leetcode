class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int r = 0, l = 0;
        for(; r < nums.size(); r++) {
            if(nums[r] - nums[l] > 2 * k)
                l++;
        }
        return r - l;
    }
};
