class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        vector<int> stk;
        for(int num : obstacles) {
            auto itr = upper_bound(stk.begin(), stk.end(), num);
            if(itr == stk.end()) {
                stk.push_back(num);
                ans.push_back(stk.size());
            } else {
                *itr = num;
                ans.push_back(itr - stk.begin() + 1);
            }
        }
        return ans;
    }
};
