class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSubSum = INT_MAX, maxSubSum = INT_MIN, currMinSubSum = 0, currMaxSubSum = 0;
        int totalSum = 0;
        for(int num : nums) {
            totalSum += num;
            currMinSubSum = min(currMinSubSum + num, num);
            currMaxSubSum = max(currMaxSubSum + num, num);
            minSubSum = min(minSubSum, currMinSubSum);
            maxSubSum = max(maxSubSum, currMaxSubSum);
            if(currMinSubSum > 0)
                currMinSubSum = 0;
            if(currMaxSubSum < 0)
                currMaxSubSum = 0;
        }
        if(maxSubSum < 0)
            return maxSubSum;
        return max(maxSubSum, totalSum - minSubSum);
    }
};
