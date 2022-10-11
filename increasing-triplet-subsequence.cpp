class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        vector<int> rightMax(nums.size());
        rightMax.back() = nums.back();
        for(int i = nums.size() - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], nums[i]);
        }
        bool ans = false;
        int leftMax = nums[0];
        for(int i = 1; i < nums.size() - 1; i++) {
            if(leftMax < nums[i] && nums[i] < rightMax[i+1])
                return true;
            leftMax = min(leftMax, nums[i]);
        }
        return ans;
    }
};
