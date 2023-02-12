class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long ans = 0;
        unordered_map<int, vector<int>> adj;
        for(auto edge : roads) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        helper(0, adj, seats, ans, -1);
        return ans;
    }

    long long helper(int curr, unordered_map<int, vector<int>> &adj, int &seats, long long &ans, int prev) {
        long long sum = 1;
        for(auto child : adj[curr]) {
            if(child != prev)
                sum += helper(child, adj, seats, ans, curr);
        }
        if(curr != 0)
            ans += ((sum + seats - 1) / seats);
        return sum; 
    }
};
