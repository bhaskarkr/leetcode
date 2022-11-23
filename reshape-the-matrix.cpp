class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if(m*n != r*c)
            return mat;
        vector<vector<int>> newMat(r, vector<int>(c));
        int k = 0;
        for(int i = 0; i < m; i++) {
           for(int j = 0; j < n; j++) {
                newMat[k/c][k%c] = mat[i][j]; 
                k++;
            } 
        }
        return newMat;
    }
};
