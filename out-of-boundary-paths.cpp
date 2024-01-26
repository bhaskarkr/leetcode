class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
    int dp[51][51][51];
    int mod = 1e9 + 7, ans = 0, m = 0, n = 0;
    int helper(int x, int y, int step) {
        if(step <= 0)
            return 0;
        if(dp[x][y][step] != -1)
            return dp[x][y][step];
        long temp = 0;
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) temp = (temp + 1) % mod;
            else temp = (temp + helper(nx, ny, step - 1)) % mod;
        }
        return dp[x][y][step] = temp;
    }
    int findPaths(int M, int N, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        m = M, n = N;
        return helper(startRow, startColumn, maxMove);
    }
};
