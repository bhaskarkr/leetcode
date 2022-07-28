class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[128] = {0};
        for(char c : s)
            count[c]++;
        for(char c : t)
            count[c]--;
        for(int val : count) {
            if(val)
                return false;
        }

        return true;
    }
};
