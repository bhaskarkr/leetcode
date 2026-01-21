class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            if(a[1] == b[1])
                return a[0] > b[0];
            return a[1] < b[1];
        });
        int ans = 0;
        for(int i = 1, j = 0; i < intervals.size(); i++) {
            if(intervals[i][0] < intervals[j][1]) {
                ans++;
            } else {
                j = i;
            }
        }
        return ans;
    }
};
