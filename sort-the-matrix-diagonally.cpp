class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for(int r = 0; r < m; r++) {
            int i = r;
            int j = 0;
            vector<int> vec;
            while(i < m && j < n) {
                vec.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(vec.begin(), vec.end());
            int k = vec.size() - 1;
            while(k >= 0) {
                mat[--i][--j] = vec[k];
                k--;
            }
        }
        for(int c = 1; c < n; c++) {
            int i = 0;
            int j = c;
            vector<int> vec;
            while(i < m && j < n) {
                vec.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(vec.begin(), vec.end());
            int k = vec.size() - 1;
            while(k >= 0) {
                mat[--i][--j] = vec[k];
                k--;
            }
        }
        return mat;
    }
};
