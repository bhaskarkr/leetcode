class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0, pairs = 0;
        unordered_map<int, int> umap;
        for(int r = 0, l = 0; r < nums.size(); r++) {
            umap[nums[r]]++;
            if(umap[nums[r]] > 1)
                pairs += umap[nums[r]] - 1;
            while(pairs >= k) {
                pairs -= umap[nums[l]] - 1;
                umap[nums[l]]--;
                l++;
            }
            ans += l;
        }
        return ans;
    }
};
