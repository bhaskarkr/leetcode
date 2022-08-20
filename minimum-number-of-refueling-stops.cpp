class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0, curr = startFuel;
        priority_queue<int> PQ;
        for(int i = 0; curr < target; ans++) {
            while(i < stations.size() && stations[i][0] <= curr) {
                PQ.push(stations[i][1]);
                i++;
            }
            if(PQ.empty())
                return -1;
            curr += PQ.top();
            PQ.pop();
        }
        return ans;
    }
};
