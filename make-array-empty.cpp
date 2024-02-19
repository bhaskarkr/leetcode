class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        unordered_map<int, int> pos;
        for(int i = 0; i < nums.size(); i++)
            pos[nums[i]] = i;
        
        sort(nums.begin(), nums.end());
        long long ans = nums.size();
        for(long long i = 1; i < nums.size(); i++) {
            if(pos[nums[i]] < pos[nums[i-1]])
                ans += nums.size() - i;
        }
        return ans;
    }
};
