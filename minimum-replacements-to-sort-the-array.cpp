class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long maxAllowed = nums.back(), n = nums.size(), ans = 0;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] > maxAllowed) {
                int part = nums[i] / maxAllowed + (nums[i]%maxAllowed ? 1 : 0);
                ans += part - 1;
                maxAllowed = nums[i] / part;
            } else {
                maxAllowed = nums[i];
            }
        }
        return ans;
    }
};
