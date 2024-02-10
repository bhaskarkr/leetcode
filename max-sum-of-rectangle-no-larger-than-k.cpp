class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(), ans = INT_MIN;
        for(int i = 0; i < m; i++)
            for(int j = 1; j < n; j++)
                matrix[i][j] += matrix[i][j - 1];   
        for(int c1 = 0; c1 < n; c1++) {
            for(int c2 = c1; c2 < n; c2++) {
                int sum = 0;
                set<int> s;
                s.insert(sum);
                for(int r2 = 0; r2 < m; r2++) {
                    sum += matrix[r2][c2] - (c1 == 0 ? 0 : matrix[r2][c1 - 1]);
                    auto itr = s.lower_bound(sum - k);
                    if(itr != s.end())
                        ans = max(sum - *itr, ans);
                    s.insert(sum);
                }
            }
        }
        return ans == INT_MIN ? - 1: ans;
    }
};
