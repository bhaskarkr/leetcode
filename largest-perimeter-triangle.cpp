class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int a = 0, b = 0, c = 0;
        sort(nums.begin(), nums.end());
        for(int i = nums.size() - 3; i >= 0 ; i--) {
            a = nums[i];
            b = nums[i+1];
            c = nums[i+2];
            if(a+b > c && a+c > b && b+c > a) {
                return a+b+c;
            }
        }
        return 0;
    }
};
