class Solution {
public:
    int maximizeWin(vector<int>& nums, int k) {
        vector<int> dp(nums.size() + 1);
        int ans = 0;
        for(int l = 0, r = 0; r < nums.size(); r++) {
            while(nums[r] - nums[l] > k)
                l++;
            ans = max(ans, dp[l] + r - l + 1);
            dp[r+1] = max(r - l + 1, dp[r]);
        }
        return ans;
    }
};
