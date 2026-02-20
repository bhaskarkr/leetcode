class Solution {
 public:
    string shortestPalindrome(string ss) {
        string rr = ss;
        reverse(rr.begin(), rr.end());
        string_view s(ss);
        string_view r(rr);
        for(int i = 0; i < s.length(); i++) {
            if(r.substr(i) == s.substr(0, s.length() - i))
                return rr.substr(0, i) + ss;
        }
        return ss;
    }
};

class Solution {
 public:
    string shortestPalindrome(string ss) {
        string rr = ss;
        reverse(rr.begin(), rr.end());
        string_view s(ss);
        string_view r(rr);
        for(int i = 0; i < s.length(); i++) {
            if(s.starts_with(r.substr(i)))
                return rr.substr(0, i) + ss;
        }
        return ss;
    }
};
