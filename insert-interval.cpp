class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[1] < b[0];
    } 
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        auto itr1 = lower_bound(intervals.begin(), intervals.end(), newInterval, cmp);
        auto itr2 = upper_bound(intervals.begin(), intervals.end(), newInterval, cmp);
        if(itr1 == itr2) {
            intervals.insert(itr1, newInterval);
        } else {
            itr2 = prev(itr2);
            (*itr2)[0] = min(newInterval[0], (*itr1)[0]);
            (*itr2)[1] = max(newInterval[1], (*itr2)[1]);
            intervals.erase(itr1, itr2);
        }
        return intervals;
    }
};
