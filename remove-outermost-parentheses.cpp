class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;
        for(char c : s) {
            if(count == 0 && c == '(') {
                count++;
            } else if(count == 1 && c == ')') {
                count--;
            } else {
                ans += c;
                count += c == '(' ? 1 : -1;
            }
        }
        return ans;
    }
};
