class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        int n3 = INT_MIN;
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] < n3)
                return true;
            while(!stk.empty() && stk.top() < nums[i]) {
                n3 = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
