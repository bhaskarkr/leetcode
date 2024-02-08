class Solution {
public:
    int numSquares(int n) {
        vector<long> dp(n + 1, 1e5);
        set<int> s;
        dp[0] = 0;
        for(int i = 0; i*i <= n; i++)
            s.insert(i * i);
        for(int i = 1; i <= n; i++) {
            int pre = *prev(s.upper_bound(i));
            for(auto itr = s.begin(); itr != s.end() && *itr <= pre; itr++) {
                int j = *itr;
                dp[i] = min(dp[i - j] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};
