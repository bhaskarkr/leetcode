class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_map<int, int>> umap;
        unordered_map<int, unordered_map<int, int>> dp;
        for(auto &edge : edges) {
            umap[edge[0]][edge[1]] = 0;
            umap[edge[1]][edge[0]] = 1;
        }

        function<int(int, int)> dfs = [&](int parent, int curr) {
            if(dp.find(parent) != dp.end() && dp[parent].find(curr) != dp[parent].end()) {
                return dp[parent][curr];
            }
            dp[parent][curr] = 0;
            for(auto &[child, cost] : umap[curr]) {
                if(child == parent)
                    continue;
                dp[parent][curr] += dfs(curr, child) + cost;
            }
            return dp[parent][curr];
        };

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(dfs(-1, i));
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_map<int, int>> umap;
        vector<int> ans(n, -1);
        for(auto &edge : edges) {
            umap[edge[0]][edge[1]] = 0;
            umap[edge[1]][edge[0]] = 1;
        }

        function<int(int, int)> dp = [&](int parent, int curr) {
            int sum = 0;
             for(auto &[child, cost] : umap[curr]) {
                if(child == parent)
                    continue;
                sum += dp(curr, child) + cost;
            }
            return sum;
        };

        function<void(int, int)> dfs = [&](int curr, int val) {
            ans[curr] = val;
            for(auto [child, cost] : umap[curr])
                if(ans[child] < 0) {
                    dfs(child, val - cost + umap[child][curr]);
                }
        };

        dfs(0, dp(-1, 0));
        return ans;
    }
};
