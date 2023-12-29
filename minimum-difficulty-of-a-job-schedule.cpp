class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& jobDifficulty, int index, int d) {
        if(d == 0 || index == jobDifficulty.size())
            return d == 0 and index == jobDifficulty.size() ? 0 : 1e6;
        if(dp[index][d] != -1)
            return dp[index][d];
        int currMax = 0, minSum = 1e6;
        for(int i = index; i < jobDifficulty.size(); i++) {
            currMax = max(jobDifficulty[i], currMax);
            minSum = min(minSum, currMax + helper(jobDifficulty, i + 1, d - 1));
        }
        return dp[index][d] = minSum;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d)
            return -1;
        dp.resize(jobDifficulty.size(), vector<int>(d + 1, -1));
        return helper(jobDifficulty, 0, d);
    }
};
