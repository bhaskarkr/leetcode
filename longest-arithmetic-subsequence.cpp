class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, unordered_map<int, int>> umap;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                umap[i][diff] = max(umap[i][diff], max(umap[j][diff] + 1, 2));
                ans = max(ans, umap[i][diff]);
            }
        }

        return ans;
    }
};
