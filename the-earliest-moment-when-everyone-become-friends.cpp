class Solution {
public:
    int getParent(int x, vector<int> &parent) {
        if(x == parent[x])
            return x;
        return parent[x] = getParent(parent[x], parent);
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        vector<int> parent(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int i = 0, m = logs.size();
        while(i < m) {
            int px = getParent(logs[i][1], parent), py = getParent(logs[i][2], parent);
            if(px != py) {
                if(px < py) {
                    parent[py] = px;
                } else {
                    parent[px] = py;
                }
                n--;
                if(n == 1)
                    return logs[i][0];
            }
            i++;
        }
    return -1;
    }
};
