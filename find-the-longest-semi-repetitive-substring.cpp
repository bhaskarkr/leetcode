class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        vector<int> counter(20);
        int ans = 0;
        for(int i = 0, j = 0, pair = 0; i < s.length(); i++) {
            if(i && s[i] == s[i-1])
                pair++;
            while(pair > 1) {
                if(s[j] == s[j+1])
                    pair--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
