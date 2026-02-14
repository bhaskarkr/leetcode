class Solution {
public:
    void helper(vector<vector<int>>& grid, int i, int j, int &ans, int squaresToVisit) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] < 0)
            return;
        if(grid[i][j] == 2) {
            // cout<<emptySquares<<endl;
            ans += squaresToVisit == 0 ? 1 : 0;
            return;
        }
        grid[i][j] = -2;
        helper(grid, i + 1, j, ans, squaresToVisit - 1);
        helper(grid, i, j + 1, ans, squaresToVisit - 1);
        helper(grid, i - 1, j, ans, squaresToVisit - 1);
        helper(grid, i, j - 1, ans, squaresToVisit - 1);
        grid[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0, emptySquares = 0, startX = 0, startY = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0)
                    emptySquares++;
                else if(grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }
        helper(grid, startX, startY, ans, 1 + emptySquares);
        return ans;
    }
};
