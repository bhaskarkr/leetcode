class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        int n = s.length();
        while(j < n) {
            while(j < n && s[j] != ' ')
                j++;
            int k = j - 1;
            while(i < k) {
                swap(s[i], s[k]);
                i++;
                k--;
            }
            i = j + 1;
            j++;
        }
        return s;
    }
};
