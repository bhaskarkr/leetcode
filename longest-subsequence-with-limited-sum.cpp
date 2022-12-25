class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 1; i < n; i++) {
            nums[i] += nums[i-1];
        }
        for(int q : queries) {
            ans.push_back(upper_bound(nums.begin(), nums.end(), q) - nums.begin());
        }
        return ans;
    }
};
