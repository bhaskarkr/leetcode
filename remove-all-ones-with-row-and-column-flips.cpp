class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ; i < n; i++) {
            if(grid[0][i]) {
                for(int j = 0; j < m; j++) {
                    grid[j][i] = !grid[j][i];
                }
            }
        }
        
        for(int i = 1 ; i < m; i++) {
            int count = accumulate(grid[i].begin(), grid[i].end(), 0);
            if(count != 0 && count != n)
                return false;
        }
        return true;
    }
};
