class Solution {
public:
    int getParent(int x, vector<int> &parents) {
        if(x == parents[x])
            return x;
        return parents[x] = getParent(parents[x], parents);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> parent(1001);

        vector<int> ans, candidate1, candidate2;

        for(auto &edge : edges) {
            if(parent[edge[1]]) {
                candidate1 = {parent[edge[1]], edge[1]};
                candidate2 = edge;
                edge[1] = 0;
            } else {
                parent[edge[1]] = edge[0];
            }
        }
        
        for(int i = 1; i <= 1000; i++)
            parent[i] = i;
        for(auto &edge : edges) {
            if(edge[1] == 0)
                continue;
            int u = edge[0], v = edge[1];
            int pu = getParent(u, parent);
            if(pu == v) {
                return candidate1.empty() ? edge : candidate1;
            } else {
                parent[v] = pu;
            }
        }
        return candidate2;
    }
};
