class Solution {
public:
    /*  
           0     0     0     0
        |  |  |  |  |  |  |  |
        2--1--2--1--2--1--2--1-----
        |  |  |  |  |  |  |  |
        S  0     0     0     0
        
        q = even -> return 0
        p = odd  -> return 1
        p = even -> return 2
    */
    int mirrorReflection(int p, int q) {
        while(p%2 == 0 && q%2 == 0)
            p /= 2, q /= 2;
        if(q % 2 == 0) 
            return 0;
        else if(p % 2)
            return 1;
        return 2;
    }
};
