class Solution {
public:

    int getParent(unordered_map<int, int> &parent, int curr) {
        if(parent[curr] == curr)
            return curr;
        return parent[curr] = getParent(parent, parent[curr]);
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, set<int>> sets;
        unordered_map<int, int> parent;
        vector<int> ans;
        for(int i = 1; i <= c; i++) {
            parent[i] = i;
        }
        for(auto &edge : connections) {
            int pu = getParent(parent, edge[0]);
            int pv = getParent(parent, edge[1]);
            if(pu < pv)
                parent[pv] = getParent(parent, pu);
            else
                parent[pu] = getParent(parent, pv);
        }

        for(auto [k, v] : parent) {
            sets[getParent(parent, v)].insert(k);
        }

        for(auto &q : queries) {
            int pq = getParent(parent, q[1]);
            if(q[0] == 1) {
                
                if(sets[pq].find(q[1]) != sets[pq].end())
                    ans.push_back(q[1]);
                else if(sets[pq].empty())
                    ans.push_back(-1);
                else
                    ans.push_back(*sets[pq].begin());
            } else {
                if(sets[pq].find(q[1]) != sets[pq].end())
                    sets[pq].erase(q[1]);
            }
        }
        return ans;
    }
};
