class Solution {
public:
    vector<int> DP;
    vector<vector<int>> memoPalin;
    int minCut(string s) {
        int ans = INT_MAX;
        DP.resize(s.length() + 1, -1);
        memoPalin.resize(s.length() + 1, vector<int>(s.length() + 1, -1));
        return dfs(s, 0) - 1;
    }

    int dfs(string &s, int index) {
        if(index == s.length()) {
            return 0;
        }
        if(DP[index] != -1)
            return DP[index];
        int ans = INT_MAX;
        for(int i = index; i < s.length(); i++) {
            if(isPalindrome(s, index, i)) {
                ans = min(ans, dfs(s, i + 1) + 1);
            }
        }
        return DP[index] = ans;
    }

    bool isPalindrome(string &s, int l, int r) {
        while(l < r) {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
};
