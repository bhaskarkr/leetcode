class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back({});
        for(int i = 0; i < nums.size(); i++) {
            int k = ans.size();
            for(int j = 0; j < k; j++) {
                auto temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
