class Solution {
public:
    int getManhattanDist(vector<int> &p1, vector<int> &p2) {
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<vector<int>>> distances(2001);
        for(int i = 0; i < workers.size(); i++) {
            for(int j = 0; j < bikes.size(); j++) {
                distances[getManhattanDist(workers[i], bikes[j])].push_back({i, j});
            }
        }
        int allocated = 0;
        vector<int> ans(workers.size(), -1);
        vector<int> selectedBike(bikes.size(), -1);
        for(int dist = 0; dist <= 2000 && allocated < workers.size(); dist++) {
            for(auto curr : distances[dist]) {
                if(ans[curr[0]] == -1 && selectedBike[curr[1]] == -1) {
                    ans[curr[0]] = curr[1];
                    selectedBike[curr[1]] = curr[0];
                    allocated++;
                }
            }
            
        }
        return ans;
    }
};
