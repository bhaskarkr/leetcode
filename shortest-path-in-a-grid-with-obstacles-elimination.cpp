class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        queue<vector<int>> Q;
        vector<vector<int>> vis(m, vector<int>(n, -1));
        vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
        Q.push({0, 0, 0, k});
        while(!Q.empty()) {
            int level = Q.size();
            auto ele = Q.front();
            Q.pop();
            int x = ele[0], y = ele[1], c = ele[2], tk = ele[3];
            if(x == m - 1 && y == n-1)
                return c;
            if(grid[x][y] == 1) {
                if(tk > 0)
                    tk--;
                else
                    continue;
            }
            if(vis[x][y] != -1 && vis[x][y] >= tk)
                continue;
            vis[x][y] = tk;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                Q.push({nx, ny, c + 1, tk});
            }
        }

        return -1;
    }
};
