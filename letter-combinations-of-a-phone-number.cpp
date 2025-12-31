class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        queue<string> q;
        int i = 0;
        q.push("");
        vector<string> inps = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        while(i < digits.length()) {
            int cn = q.size();
            while(cn--) {
                string curr = q.front();
                q.pop();
                int num = digits[i] - '0' - 2;
                for(char c : inps[num])
                    q.push(curr + c);
            }
            i++;
        }
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
            
        return ans.size() == 1 ? vector<string>() : ans;
    }
};


class Solution {
public:
    vector<string> k = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    void dfs(string s, vector<string> &ans, string &digits, int index) {
        if(s.length() == digits.length()) {
            ans.push_back(s);
            return;
        }
        for(char c : k[digits[index] - '0']) {
            s += c;
            dfs(s, ans, digits, index + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        dfs("", ans, digits, 0);
        return ans;
    }
};
