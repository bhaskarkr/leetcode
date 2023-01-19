class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mapper;
        int ans = 0;
        int sum = 0;
        mapper[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i])%k;
            if(sum < 0)
                sum += k;
            ans += mapper[sum%k];
            mapper[sum]++;
        }
        return ans;
    }
};
