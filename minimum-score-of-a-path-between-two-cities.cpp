class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> dist(n+1, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        dist[1] = 0;
        queue<int> Q;
        Q.push(1);
        int ans = INT_MAX;
        while(!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            for(auto child : adj[curr]) {
                if(dist[child.first] > child.second) {
                    dist[child.first] = child.second;
                    ans = min(ans, child.second);
                    Q.push(child.first);
                }
            }
        }
        return ans;
    }
};
