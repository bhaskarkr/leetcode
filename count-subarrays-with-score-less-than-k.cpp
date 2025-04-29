class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size(), ans = 0;
        vector<long long> presum(nums.size() + 1);
        for(int i = 1; i <= n; i++) {
            presum[i] += nums[i - 1] + presum[i-1];
        }
        for(long i = 1; i <= n; i++) {
            long long right = n;
            long long left = i;
            while(left <= right) {
                long long m = (right + left) / 2;
                if((presum[m] - presum[i-1]) * (m - i + 1) >= k) {
                    right = m - 1;
                } else {
                    left = m + 1;
                }
            }
            ans += max(0LL, right - i + 1LL);
        }
        return ans;
    }
};
