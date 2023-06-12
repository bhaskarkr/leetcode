class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() < 1)
            return ans;
        long start = nums[0];
        long end = nums[0];
        for(int i = 1; i <= nums.size(); i++) {
            if(i != nums.size() && 1L*(nums[i]) - nums[i-1] == 1) {
                end = nums[i];
            } else {
                if(start != end)
                    ans.push_back(to_string(start) + "->"+to_string(end));
                else
                    ans.push_back(to_string(start));
                if(i != nums.size())
                    start = nums[i];
                    end = nums[i];
            }
        }
        return ans;
    }
};
