class Solution {
public:
    int fib(int n) {
        if(n < 2)
            return n;
        int a = 0;
        int b = 1;
        n = n - 1;
        while(n--) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;    
    }
};
