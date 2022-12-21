class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> umap;
        vector<int> color(n+1, -1);
        for(auto edge : dislikes) {
            umap[edge[0]].push_back(edge[1]);
            umap[edge[1]].push_back(edge[0]);
        }
        queue<int> Q;
        for(int i = 1; i <= n; i++) {
            if(color[i] == -1) {
                Q.push(i);
                int level = 1;
                while(!Q.empty()) {
                    int objects = Q.size();
                    while(objects--) {
                        int curr = Q.front();
                        Q.pop();
                        if(color[curr] != -1) {
                            if(color[curr] != level%2)
                                return false;
                        } else {
                            color[curr] = level%2;
                            for(int child : umap[curr]) {
                                Q.push(child);
                            }
                        }
                    }
                    level++;
                }
            }
        }

        return true;
    }
};
