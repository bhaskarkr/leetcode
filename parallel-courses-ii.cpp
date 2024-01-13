class Solution {
public:
    vector<int> DP;
    int helper(int mask, vector<vector<int>> &adj, int n, int k) {
        if(mask == (1 << n) - 1)
            return 0;
        if(DP[mask] != -1)
            return DP[mask];
        vector<int> ind(n);
        for(int i = 0; i < n; i++) { 
            for(int child : adj[i])
                if((mask & (1 << child)) == 0) {
                    ind[i]++;
                    break;
                }     
        }
        int candBit = 0, ans = INT_MAX;
        for(int i = 0; i < n; i++)
            if(ind[i] == 0 && (mask & (1 << i)) == 0)
                candBit |= (1 << i);
        if(__builtin_popcount(candBit) <= k) {
            ans = min(ans, 1 + helper(candBit | mask, adj, n, k));
        } else {
            int temp = candBit;
            while(temp > 0) {
                temp = (temp - 1) & candBit;
                if(__builtin_popcount(temp) != k)
                    continue;
                ans = min(ans, 1 + helper(temp | mask, adj, n, k));
            }
        }
        return DP[mask] = ans;
    }
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<vector<int>> adj(n);
        DP.resize(1 << 16, -1);
        for(auto &rel : relations)
            adj[rel[1] - 1].push_back(rel[0] - 1);
        return helper(0, adj, n, k);
    }
};
