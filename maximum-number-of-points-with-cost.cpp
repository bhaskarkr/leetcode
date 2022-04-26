class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int r = points.size();
        int c = points[0].size();
        long long ans = 0;
        vector<long long> prev(points[0].begin(), points[0].end());
        for(int i = 1; i < r; i++) {
            vector<long long> left(c), right(c);
            left[0] = prev[0];
            right[c-1] = prev[c-1];
            for(int j = 1; j < c; j++) {
                left[j] = max(left[j-1] - 1, prev[j]); 
            }
            for(int j = c-2; j >= 0; j--) {
                right[j] = max(right[j+1] - 1, prev[j]); 
            }
            for(int j = 0; j < c; j++) {
                prev[j] = points[i][j] + max(left[j], right[j]);
            }
        }
        for(auto point : prev)
            ans = ans > point ? ans : point;
        return ans;
    }
};
