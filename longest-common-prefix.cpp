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
