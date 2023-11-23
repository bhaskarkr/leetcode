class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long ans = 0;
        auto up = grid, down = grid;
        for(int i = m-2; i >= 0; i--) {
            for(int j = 1; j < n - 1; j++) {
                if(grid[i][j]) {
                    up[i][j] = min(up[i+1][j-1], min(up[i+1][j+1], up[i+1][j])) + 1;
                    ans += up[i][j] - 1;
                }
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n - 1; j++) {
                if(grid[i][j]) {
                    down[i][j] = min(down[i-1][j-1], min(down[i-1][j+1], down[i-1][j])) + 1;
                    ans += down[i][j] - 1;
                }
            }
        }
        return ans;
    }
};
