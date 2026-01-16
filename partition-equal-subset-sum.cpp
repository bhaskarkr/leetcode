class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2)
            return false;
        vector<vector<bool>> DP(nums.size() + 1, vector<bool> (1 + sum / 2));
        DP[0][0] = true;
        for(int j = 1; j <= nums.size(); j++) {
            int num = nums[j-1];
            for(int i = 1; i <= sum / 2; i++) {
                if(i < num) {
                    DP[j][i] = DP[j - 1][i];
                } else {
                    DP[j][i] = DP[j - 1][i - num] || DP[j - 1][i];
                }
            }
        }
        return DP.back().back();
    }
};
