class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> DP(2001, vector<int>(1001, -1));
        return helper(DP, piles, 0, k);
    }

    int helper(vector<vector<int>> &DP, vector<vector<int>>& piles, int i, int k) {
        if(i >= piles.size() || k <= 0)
            return DP[k][i] = 0;
        if(DP[k][i] != -1)
            return DP[k][i];
        int currSum = 0, ans = 0;
        int k_backup = k;
        for(int j = 0; j < piles[i].size() && k > 0; j++) {
            currSum += piles[i][j];
            k--;
            ans = max(ans, currSum + helper(DP, piles, i + 1, k));
        }
        return DP[k_backup][i] = max(ans, helper(DP, piles, i + 1, k_backup));
    }

};
