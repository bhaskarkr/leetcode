class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() < 5) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = INT_MAX; 
        int i = 3, j = nums.size() - 1;
        while(i>=0) {
            ans = min(ans, nums[j--] -  nums[i--]);
        }
        return ans;
    }
};
