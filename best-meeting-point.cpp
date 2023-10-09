class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        /**
            {
                {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                {0, 0, 0, 0, 1, 0, 0, 1, 0}, 
                {1, 1, 0, 0, 0, 0, 1, 0, 0}, 
                {0, 0, 0, 1, 1, 1, 0, 0, 0}
            }
        */
        int m = grid.size(), n = grid[0].size(), ans = 0;
        int R = 0, C = 0;
        vector<int> I, J;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                     I.push_back(i);
                     J.push_back(j);
                }
            }
        }
        sort(I.begin(), I.end());
        sort(J.begin(), J.end());
        int l = 0, j = I.size() - 1;
        while(l < j) ans += I[j--] - I[l++]; 
        l = 0, j = J.size() - 1;
        while(l < j) ans += J[j--] - J[l++]; 
        return ans;
    }
};
