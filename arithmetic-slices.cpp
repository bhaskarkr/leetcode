class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int count = 1;
        for(int i = 2; i < nums.size(); i++) {
            if(nums[i]-nums[i-1] == nums[i-1] - nums[i-2])   {
                ans += count;
                count++;
            }  else {
                count = 1;
            }     
        }
        return ans;
    }
};
