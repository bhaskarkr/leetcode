class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int K) {
        int n = nums.size();
        long long k = K;
        vector<long long> presum(n);
        presum[0] = nums[0];
        for(int i = 1; i < n; i++)
            presum[i] = presum[i-1] + nums[i]*1L;
        unordered_map<long long, int> umap;
        long long ans = LLONG_MIN;
        for(int i = 0; i < n; i++) {
            if(umap.find(nums[i] - k) != umap.end())
                    ans = max(ans, presum[i] - (umap[nums[i] - k] == 0 ? 0 : presum[umap[nums[i] - k] - 1]));
            if(umap.find(nums[i] + k) != umap.end())
                    ans = max(ans, presum[i] - (umap[nums[i] + k] == 0 ? 0 : presum[umap[nums[i] + k] - 1]));
            if(umap.find(nums[i]) == umap.end() || presum[i] - presum[umap[nums[i]]] <= 0)
                umap[nums[i]] = i;
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};
