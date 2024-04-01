class Solution {
public:
    int lengthOfLastWord(string s) {
        int r = s.length() - 1;
        while(r >= 0 && s[r] == ' ')
            r--;
        int l = r;
        while(l >= 0 && s[l] != ' ')
            l--;
        return r - l;
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        while(i >= 0 && !isalpha(s[i])) {
            i--;
        }
        int ans = 0;
        while(i >= 0 && s[i] != ' ')
            i--, ans++;
        return ans;    
    }
};
