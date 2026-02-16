
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 1, r = cells.size();
        vector<vector<int>> grid(row + 1, vector<int>(col + 1));
        vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
        function<bool(int)> check = [&](int day) {
            queue<pair<int, int>> Q;
            for(auto &row : grid)
                fill(row.begin(), row.end(), 0);
            for(int i = 0; i < day; i++) {
                // cout<<i<<" "<<cells[i][0]<<" "<<cells[i][0]<<endl;
                grid[cells[i][0]][cells[i][1]] = 1;
            }
                
            for(int c = 1; c <= col; c++) {
                if(grid[1][c] == 0)
                    Q.push({1, c});
                grid[1][c] = 1;
            }

            while(!Q.empty()) {
                auto curr = Q.front();
                Q.pop();
                if(curr.first == row)
                    return true;
                for(int d = 0; d < 4; d++) {
                    int nx = curr.first + dx[d];
                    int ny = curr.second + dy[d];
                    if(nx < 1 || ny < 1 || nx > row || ny > col || grid[nx][ny] > 0)
                        continue;
                    grid[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            return false;
        };
        int ans = 0;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(check(m)) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};
