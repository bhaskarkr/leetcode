class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> Q;
        int level = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j])
                    Q.push({i, j});
            }
        }
        if(Q.size() == grid.size()*grid[0].size())
            return -1;
        vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
        while(!Q.empty()) {
            int n = Q.size();
            level++;
            while(n--) {
                auto index = Q.front();
                Q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = index.first + dx[d];
                    int ny = index.second + dy[d];
                    if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny])
                    continue;
                    grid[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
        return --level;
    }
};
