class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        string a = "aeiou";
        int vowel = 0;
        for(int i = 0;i < s.length(); i++) {
            if(a.find(s[i]) != string::npos)
                vowel++;
            if(i >= k && a.find(s[i-k]) != string::npos)
                vowel--;
            ans = max(ans, vowel);
        }
        return ans;
    }
};
