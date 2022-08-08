class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> my;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(my.empty() || nums[i] > my.back())
                my.push_back(nums[i]);
            else if(my.back() == nums[i])
                continue;
            else {
                int index = lower_bound(my.begin(), my.end(), nums[i]) - my.begin();
                my[index] = nums[i];
            }
        }
        return my.size();
    }
};
