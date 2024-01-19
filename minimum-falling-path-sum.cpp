class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        if(matrix.size() == 1)
            return *min(matrix[0].begin(), matrix[0].end());
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                int temp = matrix[i-1][j];
                int left = j > 0 ? matrix[i-1][j-1] : INT_MAX;
                int right = j < matrix[0].size() - 1 ? matrix[i-1][j+1] : INT_MAX;
                matrix[i][j] += min(temp, min(left, right));
                if(i == matrix.size() - 1) {
                    ans = min(ans, matrix[i][j]);
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        for(int i = 1; i < n; i++) {
            vector<int> row(n);
            for(int j = 0; j < n; j++) {
                int temp = matrix[i-1][j];
                if(j > 0)
                    temp = min(matrix[i-1][j-1], temp);
                if(j < n - 1)
                    temp = min(matrix[i-1][j+1], temp);
                row[j] = temp + matrix[i][j];
            }
            matrix[i] = row;
        }
        for(int i = 0; i < n; i++) {
            ans = min(matrix[n-1][i], ans);
        }
        return ans;
    }
};
