class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> stk;
        int ans = 0;
        for(int num : nums) {
            while(!stk.empty() && (num == 0 || stk.back() > num))
                stk.pop_back();
            if(num && (stk.empty() || stk.back() != num))
                ans++, stk.push_back(num);
        }
        return ans;
    }
};
