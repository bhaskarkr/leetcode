class Solution {
public:
    vector<string> ans;
    void helper(string s, int index, string curr) {
        if(index >= s.length()) {
            ans.push_back(curr);
            return;
        }
        if(s[index] == '{') {
            index ++;
            set<char> options;
            for(; index < s.length() && s[index] != '}'; index++) {
                if(s[index] == ',')
                    continue;
                else
                    options.insert(s[index]);
            }
            for(char op : options)
                helper(s, index + 1, curr + op);
        } else helper(s, index + 1, curr + s[index]);
    }
    vector<string> expand(string s) {
        helper(s, 0, "");
        return ans;
    }
};
