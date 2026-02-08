class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int l = 0, r = 0; r < nums.size(); r++) {
            while(l < r && (long long )nums[l] * k * 1L < nums[r]) {
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return nums.size() - ans;
    }
};
