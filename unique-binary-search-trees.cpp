class Solution {
public:
    /*
            catalan number
                    (n)
                    N1
                  /    \
                (i)     (n-i-1)
               /   \
              j    (i-j-1) .......
    */
    int numTrees(int n) {
        vector<int> DP(n+1);
        DP[0] = 1;
        DP[1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                DP[i] += DP[j] * DP[i-j-1];
            }
        }
        return DP[n];
    }
};
