
class Solution {
public:
    unordered_map<int, int> memo;
    int minCut(string s) {
        int ans = INT_MAX;
        return dfs(s, 0) - 1;
    }

    int dfs(string &s, int index) {
        if(index == s.length()) {
            return 0;
        }
        if(memo.find(index) != memo.end())
            return memo[index];
        int ans = INT_MAX;
        for(int i = index; i < s.length(); i++) {
            if(isPalindrome(s, index, i)) {
                ans = min(ans, dfs(s, i + 1) + 1);
            }
        }
        return memo[index] = ans;
    }

    bool isPalindrome(string &s, int l, int r) {
        while(l < r) {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
};
