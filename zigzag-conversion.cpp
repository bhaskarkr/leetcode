class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> strs(numRows);
        int i = 0, l = s.length();
        while(i < l) {
            for(int r = 0; r < numRows && i < l; r++)
                strs[r] += s[i++];
            for(int r = numRows - 2; r > 0 && i < l; r--)
                strs[r] += s[i++];
        }
        string ans = "";
        for(auto str : strs)
            ans += str;
        return ans;
    }
};
