class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0, n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            maxJump = max(maxJump, nums[i]);
            if(!maxJump) {
                return false;
            }
            maxJump--;
        }
        return true;
    }
};
