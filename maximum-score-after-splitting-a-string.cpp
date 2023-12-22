class Solution {
public:
    int maxScore(string s) {
        int ones = 0, ans = 0, n = s.length();
        vector<int> z(n);
        for(int i = 0; i < n; i++)
            z[i] = (s[i] == '0' ?  1 : 0 ) + (i > 0 ? z[i - 1] : 0);
        for(int i = n - 1; i > 0; i--) {
            ones += (s[i] == '0' ?  0 : 1);
            ans = max(ans, ones + z[i - 1]);
        }
        return ans;
    }
};
