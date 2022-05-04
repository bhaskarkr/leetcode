class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> umap;
        int ans = 0;
        for(int num : arr) {
            umap[num] = umap[num-difference] + 1;
            ans = max(ans, umap[num]);
        }
        return ans;
    }
};
