class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9 + 7;
        long long int ans = 0;
        for(int i = 1; i <= n; i++) {
            int numOfBit = log2(i) + 1;
            ans <<= numOfBit; 
            ans |= i;
            ans %= mod;
        }
        return ans;
    }
};
