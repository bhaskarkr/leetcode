class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0])
            return a[1]>b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        int n = envelopes.size();
        vector<int> LIS;
        for(auto env : envelopes) {
            int gteIndex = lower_bound(LIS.begin(), LIS.end(), env[1]) - LIS.begin();
            if(gteIndex >= LIS.size()) {
                LIS.push_back(env[1]);
            } else {
                LIS[gteIndex] = env[1];
            }
 
        }
        return LIS.size();
    }
};
