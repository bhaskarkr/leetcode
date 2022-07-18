class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m; i++)
            for(int j = 1; j < n; j++)
                matrix[i][j] += matrix[i][j-1];
        
        int ans = 0;
        
        unordered_map<int, int> found;
        
        for(int c1 = 0; c1 < n; c1++) {
            for(int c2 = c1; c2 < n; c2++) {
                int curr = 0;
                found.clear();
                found[0] = 1;
                for(int r = 0; r < m; r++) {
                    curr += matrix[r][c2] - (c1 > 0 ? matrix[r][c1 - 1] : 0);
                    ans += found[curr - target];
                    found[curr]++;
                }
            }
        }
        return ans;
    }
};
