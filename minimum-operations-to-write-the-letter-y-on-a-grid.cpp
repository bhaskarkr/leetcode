class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        unordered_map<int, int> yCount, allCount;
        int m = grid.size(), n = grid[0].size(), ans = m * n, c1 = 0, c2 = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i < m / 2 && (abs(i - j) == 0 || (i + j == n - 1))) 
                    yCount[grid[i][j]]++;
                else if(i >= m / 2 && j == n / 2)
                    yCount[grid[i][j]]++;
                else
                    allCount[grid[i][j]] += 1, c2++;
            }
        }
        c1 = m * n - c2;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int t1 = 0, t2 = 0;
                if(i == j)
                    continue;
                else {
                    t1 += c1 - yCount[i];
                    t2 += c2 - allCount[j];
                    ans = min(ans, t1 + t2);
                }
            }
        }
        return ans;
    }
};
