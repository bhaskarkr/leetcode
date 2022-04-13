class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int low = 0, high = n - 1;
        int l = 0, t = 0, r = n - 1, d = n - 1;
        int k = 1;
        while(l <= r) {
            for(int i = l; i < r; i++) {
                ans[t][i] = k++;
            }
            for(int i = t; i < d; i++) {
                ans[i][r] = k++;
            }
            for(int i = r; i > l; i--) {
                ans[d][i] = k++;
            }
            for(int i = d; i > t; i--) {
                ans[i][l] = k++;
            }
            l++;
            r--;
            t++;
            d--;
        }
        if(n%2)
            ans[n/2][n/2] = k;
        
        return ans;
    }
};
