class Solution {
public:

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int, vector<int>> umap;
        vector<int> indegree(n);
        for(auto edge : edges) {
            umap[edge[0]].push_back(edge[1]);
            umap[edge[1]].push_back(edge[0]);
        }
        int start = -1;
        int ans = 0;

        function<long(int curr, int par)> dfs = [&](int curr, int par) {
            long val = values[curr];
            for(int child : umap[curr]) {
                if(child == par)
                    continue;
                long childSum = dfs(child, curr);
                if(childSum != 0) {
                    val += childSum;
                }
            }
            cout<<val<<endl;
            if(val % k == 0)
                ans++, val = 0;
            return val;
        };
        dfs(0, -1);
        return ans;
    }
};
