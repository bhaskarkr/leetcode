class Solution {
public:
    int reverse(int x) {
        int t = 0;
        if(x == INT_MIN)
            return 0;
        int sign = (x < 0 ? -1 : 1);
        x *= sign;
        while(x > 0) {
            if(t > INT_MAX / 10)
                return 0;
            t = t * 10 + x % 10;
            x /= 10;
        }
        return t * sign;
    }
};
