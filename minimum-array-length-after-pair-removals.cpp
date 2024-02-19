class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        int j = n - 1, i = n / 2 - 1, ans = 0;
        while(j >= 0 && i >= 0) {
            while(i >= 0 && nums[i] >= nums[j])
                i--;
            if(i < 0)
                break;
            nums[i] = 0;
            i--, j--, ans += 2;
        }
        return n - ans;
    }
};
