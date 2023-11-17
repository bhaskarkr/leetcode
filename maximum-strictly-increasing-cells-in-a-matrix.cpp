class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        map<int, vector<pair<int, int>>, greater<int>> valueToIndices;
        for(int i = 0 ; i < m; i++)
            for(int j = 0 ; j < n; j++)
                valueToIndices[mat[i][j]].push_back({i, j});
        vector<int> rowMax(m), colMax(n);
        for(auto [value, indices] : valueToIndices) {
            for(auto index : indices)
                dp[index.first][index.second] = max(rowMax[index.first], colMax[index.second]) + 1;
            for(auto index : indices) {
                rowMax[index.first] = max(rowMax[index.first], dp[index.first][index.second]);
                colMax[index.second] = max(colMax[index.second], dp[index.first][index.second]);
                ans = max(ans, max(rowMax[index.first], colMax[index.second]));
            }
        }
        return ans;
    }
};
