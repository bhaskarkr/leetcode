class Solution {
public:
    int numberOfWays(string corridor) {
        long ans = 0, k = 0, m = 0, mod = 1e9 + 7; 
        for(char c : corridor) {
            if(c == 'S') {
                k++;
                if(k == 3) {
                    ans = ans == 0 ? m + 1 : (ans * (m + 1)) % mod;
                    k = 1;
                    m = 0;
                }
            } 
            else {
                if(k == 2) {
                    m++;
                }
            }
            
        }
        return k % 2 == 1 ? 0 : ans == 0 and k == 2 ? 1 : ans;
    }
};
