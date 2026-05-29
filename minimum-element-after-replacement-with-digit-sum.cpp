class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(auto num : nums) {
            int temp = num;
            int digitSum = 0;
            while(temp > 0) {
                digitSum += temp % 10;
                temp /= 10;
            }
            ans = min(ans, digitSum);
        }
        return ans;
    }
};
