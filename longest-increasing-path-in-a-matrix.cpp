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


class Solution {
public:
    vector<vector<int>> visited;
    vector<int> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
    int helper(vector<vector<int>>& matrix, int x, int y, int m, int n) {
        int curr = 0;
        if(visited[x][y] != -1)
            return visited[x][y];
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx  < 0 || ny < 0 || nx >= m || ny >= n || matrix[nx][ny] <= matrix[x][y])
                continue;
            curr = max(curr, helper(matrix, nx, ny, m, n));
        }
        return visited[x][y] = curr + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        visited.resize(m, vector<int> (n, -1));
        vector<vector<int>> count(m, vector<int> (n, 1));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(visited[i][j] == -1)
                    ans = max(ans, helper(matrix, i, j, m, n));
        return ans;
    }
};
