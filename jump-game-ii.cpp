class Solution {
public:
    int jump(vector<int>& nums) {
        int curr = 0, currMax = 0, ans = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            currMax = max(currMax, i + nums[i]);
            if(i == curr) {
                ans++;
                curr = currMax;
            }
        }
        return ans;
    }
};
