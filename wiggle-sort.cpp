class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> ans(nums.begin(), nums.end());
        sort(ans.begin(), ans.end());
        int n = nums.size();
        for(int i = 0, j = 0; j < n; i += 2, j++) {
            if(i >= n)
                i = 1;
            nums[i] = ans[j];
        }
    }
};
