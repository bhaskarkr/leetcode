class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        vector<int> exists(100001);
        int minV = INT_MAX, maxV = 0;
        for(int i = 0; i < nums.size(); i++) {
            exists[nums[i]] = true;
            minV = min(minV, nums[i]);
            maxV = max(maxV, nums[i]);
        }
        int ans = 1, start = minV;
        for(int i = minV; i <= maxV; i++) {
            if(exists[i] && i - start > k) {
                start = i;
                ans++;
            }
        }
        return ans;
    }
};
