class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        for(char c : s) {
            if(ans.empty()) {
                ans.push_back(c);
            } else {
                if(ans.back() == c - 32 || ans.back() == c + 32) {
                    ans.pop_back();
                } else {
                    ans.push_back(c);
                }
            }
        }
        return ans;
    }
};
