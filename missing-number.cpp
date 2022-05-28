class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n+1)) / 2;
        int temp = 0;
        for(int num : nums)
            temp += num;
        return sum - temp;
    }
};
