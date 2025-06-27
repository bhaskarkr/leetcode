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


class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long ans = 0, sum = 0, pow = 1;
        int zeroes = count(s.begin(), s.end(), '0');
        for(long r = s.length() - 1; r >= 0 && sum + pow <= k; r--) {
            if(s[r] == '1' && sum + pow <= k) {
                sum += pow;
                ans++;
            }
            pow <<= 1;
        }
        return ans + zeroes;
    }
};
