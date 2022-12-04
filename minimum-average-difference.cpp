class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long> rightSum(n);
        rightSum.back() = nums.back();
        for(int i = n-2; i >= 0; i--) {
            rightSum[i] = rightSum[i+1] + nums[i];
        }
        long ans = INT_MAX;
        int index = 0;
        long leftSum = 0;
        for(int i = 0; i < n; i++) {
            leftSum += nums[i];
            long newAns = abs((leftSum)/(i+1) - (i < n - 1 ? rightSum[i+1] /(n - i - 1) : 0));
            if(ans > newAns) {
                ans = newAns;
                index = i;
            }
        }
        return index;
    }
};
