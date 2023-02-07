class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> sums;
        int sum = 0, ans = 0;
        sums[0] = 1;
        for(int num : nums) {
            sum += num;
            ans += sums[sum-goal];
            sums[sum]++;
        }
        return ans;
    }
};
