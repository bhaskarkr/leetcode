class Solution {
public:
    bool bfs(unordered_set<long>& blocked, pair<int, int> start, pair<int, int> dest) {
        unordered_set<long> vis;
        int n = blocked.size(), lvl = 0;
        int limit = blocked.size();
        queue<pair<int, int>> q;
        vis.insert(start.first * 1e6L + start.second);
        q.push(start);
        vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
        while(!q.empty()) {
            int c = q.size();
            if(lvl >= blocked.size())
                return true;
            while(c--) {
                auto curr = q.front();
                int x = curr.first, y = curr.second;
                if(x == dest.first && y == dest.second)
                    return true;
                q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(nx >= 0 && nx < 1e6 && ny >= 0 && ny < 1e6 && vis.find(nx * 1e6L + ny) == vis.end() && blocked.find(nx*1e6L + ny) == blocked.end()) {
                        q.push({nx, ny});
                        vis.insert(nx * 1e6L + ny);
                    }
                }
            }
            lvl++;
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long> isBlocked;
        for(auto block : blocked) {
            isBlocked.insert(block[0] * 1e6L + block[1]);
        }
        return bfs(isBlocked, {source[0], source[1]}, {target[0], target[1]}) && bfs(isBlocked, {target[0], target[1]}, {source[0], source[1]});
    }
};
