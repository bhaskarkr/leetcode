class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        set<int> visited;
        unordered_map<int, vector<int>> umap;
        
        int start = 1e9;
        for(auto p : adjacentPairs) {
            umap[p[0]].push_back(p[1]);
            umap[p[1]].push_back(p[0]);
        }
        for(auto [k, v] : umap) {
            if(v.size() == 1) {
                start = k;
                break;
            }
        }
        vector<int> ans = {start};
        visited.insert(start);
        while(visited.size() < adjacentPairs.size() + 1) {
            cout<<ans.back()<<endl;
            if(visited.find(umap[ans.back()][0]) == visited.end())
                ans.push_back(umap[ans.back()][0]);
            else 
                ans.push_back(umap[ans.back()][1]);
            visited.insert(ans.back());
        }
        return ans;

    }
};
