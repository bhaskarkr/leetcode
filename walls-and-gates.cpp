class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> Q;
        for(int i = 0; i < rooms.size(); i++) {
            for(int j = 0; j < rooms[0].size(); j++) {
                if(rooms[i][j] == 0) {
                    Q.push({i, j});
                }
                    
            }
        }
        int level = 1;
        vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
        while(!Q.empty()) {
            int c = Q.size();
            while(c--) {
                auto curr = Q.front();
                Q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = curr.first + dx[d];
                    int ny = curr.second + dy[d];
                    if(nx < 0 || ny < 0 || nx >= rooms.size() || ny >= rooms[0].size() || rooms[nx][ny] != 2147483647)
                        continue;
                    rooms[nx][ny] = level;
                    Q.push({nx, ny});
                }
            }  
            level++;  
        }
    }
};
