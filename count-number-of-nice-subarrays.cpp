class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odds = 0, ans = 0;
        for(int l = 0, r = 0; r < nums.size(); r++) {
            odds += nums[r] % 2;
            while(odds > k)
                odds -= nums[l++] % 2;
            ans += r - l + 1;
        }
        odds = 0;
        for(int l = 0, r = 0; r < nums.size(); r++) {
            odds += nums[r] % 2;
            while(odds > k - 1)
                odds -= nums[l++] % 2;
            ans -= r - l + 1;
        }
        return ans;
    }
};
