class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), 
        target = 0, 
        mindist = -1, 
        dx[] = {0, 1 , 0, -1}, 
        dy[] = {1, 0, -1, 0};
        vector<vector<int>> dist(m, vector<int>(n));
        for(int i = 0 ; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    
                    mindist = INT_MAX;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    int level = 1;
                    while(!q.empty()) {
                        int c = q.size();
                        while(c--) {
                            auto curr = q.front();
                            int x = curr.first;
                            int y = curr.second;
                            q.pop();
                            for(int d = 0; d < 4; d++) {
                                int nx = x + dx[d];
                                int ny = y + dy[d];
                                if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target) {
                                    continue;
                                }
                                q.push({nx, ny});
                                grid[nx][ny]--;
                                dist[nx][ny] += level;
                                mindist = min(mindist, dist[nx][ny]);
                            }
                        }
                        level++;
                    }
                    target--;
                }
            }
        }
        return mindist == INT_MAX ? -1 : mindist;
    }
};
