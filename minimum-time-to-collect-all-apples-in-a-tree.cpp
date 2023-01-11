class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n+1);
        int count = 0;
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return max(dfs(0, visited, adj, hasApple) * 2 - 2, 0);
    }

    int dfs(int curr, vector<bool> &visited, unordered_map<int, vector<int>> &adj, vector<bool>& hasApple) {
        if(visited[curr])
            return 0;
        visited[curr] = true;
        int apple = 0;
        for(auto child : adj[curr]) {
            apple += dfs(child, visited, adj, hasApple);
        }
        if(apple)
            return 1 + apple;
        return hasApple[curr];
    }
};
