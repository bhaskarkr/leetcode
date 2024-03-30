class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> umap;
        for(int r = 0, l = 0; r < nums.size(); r++) {
            umap[nums[r]]++;
            while(umap.size() > k) {
                umap[nums[l]]--;
                if(umap[nums[l]] == 0)
                    umap.erase(nums[l]);
                l++;
            }
            ans += r - l + 1;
        }
        umap.clear();
        for(int r = 0, l = 0; r < nums.size(); r++) {
            umap[nums[r]]++;
            while(umap.size() > k - 1) {
                umap[nums[l]]--;
                if(umap[nums[l]] == 0)
                    umap.erase(nums[l]);
                l++;
            }
            ans -= r - l + 1;
        }
        return ans;
    }
};
