class Solution {
public:
    long long mod = (1e9 + 7);
    long long power(long a, long b) {
        if(b == 0)
            return 1;
        long long temp = power(a, b / 2) % mod;
        if(b % 2)
            return (a * ((temp * temp) % mod)) % mod;
        return (temp * temp) % mod;

    }
    int countGoodNumbers(long long n) {
        long long ans = power(20, n / 2);
        return n % 2 ? (5 * ans) % mod : ans;
    }
};
