class Solution {
public:
    /**
        Let square be at i,j with side of length 'w'
        then the 4 rectanges on each side will be as given below:
            A = [j + w, i];
            B = [n - j - w, i + w];
            C = [n - j, m - i - w];
            D = [j, m - i];
    */
    int helper(int n, int m, vector<vector<int>> &DP) {
        if(n > m)
            swap(m, n);
        if(n == 0)
            return 0;
        if(n == 1)
            return m;
        if(DP[m][n] != 0)
            return DP[m][n];
        int ans = INT_MAX;
        for(int w = 1; w <= n; w++) {
            for(int i = 0; i <= m - w; i++) {
                for(int j = 0; j <= n - w; j++) {
                    int A = helper(j + w, i, DP);
                    int B = helper(n - (j + w), i + w, DP);
                    int C = helper(n - j, m - (i + w), DP);
                    int D = helper(j, m - i, DP);
                    ans = min(ans,A + B + C + D + 1);
                }
            }
        }
        return DP[m][n] = ans;
    }
    int tilingRectangle(int n, int m) {
        vector<vector<int>> DP(14, vector<int>(14));
        return helper(m, n, DP);
    }
};
