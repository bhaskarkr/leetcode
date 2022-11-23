class Solution {
public:
    
    
    int getSquareSum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += (n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        set<int> visited;
        visited.insert(n);
        while( n != 1) {
            n = getSquareSum(n);
            if(visited.find(n) != visited.end())
                return false;
            visited.insert(n);
        }
        return true;
    }
};
