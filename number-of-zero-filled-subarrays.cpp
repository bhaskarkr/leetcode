class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i < n && nums[i] == 0) {
                long long c = 1;
                while(i + 1 < n && nums[i+1] == 0) {
                    i++;
                    c++;
                }
                ans += ((c + 1) * c) / 2;
            }
        }
        return ans;
    }
};
