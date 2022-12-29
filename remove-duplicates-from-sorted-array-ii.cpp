class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;
        int prev = -1;
        for(int i = 0, j = 0; i < nums.size(); i++) {
            if(i > 1 && nums[i] == nums[i-1] && nums[i] == prev)
                continue;
            if(i > 0)
                prev = nums[i-1];
            nums[j] = nums[i];
            j++;
            ans++;
            
                
        }
        return ans;
    }
};
