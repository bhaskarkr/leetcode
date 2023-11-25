class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int>> count(m, vector<int> (n, 1));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                pq.push({matrix[i][j], i, j});
        vector<int> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            for(int i = 0; i < 4; i++) {
                int nx = curr[1] + dx[i];
                int ny = curr[2] + dy[i];
                if(nx  < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                if(matrix[nx][ny] < curr[0]) {
                    count[curr[1]][curr[2]] = max(count[curr[1]][curr[2]], count[nx][ny] + 1);
                }
            }
            ans = max(ans, count[curr[1]][curr[2]]);
        }
        return ans;
    }
};
