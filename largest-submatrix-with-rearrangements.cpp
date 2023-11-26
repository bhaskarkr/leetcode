class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; i > 0 && j < n; j++) {
                if(matrix[i][j])
                    matrix[i][j] += matrix[i-1][j];
            }
            vector<int> temp(matrix[i].begin(), matrix[i].end());
            sort(temp.rbegin(), temp.rend());
            for(int j = 0; j < n; j++) {
                if(temp[j] == 0)
                    break;
                ans = max(ans, (j + 1) * temp[j]);
            }
        }
        return ans;
    }
};
