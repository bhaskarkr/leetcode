class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp(nums.begin(), nums.end());
        int n = nums.size();
        int j = n - 1, i = n / 2 - 1, ans = 0;
        while(j >= 0 && i >= 0) {
            while(i >= 0 && nums[i] * 2 > nums[j])
                i--;
            if(i < 0)
                break;
            nums[i] = 0;
            i--, j--, ans += 2;
        }
        return ans;
    }
};
