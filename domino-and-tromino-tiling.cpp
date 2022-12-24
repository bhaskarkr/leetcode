class Solution {
public:
    /**
        DP[0] = 1
        DP[1] = 1
        DP[2] = 2
        DP[3] = 5
        DP[4] = DP[3] + DP[2] + 2 * DP[1] + 2 * DP[0]
        DP[5] = DP[4] + DP[3] + 2 * DP[2] + 2 * DP[1] + 2 * DP[0] 
        DP[5] - DP[4] = DP[4] + DP[3]
        DP[5] = 2 * DP[4] + DP[3] 

        beyong n - 2, let XYX, then XYYX, then XYYYX, so all of them 
        will be contributing 2 * DP[n-3] and 2 * DP[n-4]
    */
    int numTilings(int n) {
        vector<long long> DP(max(4, n) + 1); 
        DP[0] = 1;
        DP[1] = 1;
        DP[2] = 2;
        DP[3] = 5;
        for(int i = 4; i <= n; i++) {
            DP[i] = (DP[i-1] * 2 + DP[i-3]) %1000000007;
        }
        return DP[n];
    }
};
