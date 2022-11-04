class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;
        set<char> chars = {'a', 'e', 'i', 'o','u', 'A', 'E', 'I', 'O','U'};
        while(l < r) {
            while(l < r && chars.find(s[l]) == chars.end()) {
                l++;
            }
            while(l < r && chars.find(s[r]) == chars.end()) {
                r--;
            }
            if(l < r)
                swap(s[l++], s[r--]);
        }
        return s;
    }
};
