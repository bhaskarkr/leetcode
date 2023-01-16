class Solution {
public:
    int countBinarySubstrings(string s) {
        int currConsecutive = 1;
        int prevConsecutive = 0;
        int ans = 0;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) {
                currConsecutive++;
            } else {
                ans += min(currConsecutive, prevConsecutive);
                prevConsecutive = currConsecutive;
                currConsecutive = 1;
            }
        }
        return ans + min(prevConsecutive, currConsecutive);
    }
};
