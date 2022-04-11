class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> ans(r, vector<int>(c));
        k = k % (r*c);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                int afterShift = i*c+j+k;
                ans[(afterShift/c)%r][afterShift%c] = grid[i][j];
            }
        }
        return ans;
    }
};
