class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n);
        unordered_map<int, vector<int>> umap;
        for(vector<int> edge : edges) {
            umap[edge[0]].push_back(edge[1]);
            umap[edge[1]].push_back(edge[0]);
        }
        vector<int> vals;
        long long total = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                int val = dfs(i, umap, visited);
                vals.push_back(val);
                total += val;
            }
        } 
        long long ans = 0;
        for(int val : vals) {
            ans += val * (total - val);
        }
        return ans / 2;
    }

    int dfs(int curr, unordered_map<int, vector<int>> &umap, vector<bool> &visited) {
        int c = 1;
        visited[curr] = true;
        for(int child : umap[curr]) {
            if(!visited[child]) {
               c += dfs(child, umap, visited);
            }
        }
        return c;
    }
};
