class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>> umap;
        for(auto conn : connections) {
            umap[conn[0]].push_back({conn[1], 1});
            umap[conn[1]].push_back({conn[0], -1});
        }
        vector<bool> visited(n);
        int ans = 0;
        queue<int> Q;
        Q.push(0);
        visited[0] = true;
        while(!Q.empty()) {
            int c = Q.size();
            while(c--) {
                int curr = Q.front();
                Q.pop();
                for(auto child : umap[curr]) {
                    if(!visited[child.first]) {
                        visited[child.first] = true;
                        if(child.second == 1) {
                            // cout<<curr<<" "<<child.first<<endl;
                            ans++;
                        }
                            
                        Q.push({child.first});
                    }
                }
            }
        }
        return ans;
    }
};
