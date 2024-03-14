class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int index = 1, i = 0, maxTillNow = nums[0], tempMax = nums[0];
        while(i < nums.size()) {
            if(nums[i] < maxTillNow) {
                index = i + 1;
                maxTillNow = tempMax;
            }
            tempMax = max(tempMax, nums[i]);
            i++;
        }
        return index;
    }
};
