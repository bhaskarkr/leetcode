class Solution {
public:
    vector<vector<int>> DP;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        DP.resize(1005, vector<int>(1005, INT_MIN));
        int n = nums.size(), m = multipliers.size();
        return helper(nums, multipliers, n, m, 0, 0);
    }
    
    int helper(vector<int>& nums, vector<int>& multipliers, int &n, int &m, int l, int r) {
        if((l + r) == m)
            return 0;
        if(DP[l][r] != INT_MIN)
            return DP[l][r];
        int left = helper(nums, multipliers, n, m, l + 1, r) + nums[l]*multipliers[l+r];
        int right = helper(nums, multipliers, n, m, l, r + 1) + nums[n-1-r]*multipliers[l+r];
        return DP[l][r] = max(left, right);
    }
};
