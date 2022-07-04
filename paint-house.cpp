class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int ans = INT_MAX;
        vector<vector<int>> DP(n + 1, vector<int>(3));
        for(int i = 1; i <= n; i++) {
            DP[i][0] = min( DP[i-1][1],  DP[i-1][2]) + costs[i-1][0];
            DP[i][1] = min( DP[i-1][0],  DP[i-1][2]) + costs[i-1][1];
            DP[i][2] = min( DP[i-1][0],  DP[i-1][1]) + costs[i-1][2];
        }
        return min(DP[n][0], min(DP[n][1], DP[n][2]));
    }
};
