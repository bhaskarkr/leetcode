class Solution {
public:
    /*
        some what similar to coin change problem
    */
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> DP(target + 1, 0);
        DP[0] = 1;
        for(int i = 1; i <= target; i++) {
            for(int j = 0; j < nums.size(); j++) {
                if(i >= nums[j])
                    DP[i] += DP[i - nums[j]];
            }
        }
        return DP[target];
    }
};
