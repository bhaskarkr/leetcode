class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        int n = nums.size();
        long ans = nums[0];
        vector<pair<long, long>> DP(n);
        DP[0].first = nums[0];
        DP[0].second = -10e6;
        for(int i = 1; i < n; i++) {
            DP[i].first = max((long)nums[i], DP[i-1].second + nums[i]);
            DP[i].second = DP[i-1].first - nums[i];
            ans = max(ans, max(DP[i].first, DP[i].second)); 
        }
        return ans;
    }
};
