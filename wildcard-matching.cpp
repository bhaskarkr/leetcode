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

class Solution {
public:
    int DP[2001][2001];
    int helper(int i, int j, string &s, string &p) {
        if(j == p.length())
            return i == s.length() ? 1 : 0;
        if(DP[i][j] != -1)
            return DP[i][j];
        int curr = (i < s.length() && (p[j] == '?' || s[i] == p[j]) && helper(i + 1, j + 1, s, p));
        if(p[j] == '*') {
            curr |= (i < s.length() && helper(i + 1, j, s, p)) || helper(i, j + 1, s, p);
        } 
        return DP[i][j] = curr;
    }
    bool isMatch(string s, string p) {
        memset(DP, -1, sizeof(DP));
        return helper(0, 0, s, p) == 1;
    }
};
