class Solution {
public:
    int longestSubsequence(string s, int k) {
        long curr = 0, ans = 0;
        for(long l = -1, r = 0; r < s.length(); r++) {
            curr = (curr << 1) | (s[r] == '1');
            while(curr > k) {
                int dig = log(curr) / log(2);
                curr ^= (1<<dig);
                l++;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};
