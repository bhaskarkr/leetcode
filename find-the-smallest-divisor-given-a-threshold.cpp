class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while(l < r) {
            int m = l + (r - l) / 2;
            int sum = 0;
            for(int num : nums) {
                sum += (num + m - 1) / m;
            }
            if(sum > threshold) {
                l = m + 1;
            } else 
                r = m;
        }
        return l;
    }
};
