class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<vector<int>> pq;
        pq.push({health - grid[0][0], 0, 0});
        vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
        while(!pq.empty()) {
            auto remaining_health = pq.top()[0];
            auto x = pq.top()[1];
            auto y = pq.top()[2];
            pq.pop();
            if(x == m - 1 && y == n - 1)
                return remaining_health >= 1;
            for(int d = 0; d< 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] < 0) {
                    continue;
                }
                pq.push({remaining_health - grid[nx][ny], nx, ny});
                grid[nx][ny] = -1;
            }
        }
        return false;
    }
};
