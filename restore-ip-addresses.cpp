class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        helper(0, ans, s, {});
        return ans;
    }

    void helper(int index, vector<string> &ans, string &s, vector<int> temp) {
        if(index == s.length()) {
            if(temp.size() == 4) {
                string t = to_string(temp[0]);
                for(int i = 1; i < 4; i++)
                    t += "."+to_string(temp[i]);
                ans.push_back(t);
            }
            return;
        }
        if(temp.size() >= 4)
            return;
        int curr = 0;
        for(int i = index; i < s.length() - 3 + temp.size(); i++) {
            if(curr == 0 && s[i] == '0') {
                temp.push_back(0);
                helper(i + 1, ans, s, temp);
                break;
            } else {
                curr = curr * 10 + s[i]-'0';
                if(curr <= 255) {
                    temp.push_back(curr);
                    helper(i + 1, ans, s, temp);
                    temp.pop_back();
                } else {
                    break;
                }
            }
        }
    }
};
