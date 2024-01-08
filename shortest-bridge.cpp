class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    void dfs(vector<vector<int>>& grid, int i, int j, int color) {
        if(i >= grid.size() || j >= grid[0].size())
            return;
        for(int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if(ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size() || grid[ni][nj] != 1)
                continue;
            grid[ni][nj] = color;
            dfs(grid, ni, nj, color);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), color = -1, ans = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = color;
                    dfs(grid, i, j, color--);
                }
                if(grid[i][j] == -1)
                    q.push({i, j});
            }
        }
        int dist = 0;
        while(!q.empty()) {
            int c = q.size();
            while(c--) {
                auto curr = q.front();
                int i = curr.first, j = curr.second;
                q.pop();
                for(int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if(ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size() || grid[ni][nj] == -3)
                        continue;
                    if(grid[ni][nj] == -2)
                        return dist;
                    grid[ni][nj] = -3;
                    q.push({ni, nj});
                }
            }
            dist++;
        }
        return dist;
    }
};

class Solution {
public:
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        bool island = false;
        for(int i = 0; i < m && !island; i++) {
            for(int j = 0; j < n && !island; j++) {
                if(grid[i][j] == 1) {
                    island = true;
                    grid[i][j] = 2;
                    helper(grid, i, j, m, n);
                }
            } 
        }
        queue<pair<int, int>> Q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    Q.push({i, j});
                    grid[i][j] = -1;

                }
            } 
        }
        int ans = 0;
        while(!Q.empty()) {
            int c = Q.size();
            while(c--) {
                pair<int, int> curr = Q.front();
                int x = curr.first;
                int y = curr.second;
                Q.pop();
                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= m || ny >= n || nx < 0 || ny < 0 || grid[nx][ny] == -1)
                        continue;
                    // cout<<nx<<" "<<ny<<" "<<grid[nx][ny]<<endl;
                    if(grid[nx][ny] == 2)
                        return ans;
                    grid[nx][ny] = -1;
                    Q.push({nx, ny});
                }
            }
            ans++;
        }
        return -1;
    }

    void helper(vector<vector<int>>& grid, int x, int y, int &m, int &n) {
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= m || ny >= n || nx < 0 || ny < 0 || grid[nx][ny] != 1)
                continue;
            grid[nx][ny] = 2;
            helper(grid, nx, ny, m, n);
        }
    }
};
