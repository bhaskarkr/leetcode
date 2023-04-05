class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long preSum = 0;
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            int mod = preSum % (i + 1) > 0;
            ans = max(ans, preSum/(i + 1) + mod);
        }
        return ans;
    }
};
