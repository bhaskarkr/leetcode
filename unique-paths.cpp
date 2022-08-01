class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
            2D 6R
            8!
            -------- = 8 * 7
                       ------
                         2
            2!*6!
        */
        long totalStep = m + n - 2;
        if(!totalStep)
            return 1;
        long numerator = 1;
        long cancel1 = max(m, n);
        long cancel2 = 1;
        while(cancel1 <= totalStep) {
            numerator *= cancel1;
            cancel1++;
            numerator /= cancel2;
            cancel2++;
        }
        return numerator;
    }
};
