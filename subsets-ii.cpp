class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back({});
        for(int i = 0, j = 0; i < nums.size(); i++) {
            if(i && nums[i] != nums[i-1])
                j = 0;
            int k = ans.size();
            for(; j < k; j++) {
                auto temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
