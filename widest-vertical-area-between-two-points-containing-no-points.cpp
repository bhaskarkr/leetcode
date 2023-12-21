class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x;
        for(auto point : points)
            x.push_back(point[0]);
        sort(x.begin(), x.end());
        int ans = 0;
        for(auto s = next(x.begin()); s != x.end(); s++) {
            ans = max(ans , (*s) - (*prev(s)));
        }
        return ans;
    }
};
