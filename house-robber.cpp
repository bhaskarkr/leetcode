class Solution {
public:
    int rob(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
            nums[i] = max(nums[i] + (i > 1 ? nums[i-2] : 0 ), nums[i-1]);
        return nums.back();
    }
};
