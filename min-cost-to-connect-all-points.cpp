class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int index = 0;
        int counted = 0;
        int ans = 0;
        vector<int> dist(n, INT_MAX - 1);
        while(counted++ < n - 1) {
            int minIndex = index;
            dist[index] = INT_MAX;
            for(int nextIndex = 0; nextIndex < n; nextIndex++) {
                if(dist[nextIndex] != INT_MAX) {
                   dist[nextIndex] = min(dist[nextIndex], getManhattanDistance(points[index], points[nextIndex]));
                    minIndex = dist[minIndex] < dist[nextIndex] ? minIndex : nextIndex;
                }
            }
            ans += dist[minIndex];
            index = minIndex;
        }
        return ans;
    }
    
    int getManhattanDistance(vector<int> &p1, vector<int> &p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};
