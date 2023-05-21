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
