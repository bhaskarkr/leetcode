class Solution {
public:
    const vector<int> d = {-1, 0, 1, 0, -1};
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int grpId = 2;
        int ans = 0;
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                if(grid[i][j] == 0) {
                    bool valid = true;
                    dfs(grid, m, n, i, j, valid, grpId);
                    ans += valid ? 1 : 0;
                    grpId++;
                }
            }
        } 
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, int &m, int &n, int i, int j, bool &valid, int grpId) {
        grid[i][j] = grpId;
        
        for(int k = 0; k < 4; k++) {
            int ni = i + d[k];
            int nj = j + d[k+1];
            if((ni == 0 || ni == m - 1 || nj == 0 || nj == n - 1) && grid[ni][nj] == 0) {
                grid[ni][nj] = grpId;
                valid = false;
            }
            if(grid[ni][nj] == 0) {
                dfs(grid, m, n, ni, nj, valid, grpId);
            }
        }
    }
};
