class Solution {
public:
    
    double getAngle(int xDiff, int yDiff) {
        double pi = acos(-1.0);
        double angle = atan2(yDiff, xDiff);
        return  angle * 180.0 / pi;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angleFromLoc;
        int sameAsLoc = 0;
        for(int i = 0; i < points.size(); i++) {
            int xDiff = points[i][0] - location[0];
            int yDiff = points[i][1] - location[1];
            if(xDiff == 0 && yDiff == 0)
                sameAsLoc++;
            else {
                double temp = getAngle(xDiff, yDiff);
                angleFromLoc.push_back(temp);
            }
        }
        sort(angleFromLoc.begin(), angleFromLoc.end());
        int n = angleFromLoc.size();
        for(int i = 0; i < n; i++)
            angleFromLoc.push_back(angleFromLoc[i] + 360);
        int ans = 0;
        for(int i = 0, j = 0; i < 2*n; i++) {
            if(angleFromLoc[i] - angleFromLoc[j] > angle)
                j++;
            ans = max(ans, i - j + 1);
        }
        return ans + sameAsLoc;
    }
};
