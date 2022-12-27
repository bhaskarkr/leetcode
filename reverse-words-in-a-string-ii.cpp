class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        for(int i = 0, j = 0; i < s.size(); i++, j++) {
            while(j < s.size() && s[j] != ' ') {
                j++;
            }
            int l = i, r = j - 1;
            while(l < r) {
                swap(s[l++], s[r--]);
            }
            i = j;
        }
    }
};
