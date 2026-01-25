class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        unordered_map<int, vector<int>> umap;
        unordered_map<int, int> color;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] && i != j)
                    umap[i].push_back(j);
            }
        }
        unordered_set<int> visited;
        function<void(int, int)> dfs = [&](int curr, int p) {
            for(auto &child : umap[curr]) {
                if(child != p && visited.find(child) == visited.end()) {
                    visited.insert(child);
                    dfs(child, curr);
                }
            }
            umap.erase(curr);
        };
        for(int i = 0; i < n; i++) {
            if(visited.find(i) == visited.end()) {
                visited.insert(i);
                dfs(i, -1);
                ans++;
            }
        }
        return ans;
    }
};
