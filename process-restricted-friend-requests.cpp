class Solution {
public:
    int getParent(vector<int> &p, int curr) {
        if(p[curr] == curr)
            return curr;
        return p[curr] = getParent(p, p[curr]);
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<int> p(n);
        vector<bool> ans;
        for(int i = 0; i < n; i++)
            p[i] = i;
        for(auto &req : requests) {
            int p1 = getParent(p, req[0]), p2 = getParent(p, req[1]);
            if(p1 > p2)
                swap(p1, p2);
            bool valid = true;
            if(p1 != p2) {
                for(auto &res : restrictions) {
                    int pp1 = getParent(p, res[0]), pp2 = getParent(p, res[1]);
                    if(pp1 > pp2)
                        swap(pp1, pp2);
                    if((pp1 == p1 && pp2 == p2)) {
                        valid = false;
                        break;
                    }
                }
            }
            if(valid)
                p[p2] = p1;
            ans.push_back(valid);
        }
        return ans;
    }
};
