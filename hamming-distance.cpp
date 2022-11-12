class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        while(x > 0 || y > 0) {
            ans += (x & 1) ^ (y & 1); 
            x >>= 1;
            y >>= 1;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int hammingDistance(int x, int y) {
//         int m = x ^ y, ans = 0;
//         while(m > 0) {
//             ans += m&1;
//             m >>= 1;
//         }
//         return ans;
//     }
// };
