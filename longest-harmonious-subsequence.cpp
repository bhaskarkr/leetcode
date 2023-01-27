class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> umap;
        int ans = 0;
        for(int num : nums) {
            umap[num]++;
            if(umap[num+1] > 0 || umap[num-1] > 0)
                ans = max(ans, umap[num] + max(umap[num+1], umap[num-1]));
        }
        return ans;
    }
};
