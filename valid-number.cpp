class Solution {
public:
    bool isNumber(string s) {
        bool period = false;
        bool number = false;
        bool exp = false;
        bool numberAfterExp = true;
        for(int i = 0; i < s.length(); i++) {
            if(isdigit(s[i])) {
                number = true;
                numberAfterExp = true;
            } else if(s[i] == '.') {
                if(exp || period)
                    return false;
                period = true;
            } else if(s[i] == 'e' || s[i] == 'E') {
                if(exp || !number)
                    return false;
                exp = true;
                numberAfterExp = false;
            } else if(s[i] == '-' || s[i] == '+') {
                if(i != 0 and s[i-1] != 'e' and s[i-1] != 'E')
                    return false;
            } else {
                return false;
            }
        }
        return number && numberAfterExp;
    }
};
