class Solution {
public:
    vector<int> d = {-1, 0, 1, 0, -1};
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        int id = 2;
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                bool value = true;
                int count = 0; 
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, value, id, count);
                }
                if(value) {
                    ans += count;
                }
                id++;
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, bool &valid, int id, int &count) {
        grid[x][y] = id;
        count++;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < 4; i++) {
            int nx = x + d[i];
            int ny = y + d[i+1];
            if((nx  == m - 1 || nx == 0 || ny == n - 1 || ny == 0) && grid[nx][ny] == 1)  {
                grid[nx][ny] = id;
                valid = false;
            }
            if(grid[nx][ny] == 1) {
                dfs(grid, nx, ny, valid, id, count);
            }
        }
    }
};
