class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 1; i < grid.size() - 1; i++) {
            for(int j = 1; j < grid[i].size() - 1; j++) {
                int tl = grid[i-1][j-1];
                int t = grid[i-1][j];
                int tr = grid[i-1][j+1];
                int l = grid[i][j-1];
                int c = grid[i][j];
                int r = grid[i][j+1];
                int bl = grid[i+1][j-1];
                int b = grid[i+1][j];
                int br = grid[i+1][j+1];
                int row1 = tl + t + tr;
                int row2 = l + c + r;
                int row3 = bl + b + br;
                int col1 = tl + l + bl;
                int col2 = t + c + b;
                int col3 = tr + r + br;
                int dia1 = tl + c + br;
                int dia2 = tr + c + bl;
                set<int> s = {row1, row2, row3, col1, col2, col3, dia1, dia2};
                set<int> v = {tl, t, tr, l, c, r, bl, b, br};
                if(s.size() == 1 && v.size() == 9 && *v.begin() > 0 && *v.rbegin() <= 9)
                    ans++;
            }
        }
        return ans;
    }
};
