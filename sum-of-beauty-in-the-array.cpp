class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> mins(nums.size());
        mins.back() = nums.back();
        for(int i = nums.size() - 2; i >= 0; i--) 
            mins[i] = min(mins[i+1], nums[i]);
        int mx = nums[0], score = 0;
        for(int i = 1; i < nums.size() - 1; i++) {
            if(nums[i] > mx && nums[i] < mins[i+1])
                score += 2;
            else if(nums[i] > nums[i-1] && nums[i] < nums[i+1])
                score += 1;
            mx = max(mx, nums[i]);
        }
        return score;
    }
};
