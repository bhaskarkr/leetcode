class Solution {
public:
    unordered_map<string, bool> MEMO;
    bool isScramble(string s1, string s2) {
        string key = s1+s2;
        if(MEMO.find(key) != MEMO.end())
            return MEMO[key];
        if(s1 == s2) {
            return MEMO[key] = true;
        } else {
            int l1 = s1.length();
            for(int split = 1; split < l1; split++) {
                if(isScramble(s1.substr(0, split), s2.substr(0, split)) && isScramble(s1.substr(split, l1 - split), s2.substr(split, l1 - split))) {
                    return MEMO[key] = true;
                }
                if(isScramble(s1.substr(0, split), s2.substr(l1 - split, split)) && isScramble(s1.substr(split, l1 - split), s2.substr(0, l1 - split))) {
                    return MEMO[key] = true;
                }   
            }

        }
        
        return MEMO[key] = false;
    }
};
