class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> Q;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(mat[i][j] == 0)
                    Q.push({i, j});
                else
                    mat[i][j] = -1;
        vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
        int dist = 0;
        while(!Q.empty()) {
            int count = Q.size();
            dist++;
            while(count--) {
                auto ele = Q.front();
                Q.pop();
                for(int i = 0; i < 4; i++) {
                    int nx = ele.first + dx[i];
                    int ny = ele.second + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || mat[nx][ny] != -1)
                        continue;
                    mat[nx][ny] = dist;
                    Q.push({nx, ny});
                }
            }
        }
        return mat;
    }
};
