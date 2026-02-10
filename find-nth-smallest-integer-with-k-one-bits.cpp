class Solution {
public:
    long long nthSmallest(long long n, int k) {
        long long possibilities[51][51] = {0};
        for(int i = 0; i <= 50; i++) {
            possibilities[i][0] = 1;
            for(int j = 1; j <= i; j++) {
                possibilities[i][j] = possibilities[i-1][j] + possibilities[i-1][j-1];
            }
        }

        long long ans = 0;
        for(int i = 49; i >= 0; i--) {
            if(k > 0 && possibilities[i][k] < n) {
                ans |= (1ll << i);
                n -= possibilities[i][k];
                k--;
            }
        }
        return ans;
    }
};
