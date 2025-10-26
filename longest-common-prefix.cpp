class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            ans = ans = ans.substr(0, strs[i].length());
            for(int c = 0; c < strs[i].length(); c++) {
                if(strs[i][c] != ans[c]) {
                    ans = ans.substr(0, c);
                    break;
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for(int i = 0; i < strs[0].length(); i++) {
            for(int j = 1; j < strs.size(); j++) {
                if(i >= strs[j].length() or strs[j][i] != strs[j - 1][i])
                    return ans;
            }
            ans.push_back(strs[0][i]);
        }
        return ans;
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];
        int ans = common.length();
        for(string s : strs) {
            int i = 0;
            for(; i < s.length() and i < common.length(); i++) {
                if(s[i] != common[i])
                    break;
            }
            ans = min(ans, i);
        }
        return common.substr(0, ans);
    }
};
