class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int ans = 1;
        int prev = 0, n = points.size();
        for(int i = 1; i < n; i++) {
            if(points[i][0] <= points[prev][1]) {
                continue;
            }
            ans++;
            prev = i;
        }
        return ans;
    }
};
