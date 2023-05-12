class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> ans(n);
        ans.back() = q.back()[0];
        for(int i = n - 2; i >= 0; i--) {
            int nextLoc = i+q[i][1] + 1;
            ans[i] = max(ans[i+1], q[i][0] + (nextLoc > n - 1 ? 0 : ans[nextLoc]));
        }
        return ans[0];
    }
};
