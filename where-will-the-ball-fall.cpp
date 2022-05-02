class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++) {
            int col = i;
            for(int row = 0; row < m; row++) {
                int nextCol = col + grid[row][col];
                if(nextCol < 0 || nextCol >= n || grid[row][col] != grid[row][nextCol]) {
                    col = -1;
                    break;
                }
                col  = nextCol;
            }
            ans[i] = col;
        }
        return ans;
    }
//     DFS
//     vector<int> findBall(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> DP(m, vector<int>(n, INT_MAX));
//         vector<int> ans(n, -1);
//         for(int i = 0; i < n; i++) {
//             ans[i] = dfs(grid, m, n, 0, i, DP);
//         }
//         return ans;
//     }
    
//     int dfs(vector<vector<int>>& grid, int &m, int &n, int row, int col, vector<vector<int>> &DP) {
//         if(row == m)
//            return col;
//         if(DP[row][col] != INT_MAX)
//             return DP[row][col];
//         int nextCol = col;
//         if(grid[row][col] == 1) {
//             if(col == n - 1 || grid[row][col + 1] == -1) {
//                 DP[row][col] = -1;
//             } else {
//                 DP[row][col] = dfs(grid, m, n, row + 1, col + 1, DP);
//             }
//         } else {
//             if(col == 0 || grid[row][col - 1] == 1) {
//                 DP[row][col] = -1;
//             } else {
//                 DP[row][col] = dfs(grid, m, n, row + 1, col - 1, DP);
//             }
//         }
//         return DP[row][col];
//     }
};
