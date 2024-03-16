class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        long long ans = 0, c = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i and nums[i] > nums[i-1])
                c++;
            else
                c = 1;
            ans += c;
        }
        return ans;
    }
};
