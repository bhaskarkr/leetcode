class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size(), ans = n - 1;
        vector<int> DP(n, 1);
        for(int r = 0; r < n; r++) {
            for(int l = 0; l < r; l++) {
                int i = 0;
                for(i = 0; i < m; i++) {
                    if(strs[i][l] > strs[i][r])
                        break;
                }
                if(i == m) {
                    DP[r] = max(DP[r], DP[l] + 1);
                }
            }
            ans = min(ans, n - DP[r]);
        }
        return ans;
    }
};
