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


class Solution {
public:
    vector<vector<long>> generatePossibleSums(vector<int>& nums, int l, int r) {
        int n = r - l;
        vector<vector<long>> bitToPossibleSum(n + 1);
        for(int selected = 0; selected < (1 << n); selected++) {
            long currSum = 0, bits = 0;
            for(int i = 0; i < n; i++) {
                if(selected & (1 << i)) {
                    bits++;
                    currSum += nums[l + i];
                }
            }
            bitToPossibleSum[bits].push_back(currSum);
        } 
        for(int i = 0; i < n; i++)
            sort(bitToPossibleSum[i].begin(), bitToPossibleSum[i].end());
        return bitToPossibleSum;
    }
    int minimumDifference(vector<int>& nums) {
        long sum = accumulate(nums.begin(), nums.end(), 0);
        int N = nums.size() / 2;
        long ans = LONG_MAX;
        auto leftBitToSums = generatePossibleSums(nums, 0, N);
        auto rightBitToSums = generatePossibleSums(nums, N, nums.size());
        for(int i = 0; i <= N; i++) {
            for(long leftSum : leftBitToSums[i]) {
                long expectedSum = sum / 2 - leftSum;
                auto rightSumPtr = lower_bound(rightBitToSums[N-i].begin(), rightBitToSums[N-i].end(), expectedSum);
                if(rightSumPtr != rightBitToSums[N-i].end()) {
                    long firstHalf = (leftSum + (*rightSumPtr));
                    long secondHalf = sum - firstHalf;
                    ans = min(ans, abs(firstHalf - secondHalf));
                }
            }
        }
        return ans;
    }
};
