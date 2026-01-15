class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> umap;
        umap[0] = 0;
        for(auto rod : rods) {
            auto temp(umap);
            for(auto [diff, height] : temp) {
                umap[diff + rod] = max(umap[diff + rod], height);
                if(diff > rod) {
                    umap[diff - rod] = max(umap[diff - rod], height + rod);
                } else {
                    umap[rod - diff] = max(umap[rod - diff], height + diff);
                }
            }
        }
        return umap[0];
    }
};
