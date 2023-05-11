class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> DP(m+1, vector<int>(n+1));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(nums1[i-1] == nums2[j-1]) {
                    DP[i][j] = DP[i-1][j-1] + 1;
                } else {
                    DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
                }
            }
        }
        return DP[m][n];
    }
};
