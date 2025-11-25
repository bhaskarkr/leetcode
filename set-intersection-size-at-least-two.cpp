class Solution {
public:
    bool static cmp(vector<int> a, vector<int> b) {
        if(a[1] == b[1])
            return a[0] > b[0];
        return a[1] < b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> ans;
        for(auto interval : intervals) {
            if(ans.empty() || ans.back() < interval[0]) {
                ans.push_back({interval[1] - 1});
                ans.push_back({interval[1]});
            } else if(ans.back() == interval[0]) {
                ans.push_back({interval[1]});
            } else if(ans.back() > interval[0] && ans.size() > 1 && ans[ans.size() - 2] < interval[0]) {
                ans.push_back({interval[1]});
            }
        }
        return ans.size();
    }
};
