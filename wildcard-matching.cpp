class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_map<string, int> memo;
        return helper(0, 0, s, p, memo) == 1 ? true : false;

    }

    string getKey(int i, int j) {
        return to_string(i)+" "+to_string(j);
    }

    int helper(int i, int j, string &s, string &p, unordered_map<string, int> &memo) {
        if(memo.find(getKey(i, j)) != memo.end())
            return memo[getKey(i, j)];
        if(j == p.length())
            return i == s.length() ? 1 : 0;
        if(i < s.length() && (s[i] == p[j] || p[j] == '?'))
            return memo[getKey(i, j)] = helper(i + 1, j + 1, s, p, memo);
        if(p[j] == '*')
            return memo[getKey(i, j)] = (i < s.length() && helper(i + 1, j, s, p, memo)) || helper(i, j + 1, s, p, memo);
        return memo[getKey(i, j)] = 0;
    }
};
