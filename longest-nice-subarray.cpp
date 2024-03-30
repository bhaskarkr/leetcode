class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0, curr = 0;
        for(int l = 0, r = 0; r < nums.size(); r++) {
            while(curr & nums[r])
                curr ^= nums[l++];
            curr |= nums[r];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
