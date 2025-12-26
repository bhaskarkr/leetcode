class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for(char c  : num) {
            while(!ans.empty() && ans.back() > c and k) {
                ans.pop_back();
                k--;
            }
            if((!ans.empty() && c == '0') || c != '0')
                ans.push_back(c);
        }
        while(!ans.empty() && k--) {
            ans.pop_back();
        }
        return ans.empty() ? "0" : ans;
    }
};
