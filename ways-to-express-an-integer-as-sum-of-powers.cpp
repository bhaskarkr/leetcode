class Solution {
public:
    long mod = 1e9 + 7;
    int numberOfWays(int n, int x) {
        vector<long> squares;
        for(int i = 1; i <= n; i++) {
            squares.push_back(i);
            for(int j = 1; j < x; j++)
                squares.back() *= i;
        }
        vector<long> DP(n + 1, 0);
        DP[0] = 1;
        for(int i = 0; i < n && squares[i] <= n; i++) {
            int step = squares[i];
            for(int j = n; j > 0; j--) {
                if(j - step >= 0)
                    DP[j] = (DP[j] + DP[j - step]) % mod;
            }
        }
        return DP[n];
    }
};

class Solution {
public:
    long mod = 1e9 + 7;
    int numberOfWays(int n, int x) {
    vector<vector<long>> DP;
    long helper(vector<long> &nums, int target, int index) {
        if(target == 0)
            return 1;
        if(index == nums.size())
            return 0;
        if(DP[target][index] != -1)
            return DP[target][index];
        long curr = 0;
        if(nums[index] <= target)
            curr = helper(nums, target - nums[index], index + 1) % mod;
        else
            return 0;
        return DP[target][index] = (curr + helper(nums, target, index + 1)) % mod;
    }
    int numberOfWays(int n, int x) {
        vector<long> squares;
        DP.resize(301, vector<long>(301, -1));
        for(int i = 1; i <= (300) && i <= n; i++) {
            squares.push_back(i);
            for(int j = 1; j < x; j++)
                squares.back() *= i;
        }
        return helper(squares, n, 0);
    }
};
