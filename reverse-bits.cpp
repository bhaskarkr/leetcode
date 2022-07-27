class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int k = 32;
        while(k--) {
            ans <<= 1;
            ans |= n & 1;
            n >>= 1;
        }
        return ans;
    }
};
