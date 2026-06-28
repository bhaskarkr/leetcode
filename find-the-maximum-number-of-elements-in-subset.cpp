class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int, int> umap, cc ;
        int ans = 0;
        for(auto num : nums) {
            umap[num]++;
        }

        ans = umap[1] % 2 ? umap[1] : umap[1]  - 1;
        umap.erase(1);
        ans = max(ans, 1);
        for(auto [k, v] : umap) {
            long sqt = sqrt(k);
            if(sqt * sqt == k) {
                if(umap[sqt] > 1) 
                    ans = max(ans, cc[sqt] + 1);
            }
            cc[k] = (sqt * sqt == k ? cc[sqt] : 0) + (v > 1 ? 2 : 0);
            
        }
        return ans;
    }
};
