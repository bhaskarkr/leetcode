class Solution {
public:
    string reverseStr(string s, int k) {
        for(int index = 0; index < s.length(); index += 2*k) {
            reverse(s.begin() + index, s.begin() + (index + k < s.length() ? index + k : s.length()));
        }
        return s;
    }
};
