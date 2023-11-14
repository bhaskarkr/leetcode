class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n+1);
        for(auto rel : relations) {
            adj[rel[0]].push_back(rel[1]);
            indegree[rel[1]]++;
        }
        queue<int> q;
        bitset<5001> vis;
        for(int i = 1; i <= n; i++) {
            if(indegree[i] == 0)
                q.push(i), vis[i] = true;
        }
        int ans = 0, k = 0;
        
        while(!q.empty()) {
            int level = q.size();
            while(level--) {
                int curr = q.front();
                k++;
                q.pop();
                for(auto child : adj[curr])
                    if(--indegree[child] == 0) {
                        q.push(child);
                        vis[child] = true;
                    }
            }
            ans++;
        }
        return k != n ? -1 : ans;
    }
};
