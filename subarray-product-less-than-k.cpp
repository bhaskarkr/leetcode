class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long prod = 1;
        int ans = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            while(prod >= k && j <= i)
                prod /= nums[j++];
            ans += i - j + 1;
        }
        return ans;
    }
};
