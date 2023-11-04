class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for(auto k : left)
            ans = max(ans, k);
        for(auto k : right)
            ans = max(ans, n - k);
        return ans;
    }
};
