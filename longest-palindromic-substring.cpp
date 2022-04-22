class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0;
        int startIndex = 0;
        if(s.length() == 1)
            return s;
        for(int i = 0;  i < s.length() - 1; i++) {
            checkPalin(s, i, i, ans, startIndex);
            checkPalin(s, i, i+1, ans, startIndex);
        }
        return s.substr(startIndex, ans);
    }
    
    void checkPalin(string s, int start, int end, int  &ans, int &startIndex) {
        while(start>=0 && end < s.length() && s[start] == s[end]) {
            start--;
            end++;
        }
        if(ans < end - start - 1) {
            ans = end - start - 1;
            startIndex = start + 1;
        }
    }
};
