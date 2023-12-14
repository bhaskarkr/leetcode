class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m), col(n);
        for(int i = 0; i < m; i++)
            for(int j = 0; j< n ; j++)
                if(grid[i][j])
                    row[i]++, col[j]++;
        for(int i = 0; i < m; i++)
            for(int j = 0; j< n ; j++)
                grid[i][j] = row[i] + col[j] - (n - row[i]) - (m - col[j]);
        return grid;
    }
};
