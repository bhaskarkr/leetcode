class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        priority_queue<vector<int>> pq;
        int dist[11][11];
        int n = workers.size(), m = bikes.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dist[i][j] = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
            }
        }
        pq.push({0, 0, 0});
        set<pair<int , int>> visited;
        while(!pq.empty()) {
            auto curr = pq.top();
            curr[0] = -curr[0];
            pq.pop();
            if(visited.find({curr[1], curr[2]}) != visited.end())
                continue;
            if(curr[1] == n)
                return curr[0];
            visited.insert({curr[1], curr[2]});
            for(int j = 0; j < m; j++) {
                if((curr[2] & (1 << j)) == 0) 
                    pq.push({-curr[0] - dist[curr[1]][j], curr[1] + 1, curr[2] | (1 << j)});
            }
        }
        return -1;
    }
};
