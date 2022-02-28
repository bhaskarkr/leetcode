class Solution {
public:
    bool checkPerfectNumber(int num) {
        int divisorSum = 1;
        int n = 2;
        while(n*n <= num) {
            divisorSum += num % n ? 0 : n + (num/n == n ? 0 : num/n); 
            n++;
        }
        return divisorSum == num && num != 1;
    }
};
