class Solution {
public:
    int helper(vector<int> &nums, int l, int r, vector<vector<int>> &dp) {
        if(l >= r)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        int maxSum = 0;
        for(int k = l; k < r; k++) {
            // cout<<k<<endl;
            int currSum = helper(nums, l, k, dp) + helper(nums, k+1, r, dp) + nums[l - 1] * nums[k] * nums[r]; 
            maxSum = max(maxSum, currSum);
            dp[l][r] = maxSum;
        }
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(nums, 1, n - 1, dp);
    }
};

class Solution { // chnaged the indices 
public:
    int helper(vector<int> &nums, int l, int r, vector<vector<int>> &dp) {
        if(l > r)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        int maxSum = 0;
        for(int k = l; k <= r; k++) {
            // cout<<k<<endl;
            int currSum = helper(nums, l, k-1, dp) + helper(nums, k+1, r, dp) + nums[l - 1] * nums[k] * nums[r+1]; 
            maxSum = max(maxSum, currSum);
            dp[l][r] = maxSum;
        }
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(nums, 1, n - 2, dp);
    }
};
