class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int , int> umap;
        for(auto num : nums)
            umap[num]++;
        int ans = 0;
        for(auto [k, v] : umap) {
            if(v < 2)
                return -1;
            ans += (v / 3) + (v % 3 ? 1 : 0);
        }
        return ans;
    }
};
