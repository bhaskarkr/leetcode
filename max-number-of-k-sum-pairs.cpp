class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> umap;
        for(auto num : nums) {
            if(umap[k-num]) {
                umap[k-num]--;
                ans++;
            } else 
                umap[num]++;
        }
        return ans;
    }
};
