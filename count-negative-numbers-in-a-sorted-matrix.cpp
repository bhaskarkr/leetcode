class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            auto k = lower_bound(grid[i].rbegin(), grid[i].rend(), 0);
            ans += (k - grid[i].rbegin());
        }
        return ans;
    }
};
