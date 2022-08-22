class Solution {
public:
    bool isPowerOfFour(long n) {
        /*
            4 = 100
            3 = 011
            4&3 = 0, every power of 2 will give same result, n&(n-1) == 0
            every power of 4, 16, 64, 256 - 1 will give a number divisble by 3
            3-4
            +12
            15-16
            +48
            63-64
            +192
            255-256
        */
        return ((n&(n-1)) == 0) && ((n-1)%3 == 0);
    }
};
