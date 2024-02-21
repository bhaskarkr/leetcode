class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, ans = INT_MAX;
        while(l <= r) {
            while(l < r && nums[l] == nums[l+1])
                l++;
            while(l < r && nums[r] == nums[r-1])
                r--;
            int m = l + (r - l) / 2;
            ans = min(ans, nums[m]);
            if(m < r && nums[m] > nums[m + 1])
                return nums[m+1];
            else if(nums[m] <= nums[r])
                r = m - 1;
            else
                l = m + 1;              
        }
        return ans;
    }
};
