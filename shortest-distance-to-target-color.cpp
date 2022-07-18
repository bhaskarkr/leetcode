class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> UMAP;
        for(int i = 0; i < colors.size(); i++)
            UMAP[colors[i]].push_back(i);
             
        
        vector<int> ans;
        for(auto q : queries) {
            if(UMAP[q[1]].empty()) {
                ans.push_back(-1);
                continue;
            }
            auto lb = lower_bound(UMAP[q[1]].begin(), UMAP[q[1]].end(), q[0]);
            int res = INT_MAX;
            if(lb != UMAP[q[1]].end())
                res = abs((*lb) - q[0]);
             if(lb != UMAP[q[1]].begin())
                 res = min(res, abs(*prev(lb) - q[0]));
            ans.push_back(res);
        }
        return ans;
    }
};
