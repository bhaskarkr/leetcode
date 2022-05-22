class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        dfs(ans, 0, nums);
        return ans;
    }
    
    void dfs(vector<vector<int>> &ans, int index, vector<int> nums) {
        if(index == nums.size()-1) {
            ans.push_back(nums);
            return;
        }
         for(int i = index; i < nums.size(); i++) {
            if(i != index && nums[i] == nums[index])
                continue;
            swap(nums[index], nums[i]);
            dfs(ans, index + 1, nums);
        }
            
    }
};
