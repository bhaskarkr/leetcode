class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        long long mod = (1e9 + 7);
        vector<long long> dp(high + 1, 0), presum(high + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= high; i++) {
            if(i >= zero)
                dp[i] += dp[i - zero];
            if(i >= one)
                dp[i] += dp[i - one];
            dp[i] %= mod;
            presum[i] = (dp[i] + presum[i-1])%mod;
        }
        return (presum[high] - presum[low - 1] + mod)%mod;
    }
};
