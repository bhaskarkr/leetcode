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


class Solution {
public:
    string longestPalindrome(string s) {
        int index = 0, len = 1;
        for(int i = 0; i < s.length(); i++) {
            auto odd = isPalindrome(i, i, s);
            auto even = isPalindrome(i, i + 1, s);
            if(odd.second > len) {
                index = odd.first;
                len = odd.second;
            }
            if(even.second > len) {
                index = even.first;
                len = even.second;
            }
        }
        return s.substr(index, len);
    }

    pair<int, int> isPalindrome(int i, int j, string &s) {
        while(i >= 0 && j < s.length()) {
            if(s[i] != s[j])
                break;
            i--;
            j++;
        }
        return {i + 1, j - i - 1};
    }   
};
