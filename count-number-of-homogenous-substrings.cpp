class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0, mod = 1e9 + 7;
        int cn = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i > 0 && s[i] == s[i-1])
                cn++;
            else
                cn = 1;
            ans = (ans + cn) % mod;
        }
        return ans;
    }
};
