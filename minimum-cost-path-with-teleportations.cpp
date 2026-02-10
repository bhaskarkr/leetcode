class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
        pq.push({0, 0, 0, k});
        const int m = grid.size();
        const int n = grid[0].size();
        vector<tuple<int, int, int>> s;
        for(int a = 0; a < m; a++) {
            for(int b = 0; b < n; b++) {
                s.push_back({grid[a][b], a, b});
            }
        }
        unordered_map<int, int> indexCounterForK;
        sort(s.begin(), s.end());
        vector memo(m + 1, vector(n + 1, vector<int>(k + 1, INT_MAX)));

        while(!pq.empty()) {
            auto [cost, i, j, rem_k] = pq.top();
            pq.pop();
            if(i == m - 1 && j == n - 1) {
                return cost;
            }
            if(i + 1 < m && memo[i+1][j][rem_k] > cost + grid[i + 1][j]) {
                memo[i+1][j][rem_k] = cost + grid[i + 1][j];
                pq.push({cost + grid[i + 1][j], i + 1, j, rem_k});
            }
            if(j + 1 < n && memo[i][j+1][rem_k] > cost + grid[i][j+1]) {
                memo[i][j+1][rem_k] = cost + grid[i][j+1];
                pq.push({cost + grid[i][j + 1], i, j + 1, rem_k});
            }
            if(rem_k > 0) {
                int r = indexCounterForK[rem_k];
                while(r < s.size()) {
                    auto [c, ni, nj] = s[r];
                    if(c > grid[i][j])
                        break;
                    if(cost < memo[ni][nj][rem_k - 1]) {
                        pq.push({cost, ni, nj, rem_k - 1});
                        memo[ni][nj][rem_k - 1] = cost;
                    }
                    r++;
                }
                indexCounterForK[rem_k] = r;
            }
        }
        return -1;
    }
};
