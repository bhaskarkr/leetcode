class Solution {
public:
    int getParent(vector<int> &parent, int node) {
        while(parent[node] != node) {
            node = parent[node];
            parent[node] = parent[node];
        }
        return node;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n - 1 > connections.size())
            return -1;
        vector<int> parent(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for(vector<int> conn : connections) {
            int u = conn[0];
            int v = conn[1];
            int parU = getParent(parent, u);
            int parV = getParent(parent, v);
            if(parU < parV) {
                parent[parV] = parU;
            } else if(parU > parV) {
                parent[parU] = parV;
            }
        }
        for(int i = 0; i < n; i++) {
            parent[i] = getParent(parent, i);
        }
        set<int> groups(parent.begin(), parent.end());
        return groups.size() - 1;
    }
};
