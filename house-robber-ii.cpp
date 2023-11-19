class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), first = 0, second = 0, prevMax=0, currMax = 0;
        if(n == 1)
            return nums[0];
        for(int i = 0; i < n - 1; i++) {
            int temp = currMax;
            currMax = max(prevMax + nums[i], currMax);
            prevMax = temp;
        }
        first = currMax;
        prevMax=0, currMax = 0;
        for(int i = 1; i < n; i++) {
            int temp = currMax;
            currMax = max(prevMax + nums[i], currMax);
            prevMax = temp;
        }
        second = currMax;
        return max(first, second);
    }
};
