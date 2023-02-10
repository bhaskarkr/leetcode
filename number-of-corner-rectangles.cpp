class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        unordered_map<int, unordered_set<int>> r;
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j]) {
                    r[i].insert(j);
                }
            }
        }
        vector<int> rows;
        for(auto [k, v] : r) {
            rows.push_back(k);
        }
        for(int i = 0; i < rows.size() - 1; i++) {
            for(int j = i+1; j < rows.size(); j++) {
                int c = 0;
                for(auto col : r[rows[i]]) {
                    if(r[rows[j]].find(col) != r[rows[j]].end()) 
                        c++;
                }
                // cout<<i <<" "<<j<<" "<<c<<endl;
                ans += c*(c-1)/2;
            }
        }
        return ans;
    }
};
