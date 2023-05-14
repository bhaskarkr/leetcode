class Solution {
public:
    int maxScore(vector<int>& nums) {
        int m = nums.size();
        int n = m / 2;
        vector<vector<int>> gcd(m, vector<int>(m));
        vector<int> DP((1<<m));
        for(int i = 0; i < m - 1; i++) {
            for(int j = i + 1; j < m; j++) {
                gcd[i][j] = __gcd(nums[i], nums[j]);
            }
        }
        return helper(gcd, DP, 0, 1, m);
    }

    int helper(vector<vector<int>> &gcd, vector<int> &DP, int mask, int index, int m) {
        if(index > m / 2) 
            return 0;
        if(DP[mask])
            return DP[mask];
        for(int i = 0; i < m - 1; i++) {
            if((mask >> i) & 1)
                continue;
            for(int j = i + 1; j < m; j++) {
                if((mask >> j) & 1)
                    continue;
                int newMask = mask | (1 << i) | (1 << j);
                DP[mask] = max(DP[mask], index * gcd[i][j] + helper(gcd, DP, newMask, index  + 1, m));
            }
        }
        return DP[mask];
        
    }
};
