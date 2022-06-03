class Solution {
public:
    bool checkRecord(string s) {
        char prev = '@';
        int absent = 0, late = 0, isLate = false;
        for(char c : s) {
            if(c == 'L') {
                late = prev == c ? late + 1 : 1;
                if(late >= 3) {
                    isLate = true;
                    break;
                }
            } else if( c == 'A')
                absent++;
            prev = c;
        }
        return absent < 2 && !isLate;
    }
};
