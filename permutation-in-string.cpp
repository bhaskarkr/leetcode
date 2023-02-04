class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length())
            return false;
        vector<int> pattern(26), temp(26);
        int window = s1.length();
        for(char c : s1)
            pattern[c-'a']++;
        int end = 0, start = 0;
        while(end < window) {
            temp[s2[end++] - 'a']++;
        }
        if(pattern == temp)
            return true;
        for(; end < s2.length(); end++) {
            temp[s2[start++]-'a']--;
            temp[s2[end]-'a']++;
            if(pattern == temp)
                return true;
        }
        return false;
    }
};
