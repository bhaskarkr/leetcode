class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        unordered_map<int, int> umap;
        int u = s.size(), ans = 0;
        for(int l = 0, r = 0; r < nums.size(); r++) {
            u -= umap[nums[r]]++ ? 0 : 1;
            while(u == 0) {
                u += --umap[nums[l]] ? 0 : 1;
                l++;
            }
            ans += l;
        }
        return ans;
    }
};
