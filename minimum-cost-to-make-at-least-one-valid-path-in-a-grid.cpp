class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        vector<vector<int>> dp(m, vector<int>(n, 100000));
        dp[0][0] = 0;
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            if(curr[1] == m - 1 && curr[2] == n - 1)
                return curr[0];
            for(int d = 0; d < 4; d++) {
                int nx = curr[1] + dx[d];
                int ny = curr[2] + dy[d];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || dp[nx][ny] <= curr[0])
                    continue;
                int cost = curr[0] + (d + 1 != grid[curr[1]][curr[2]]);
                if(cost < dp[nx][ny]) {
                    pq.push({cost, nx, ny});
                    dp[nx][ny] = cost;
                }
            }
        }
        return -1;
    }
};
