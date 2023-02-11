class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        vector<int> presum(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); i++) {
            presum[i] += presum[i-1];
        }
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(sum + nums[i] > presum.back() - presum[i]) {
                vector<int> temp(nums.begin(), nums.begin() + i + 1);
                return temp;
            }
            sum += nums[i];
        }
        return {};
    }
};
