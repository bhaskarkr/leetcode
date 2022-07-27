class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(m == num/m && num%m == 0)
                return true;
            else if(m > num/m)
                r = m - 1;
            else
                l = m + 1;
        }
        return false;
    }
};
