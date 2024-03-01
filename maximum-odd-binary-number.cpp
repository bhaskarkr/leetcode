class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;
        for(char &c : s)
            ones += (c == '1' ? 1 : 0);
        for(int i = 0; i < s.length(); i++) {
            if(ones > 1)
                s[i] = '1', ones--;
            else
                s[i] = '0';
        }
        if(ones > 0)
            s.back() = '1';
        return s;
    }
};
