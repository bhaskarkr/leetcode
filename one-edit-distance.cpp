class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.length() > t.length())
            swap(s, t);
        if(t.length() - s.length() > 1)
            return false;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != t[i]) {
                if(s.length() == t.length()) {
                    return s.substr(i + 1) == t.substr(i + 1);
                } 
                return s.substr(i) == t.substr(i + 1);
            }
        }
        return t.length() - s.length() == 1;
    }
};
