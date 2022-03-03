class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
         int mod = 1000000007;
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair< long long, long long> > > DP(n, vector<pair<long long, long long> > (m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    DP[i][j].first = DP[i][j].second = grid[i][j];
                }
                else if(i == 0) {
                    DP[i][j].first = DP[i][j].second = grid[i][j]*DP[i][j-1].first;
                }
                else if(j == 0) {
                    DP[i][j].first = DP[i][j].second = grid[i][j]*DP[i-1][j].first;
                }
                else if(grid[i][j] > 0) {
                    DP[i][j].first = max((DP[i-1][j].first * grid[i][j]), (DP[i][j-1].first * grid[i][j]));
                    DP[i][j].second = min(DP[i-1][j].second * grid[i][j], DP[i][j-1].second * grid[i][j]);
                } else {
                    DP[i][j].first = max(DP[i-1][j].second * grid[i][j], DP[i][j-1].second * grid[i][j]);
                    DP[i][j].second = min(DP[i-1][j].first * grid[i][j], DP[i][j-1].first * grid[i][j]);
                }
            }
        }
        return DP[n-1][m-1].first < 0 ? -1 : DP[n-1][m-1].first % mod;
    }
};
