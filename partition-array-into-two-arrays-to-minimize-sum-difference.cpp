class Solution {
public:
    vector<vector<int>> checkSum(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        vector<vector<int>> sums(n + 1);
        for(int selected = 0; selected < (1 << n); selected++) {
            int curr = 0, count = 0;
            for(int i = 0; i < n; i++) {
                if(((selected >> i) & 1) == 1) {
                    count++;
                    curr += nums[start + i];
                } 
            }
            sums[count].push_back(curr);
        }
        return sums;
    }

    int minimumDifference(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        auto left = checkSum(nums, 0, n / 2 - 1);
        auto right = checkSum(nums, n / 2, n - 1);
        int target = sum / 2;
        int ans = INT_MAX;
        for(int i = 0; i <= n / 2; i++) {
            sort(right[n/2 - i].begin(), right[n/2 - i].end());
            for(int currLeftSum : left[i]) {
                int expectedRightSum = target - currLeftSum;
                auto it = lower_bound(right[n/2 - i].begin(), right[n/2 - i].end(), expectedRightSum);
                if(it != right[n/2 - i].end()) {
                    ans = min(ans, abs(sum - 2 * (currLeftSum + (*it))));
                }
            }
        }
        return ans;
    }
};
