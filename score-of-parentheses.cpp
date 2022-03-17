class Solution {
public:
    
    //     int scoreOfParentheses(string s) {
    //     stack<int> stk;
    //     int curr = 0;
    //     for(char c : s) {
    //         if(c == '(') {
    //             stk.push(curr);
    //             curr = 0;
    //         } else {
    //             curr += stk.top() + max(1, curr);
    //             stk.pop();
    //         }
    //     }
    //     return curr;
    // }
    
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
