class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = nums.size();
        int ans = 0;
        vector<unordered_map<long long, int> > DP(n);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                long long diff = (long long) nums[i] - nums[j];
                DP[i][diff] += DP[j][diff] + 1;
                ans += DP[j][diff];
            }
        }
        return ans;
    }
};
