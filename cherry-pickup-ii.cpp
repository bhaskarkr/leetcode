class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int m = grid.size(), n = grid[0].size(), ans = 0, row = 0;
        q.push({0, n - 1, grid[0][0] + grid[0].back()});
        while(!q.empty() && ++row <= m) {
            int level = q.size();
            set<pair<int, int>> candidates;
            vector<vector<int>> costs(n, vector<int>(n));
            while(level--) {
                auto curr = q.front();
                int y1 = curr[0], y2 = curr[1], cost = curr[2];
                ans = max(ans, cost);
                q.pop();
                for(int dy1 = -1 ; dy1 <= 1; dy1++) {
                    for(int dy2 = -1 ; dy2 <= 1; dy2++) {
                        int ny1 = y1 + dy1, ny2 = y2 + dy2;
                        if(row >= m || ny1 < 0 || ny2 < 0 || ny1 >= n || ny2 >= n || ny1 > ny2)
                            continue;
                        int newCost = cost + grid[row][ny1] + ((ny1 == ny2) ? 0 : grid[row][ny2]);
                        candidates.insert({ny1, ny2});
                        costs[ny1][ny2] = max(costs[ny1][ny2], newCost);
                    }
                }
            }
            for(auto &ele : candidates)
                q.push({ele.first, ele.second, costs[ele.first][ele.second]});
        }
        return ans;
    }
};
