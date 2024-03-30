class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, zeroes = 0, exists = 0;
        for(int r = 0, l = 0; r < nums.size(); r++) {
            zeroes += nums[r] ? 0 : exists = 1;
            while(zeroes > 1)
                zeroes -= nums[l++] ? 0 : 1;
            ans = max(ans, r - l + 1 - zeroes);
        }
        return exists ? ans : ans - 1;
    }
};
