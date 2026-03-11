class Solution {
public:
    bool checkOnesSegment(string s) {
        bool found = true;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == '1' and s[i-1] == '0') {
                return false;
            }
        }
        return true;
    }
};
