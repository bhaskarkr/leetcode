class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> Q;
        Q.push(entrance);
        int m = maze.size(), n = maze[0].size();
        int dist = 0;
        vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
        maze[entrance[0]][entrance[1]] = '+';
        while(!Q.empty()) {
            int level = Q.size();
            while(level--) {
                auto ele = Q.front();
                Q.pop();
                if(ele != entrance && (ele[0] == 0 || ele[1] == 0 || ele[0] == m - 1 || ele[1] == n - 1))
                   return dist;
                for(int i = 0; i < 4; i++) {
                    int nx = dx[i] + ele[0];
                    int ny = dy[i] + ele[1];
                    if(nx < m && nx >= 0 && ny < n && ny >= 0 && maze[nx][ny] == '.') {
                        maze[nx][ny] = '0';
                        Q.push({nx, ny});
                    }
                    
                }
            }
            dist++;
        }
        return -1;
    }
};
