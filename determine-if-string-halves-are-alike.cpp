class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowel = "aeiou";
        int f = 0, b = 0, n = s.length();
        for(int i = 0; i < n/2; i++) {
            s[i] = tolower(s[i]);
            s[n - i - 1] = tolower(s[n - i - 1]);
            f += vowel.find(s[i]) != string :: npos? 1 : 0;
            b += vowel.find(s[n - i - 1]) != string :: npos ? 1 : 0;
        }
        return f == b;
    }
};


class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowel = "aeiouAEIOU";
        int c = 0;
        for(int i = 0; i < s.length() / 2; i++) {
            if(vowel.find(s[i]) != string::npos)
                c++;
        }
        for(int i = s.length() / 2; i < s.length(); i++) {
            if(vowel.find(s[i]) != string::npos)
                c--;
        }
        return c == 0;
    }
};
