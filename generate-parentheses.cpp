class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(2*n, "", 0, ans);
        return ans;
    }
    
    void dfs(int n, string str, int open, vector<string> &ans) {
        if(n <= 0 || open < 0 || open > n) {
            // cout<<str<<" "<<open<<endl;
            if(open == 0)
                ans.push_back(str);
            return;
        }
        dfs(n - 1, str + '(', open + 1, ans);
        dfs(n - 1, str + ')', open - 1, ans);   
    }
};


class Solution {
public:
    void dfs(int n, string s, int open, int close, vector<string> &ans) {
        if(s.length() >= 2 * n) {
            ans.push_back(s);
            return;
        }
        if(open < n)
            dfs(n, s + '(', open + 1, close, ans);
        if(open > close)
            dfs(n, s + ')', open, close + 1, ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(n, "", 0, 0, ans);
        return ans;
    }
};
