class Solution {
public:
    bool canWin(string currentState) {
        unordered_map<string, bool> MEMO;
        return helper(currentState, MEMO);
    } 

    bool helper(string &s, unordered_map<string, bool> &MEMO) {
        if(MEMO.find(s) != MEMO.end())
            return MEMO[s];
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == '+' && s[i-1] == '+') {
                s[i] = '-';
                s[i-1] = '-';
                if(!helper(s, MEMO)) {
                    s[i] = '+';
                    s[i-1] = '+';
                    return true;
                }
                s[i] = '+';
                s[i-1] = '+';
            }
        }
        return false;
    }
};
