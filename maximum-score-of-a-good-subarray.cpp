class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        long ans = nums[k];
        int n = nums.size();
        int mm = nums[k];
        int i = k - 1, j = k + 1;
        while(i >= 0 || j < n) {
            while(i >= 0 && nums[i] >= mm) {
                ans = max(mm * (j - i*1L), ans);
                i--;
            }
            while(j < n && nums[j] >= mm) {
                ans = max(mm *  (j - i*1L), ans);
                j++;
            }
            if(i >= 0 && j < n) {
                if(nums[i] >= nums[j])
                    mm = nums[i]; 
                else
                    mm = nums[j];
            }              
            else if(i >= 0)
                mm = nums[i];
            else if(j < n)
                mm = nums[j];
        }
        return ans;
    }
};
