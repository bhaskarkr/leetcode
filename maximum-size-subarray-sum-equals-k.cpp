class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        long sum = 0;
        int ans = 0;
        unordered_map<int , int> umap;
        umap[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(umap.find(sum) == umap.end())
                umap[sum] = i;
            if(umap.find(sum - k) != umap.end())
                ans = max(ans, i - umap[sum - k]);
        }
        return ans;
    }
};
