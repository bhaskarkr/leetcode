class Solution {
public:

    /*
        CASE 1 : 2 parents for a node, candidate1 and candidate2 will be set
                 and one of them will removed (candidate2).
        CASE 2: cycle exist, then we can just return the node which caused the cycle. candidate1 and candidate2 will be empty.
        CASE 3 : both cycle and 2 parent exist, then we will first eleminate candidate2 and then check if cycle still exists then we will just return the candidate1 otherwise candidate2.
    */
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
