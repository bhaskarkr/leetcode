class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;
        for(int i = n - 1; i >= 0 && k > 0; i--, k-=25) {
            ans[i] = k >= 25 ? 'z' : ans[i] + k;
        }
        return ans;
    }
};
