class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX, i = start;
        while(i >= 0 && nums[i] != target)
            i--;
        if(i >= 0)
            ans = abs(i - start);
        i = start;
        while(i < nums.size() && nums[i] != target)
            i++;
        if(i < nums.size())
            ans = min(ans, abs(i - start));
        return ans;
    }
};
