const int MOD = 1000000007;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        vector<int> powers;
        powers.push_back(1);
        for(int i = 1; i < nums.size(); i++)
            powers.push_back((powers.back()*2)%MOD);
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            if(nums[l] + nums[r] <= target) {
                ans += powers[r-l];
                ans %= MOD;
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
