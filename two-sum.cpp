class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valToIndices;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(valToIndices.find( target - nums[i]) != valToIndices.end()) {
                return vector<int> {valToIndices[target - nums[i]], i};
            }
            valToIndices[nums[i]] = i;
        }
        return vector<int>{};
    }
};
