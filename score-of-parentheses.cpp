class Solution {
public:
    int scoreOfParentheses(string s) {
        int openBck = 0;
        int ans = 0;
        char prev ='-';
        for(char c : s) {
            if(c == '(')
                openBck++;
            else
                openBck--;
            if(c == ')' && prev == '(')
                ans += (1 << openBck);
            prev = c;
        }
        return ans;
    }
};
