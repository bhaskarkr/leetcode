class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0, m = matrix.size(), c = matrix[0].size() - 1, n = matrix[0].size();
        while(r < m && c >= 0) {
            if(matrix[r][c] == target)
                return true;
            if(matrix[r][c] < target)
                r++;
            else
                c--;
        }
        return false;
    }
};
