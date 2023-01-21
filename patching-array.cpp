class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1, ans = 0;
        int index = 0;
        while(miss <= n) {
            if(index < nums.size() && nums[index] <= miss) {
                miss += nums[index];
                index++;
            } else {
                // if my current miss was 4 and we added 4
                // to the list that means the next missing 
                // number will be 8, since 4 was the current missing
                // that means we have all numbers till 3, so 3 + 4 = 7
                miss = 2*miss;
                ans++;
            }
        }
        return ans;
    }
};
