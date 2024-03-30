class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int mf = 0, l = 0;
        unordered_map<int, int> umap;
        for(int r = 0; r < nums.size(); r++) {
            mf = max(mf, ++umap[nums[r]]);
            if(r - l - mf + 1 > k)
                --umap[nums[l++]];
        }
        return mf;
    }
};
