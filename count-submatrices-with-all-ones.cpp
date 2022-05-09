class Solution {
public:
    /*
        [1,0,1],    1, 0, 1   ans = 0 + (1 + 1) = 2
        [1,1,0],    2, 1, 0   ans = 2 + (2 + (1 + 1) + 0) = 6
        [1,1,0]     3, 2, 0   ans = 6 + (3 + (2 + 2) + 0) = 13
                                         |
                                         considering (2,0) --> 3 rectangle can be created, 3, 2, 1
    */
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n); // keep continous 1 for each column
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                height[j] = mat[i][j] == 0 ? 0 : height[j] + 1;
                for(int k = j,  minHeight = height[j]; k >= 0 && minHeight > 0; k--) {
                    minHeight = min(minHeight, height[k]);
                    ans += minHeight;
                }
            }
        }
        return ans;
    }
};
