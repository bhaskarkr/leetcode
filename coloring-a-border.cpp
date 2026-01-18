class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& temp, int row, int col, int fromColor) {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || temp[row][col] != fromColor)
            return;
        grid[row][col] = -fromColor;
        temp[row][col] = -fromColor;
        dfs(grid, temp, row - 1, col, fromColor);
        dfs(grid, temp, row + 1, col, fromColor);
        dfs(grid, temp, row, col - 1, fromColor);
        dfs(grid, temp, row, col + 1, fromColor);
        if(row > 0 && col > 0 && row < grid.size() - 1 && col < grid[0].size() - 1 && abs(grid[row - 1][col]) == fromColor 
        && abs(grid[row + 1][col]) == fromColor && abs(grid[row][col - 1]) == fromColor && abs(grid[row][col + 1]) == fromColor)
            grid[row][col] = fromColor;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        auto temp = grid;
        dfs(grid, temp, row, col, grid[row][col]);
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] < 0)
                    grid[i][j] = color;
            }
        }
        return grid;
    }
};
