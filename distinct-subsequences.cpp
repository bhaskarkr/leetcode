class Solution {
public:
    vector<vector<int>> memo;
    int helper(string &s, string &t, int i1, int i2) {
        if(i1 == s.length() || i2 == t.length() || s.length() - i1 < t.length() - i2)
            return i2 == t.length();
        if(memo[i1][i2] != -1)
            return memo[i1][i2];
        memo[i1][i2] = 0;
        if(s[i1] == t[i2])
            memo[i1][i2] = helper(s, t, i1 + 1, i2 + 1);
        memo[i1][i2] += helper(s, t, i1 + 1, i2);
        return memo[i1][i2];
    }
    int numDistinct(string s, string t) {
        memo.resize(1000, vector<int>(1000, -1));
        return helper(s, t, 0, 0);
    }
};
