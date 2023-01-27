class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOne = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                maxOne++;
            } else {
                maxOne = 0;
            }
            ans = max(ans, maxOne);
        }
        return ans;
    }
};
