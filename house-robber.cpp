class Solution {
public:
    int rob(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
            nums[i] = max(nums[i] + (i > 1 ? nums[i-2] : 0 ), nums[i-1]);
        return nums.back();
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> DP(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            DP[i] = max((i >= 2 ? DP[i-2] : 0) + DP[i], DP[i-1]);
        }
        return DP.back();
    }
};
