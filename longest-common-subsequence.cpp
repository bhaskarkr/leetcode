class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> DP(m+1, vector<int>(n+1));
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 || j == 0) {
                    continue;
                }
                if(s1[i-1] == s2[j-1])
                    DP[i][j] = DP[i-1][j-1] + 1;
                else
                    DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
        return DP[m][n];
    }
};
