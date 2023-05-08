class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i = 0, j = 0;
        int ans = 0;
        while(i < mat.size()) {
            ans += mat[i][j];
            i++;
            j++;
        }
        i = 0;
        j--;
        while(i < mat.size()) {
            if(i != j)
                ans += mat[i][j];
            i++;
            j--;
        }
        return ans;
    }
};
