class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<int> X = {0, 1, 0, -1}, Y = {-1, 0, 1, 0};
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> efforts(m, vector<int> (n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> PQ;
        PQ.push({0, 0, 0});
        while(!PQ.empty()) {
            vector<int> ele = PQ.top();
            int x = ele[1];
            int y = ele[2];
            int effort = ele[0];
            PQ.pop();
            if(efforts[x][y] < effort)
                continue;
            if(x == m - 1 && y == n - 1)
                return effort;
            // cout<<x<<" "<<y<<endl;
            for(int i = 0; i < 4; i++) {
                int nx = x + X[i];
                int ny = y + Y[i];
                if(nx < 0 || ny < 0 || nx > m - 1 || ny > n - 1) 
                    continue;
                int newEffort = max(effort, abs(heights[x][y] - heights[nx][ny]));
                if(efforts[nx][ny] > newEffort) {
                    // cout<<"pushed";
                    efforts[nx][ny] = newEffort;
                    PQ.push({newEffort, nx, ny});
                }   
            }
        }
        return efforts[m-1][n-1];
    }
};
