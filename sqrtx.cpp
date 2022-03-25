class Solution {
public:
    int mySqrt(int x) {
        if(x < 2)
            return x;
        int l = 0, r = INT_MAX;
        while(l <= r) {
            int srt = l + (r-l)/2;
            if (srt == x / srt)
                return srt;
            else if(srt > x/srt)
                r = srt - 1;
            else
                l = srt + 1;
        }
        return r;
    }
};
