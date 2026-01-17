class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        long long sum = 0;
        int count = 0, maxNegative = INT_MAX;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                count += matrix[i][j] < 0;
                maxNegative = min(maxNegative, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);    
            }
        }
        return count % 2 ? sum + (2 * -maxNegative) : sum;
    }
};
