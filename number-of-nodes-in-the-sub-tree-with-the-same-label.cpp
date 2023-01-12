class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
            vector<int> ans(n);
            unordered_map<int, vector<int>> adj;
            vector<int> count(26);
            for(auto edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            dfs(-1, 0, adj, ans, count, labels);
            return ans;
    }

    vector<int> dfs(int prev, int curr, unordered_map<int, vector<int>> &adj, vector<int> &ans, vector<int> count, string &labels) {
        vector<int> tempCount(26);
        for(auto child : adj[curr]) {
            if(child == prev)
                continue;
            vector<int> temp = dfs(curr, child, adj, ans, count, labels);
            for(int i = 0; i < 26; i++)
                tempCount[i] += temp[i];
        }
        for(int i = 0; i < 26; i++)
            count[i] += tempCount[i];
        count[labels[curr]-'a']++;
        ans[curr] = count[labels[curr]-'a'];
        return count;
    }
};
