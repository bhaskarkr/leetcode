class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = -1;
        for(int i = 0; i < nums.size(); i++) {
            int index = (nums[i] < 0 ? -nums[i] : nums[i]) - 1;
            if(nums[index] < 0)
                dup = index + 1;
            else 
                nums[index] = -nums[index];
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0)
                return {dup, i + 1};
        }
        return {};
    }
};
