class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int m = heightMap.size(), n = heightMap[0].size(), ans = 0, level = 0;
        for(int i = 0; i < m ; i++)
            for(int j = 0; j < n; j++)
                if(i == 0 || j == 0 || i == m - 1 || j == n - 1)
                    pq.push({heightMap[i][j], i, j}), heightMap[i][j] = -1;
        vector<int> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int val = curr[0], x = curr[1], y = curr[2];
            level = max(level, val);
            for(int d = 0; d < 4; d++) {
                int nx = dx[d] + x;
                int ny = dy[d] + y;
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || heightMap[nx][ny] == -1)
                    continue;
                if(heightMap[nx][ny] < level)
                    ans += level - heightMap[nx][ny];
                pq.push({heightMap[nx][ny], nx, ny});
                heightMap[nx][ny] = -1;
            }
        }
        return ans;
    }
};
