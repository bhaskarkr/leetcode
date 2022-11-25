class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        swapper(nums, ans, 0);
        return ans;
    }
    
    void swapper(vector<int>& nums, vector<vector<int>> &ans, int n) {
        if(n == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i = n; i < nums.size(); i++) {
            swap(nums[i], nums[n]);
            swapper(nums, ans, n + 1);
            swap(nums[i], nums[n]);
        }
    }
    
};
