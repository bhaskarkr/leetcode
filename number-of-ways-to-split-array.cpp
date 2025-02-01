class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        long left = nums[0], right = 0;
        for(int i = 1; i < nums.size(); i++) {
            right += nums[i];
        }
        for(int i = 1; i < nums.size(); i++) {
            ans += (left >= right) ? 1 : 0;
            left += nums[i];
            right -= nums[i];
        }
        return ans;
    } 
};
