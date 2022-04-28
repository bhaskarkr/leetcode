class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for(string word : words) {
            int i1 = 0;
            int i2 = 0;
            while(i1 < s.length() && i2 < word.length()) {
                if(s[i1] == word[i2]) {
                    int j1 = i1;
                    int j2 = i2;
                    while(j1 < s.length() && s[j1] == s[i1])
                        j1++;
                     while(j2 < word.length() && word[j2] == word[i2])
                        j2++;
                    int l1 = j1 - i1;
                    int l2 = j2 - i2;
                    if((l1 < 3 && l1 != l2) || (l1 >= 3 && l1 < l2))
                        break;
                    i1 += l1;
                    i2 += l2;
                } else
                    break;
            }
            ans+= i1 == s.length() && i2 == word.length() ? 1 : 0;
        }
        return ans;
    }
};
