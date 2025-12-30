class Solution {
public:
    vector<int> parent;
    // iterative one
    // int findParent(int a) {
    //     while(parent[a] != a) {
    //         parent[a] = parent[parent[a]];
    //         a = parent[a];
    //     }
    //     return a;
    // }
    // recursive one    
    int findParent(int a) {
        return a == parent[a] ? a : parent[a] = findParent(parent[a]);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int l = s.length();
        parent.assign(l, 0);
        for(int i = 0; i < l; i++)
            parent[i] = i;
        for(auto p : pairs) {
            int i = findParent(p[0]);
            int j = findParent(p[1]);
            if(i != j) {
                if(i > j)
                    swap(i, j);
                parent[j] = i;
            }
        }
        // have 2 option here 
        // 1. make vector of chars and sort in each group and populate accordingly
        // 2. create a priority queue and pop the min one and keep assign it to positions
        unordered_map<int, priority_queue<char, vector<char>, greater<char>>> umap;
        for(int i = 0; i < l; i++) {
            umap[findParent(i)].push(s[i]);
        }
        // not calling again findParent because it was already set while populating map
        for(int i = 0; i < l; i++) {
            s[i] = umap[parent[i]].top();
            umap[parent[i]].pop();
        }
        return s;
    }
};


class Solution {
public:
    int getParent(unordered_map<int, int> &parent, int x) {
        if(parent[x] == x)
            return x;
        return parent[x] = getParent(parent, parent[x]);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_map<int, int> parent;
        for(int i = 0; i < s.length(); i++) {
            parent[i] = i;
        }
        for(auto p : pairs) {
            int px = getParent(parent, p[0]);
            int py = getParent(parent, p[1]);
            int pp = min(px, py);
            parent[px] = pp;
            parent[py] = pp;
        }

        unordered_map<int, vector<int>> parentGroup;
        for(auto [k, v] : parent) {
            parentGroup[getParent(parent, v)].push_back(k);
        }
        string temp = s;
        for(auto &[k, v] : parentGroup) {
            vector<int> t(v.begin(), v.end());
            sort(v.begin(), v.end(), [&](int a, int b) {
                return temp[a] < temp[b];
            });
            sort(t.begin(), t.end());
            for(int i = 0; i < v.size(); i++) {
                s[t[i]] = temp[v[i]];
            }
        }
        return s;
    }
};
