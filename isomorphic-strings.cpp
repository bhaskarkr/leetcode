class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapped, revMapped;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(mapped.find(t[i]) == mapped.end() && revMapped.find(s[i]) == revMapped.end()) {
                mapped[t[i]] = s[i];
                revMapped[s[i]] = t[i];
            } else {
                if(mapped[t[i]] != s[i] || revMapped[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};
