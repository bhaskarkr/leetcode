class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector<vector<int>> matrix(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = mat[i][j] == '1';
                if(matrix[i][j] && i  > 0 && j > 0 && matrix[i-1][j] && matrix[i][j-1] && matrix[i-1][j-1]) {
                        matrix[i][j] = min(matrix[i-1][j], min(matrix[i][j-1], matrix[i-1][j-1])) + 1;
                }
                if(ans < matrix[i][j])
                    ans = matrix[i][j];
            }
        }
        return ans * ans;
    }
};
