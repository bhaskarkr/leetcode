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


class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size(), ans = 0, sum = 0;
        for(long long right = 0, left = 0; right < n; right++) {
            sum += nums[right];
            while(sum * (right - left + 1) >= k && left <= right) {
                sum -= nums[left++];
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
