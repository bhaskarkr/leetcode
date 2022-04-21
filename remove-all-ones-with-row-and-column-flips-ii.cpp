class Solution {
public:
    int removeOnes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int flip = INT_MAX;
        vector<int> row(n), col(m);
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == 1) {
                    for(int i = 0; i < n; i++) {
                        row[i] = grid[r][i];
                        grid[r][i] = 0;
                    }
                    for(int i = 0; i < m; i++) {
                        col[i] = grid[i][c];
                        grid[i][c] = 0;
                    }
                    flip = min(flip, 1 + removeOnes(grid));
                    for(int i = 0; i < m; i++) {
                        grid[i][c] = col[i];
                    }
                    for(int i = 0; i < n; i++) {
                        grid[r][i] = row[i];
                    }
                }
            }
        }
        return flip == INT_MAX ? 0 : flip;
    }
};
