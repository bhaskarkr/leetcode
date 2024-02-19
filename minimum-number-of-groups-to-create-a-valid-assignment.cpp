class Solution {
public:
    int eligible(int s, vector<int> &vals) {
        int c = 0, gs = s + 1;
        for(auto &val : vals) {
            int div = val / gs, rem = val % gs;
            if(rem == 0)
                c += div;
            else if(s - rem <= div)
                c += div + 1;
            else 
                return -1;
        }
        return c;
    }
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int , int> umap;
        for(int num : nums)
            umap[num]++;
        vector<int> vals;
        int minC = INT_MAX, ans = INT_MAX;
        for(auto &itr : umap)
            minC = min(minC, itr.second), vals.push_back(itr.second);
        for(int i = 1; i <= minC; i++) {
            int val = eligible(i, vals);
            cout<<val<<endl;
            if(val != -1) {
                ans = min(ans, val);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
