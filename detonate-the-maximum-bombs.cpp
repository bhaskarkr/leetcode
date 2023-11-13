class Solution {
public:
    long getDist(vector<int> &a, vector<int> &b) {
        return (a[0] - b[0]*1L)*(a[0] - b[0]) + (a[1] - b[1]*1L) * (a[1] - b[1]);
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> distance(bombs.size());
        int ans = 0;
        for(int i = 0; i < bombs.size(); i++) 
            for(int j = i + 1; j < bombs.size(); j++) {
                long dist = getDist(bombs[i], bombs[j]);
                if(dist <= bombs[i][2]*(bombs[i][2]*1L))
                    distance[i].push_back(j);
                if(dist <= bombs[j][2]*(bombs[j][2]*1L))
                    distance[j].push_back(i);
            }
        
        queue<int> q;
        for(int i = 0; i < bombs.size(); i++) {
            bitset<100> visited;
            q.push(i);
            visited[i] = true;
            while(!q.empty()) {
                int ci = q.front();
                q.pop();
                for(int j : distance[ci]) {
                    if(!visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
            ans = max(ans, (int) visited.count());
        } 
        return ans;
    }
};
