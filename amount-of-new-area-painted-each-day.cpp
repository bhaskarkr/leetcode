class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        vector<int> ans;
        map<int, int> intervals;
        
        for(auto p : paint) {
            int l = p[0], r = p[1];
            auto left = intervals.upper_bound(l);
            auto right = left;
            if(left != begin(intervals) && prev(left)->second >= l) {
                left = prev(left);
                l = left->second;
            } else {
                left = intervals.insert({l, r}).first;
            }

            int currPaint = r - l;
            while(right != intervals.end() && right->first < r) {
                currPaint -= min(r, right->second) - right->first;
                r = max(r, right->second);
                intervals.erase(right++);
            }
            left->second = max(left->second, r);
            ans.push_back(max(0, currPaint));
        }

        return ans;
    }
};
