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

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++) {
            if(umap.find(target - nums[i]) != umap.end()) {
                return {umap[target - nums[i]], i};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};
