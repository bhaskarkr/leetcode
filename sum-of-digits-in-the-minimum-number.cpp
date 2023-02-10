class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
        int minNum = INT_MAX;
        for(int num : nums)
            minNum = min(minNum, num);
        int sum = 0;
        while(minNum > 0) {
            sum += minNum%10;
            minNum /= 10;
        }
        return sum % 2 == 0;
    }
};
