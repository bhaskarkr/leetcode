class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>> pq;
        int m = grid.size(), n = grid[0].size();
        vector<int> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
        pq.push({-grid[0][0], 0, 0});
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            if(curr[1] == m - 1 and curr[2] == n - 1) {
                return -curr[0];
            }
            for(int d = 0; d < 4; d++) {
                int nx = curr[1] + dx[d];
                int ny = curr[2] + dy[d];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == -1) {
                    continue;
                }
                pq.push({-max(grid[nx][ny], -curr[0]), nx, ny});
                grid[nx][ny] = -1;
            }
        }
        return -1;
    }
};
