class Solution {
public:
    bool isValid(int x, int y, int m , int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        unordered_map<int, int> p;
        vector<vector<int>> arr(m, vector<int>(n));
        int color = 1, merged = 0, count = 0;
        vector<int> ans, dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
        for(auto &pos : positions) {
            int x = pos[0], y = pos[1];
            if(arr[x][y] == 0) {
                set<int> neigh;
                for(int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(isValid(nx, ny, m, n) && arr[nx][ny] > 0) {
                        while(p[arr[nx][ny]] != arr[nx][ny])
                            arr[nx][ny] = p[arr[nx][ny]];
                        neigh.insert(p[arr[nx][ny]]);
                    }
                }
                if(neigh.size()) {
                    for(int nn : neigh)
                        p[nn] = *neigh.begin();
                    arr[x][y] = *neigh.begin();
                    merged += neigh.size() - 1;
                } else {
                    arr[x][y] = color;
                    p[color] = color;
                    color++;
                }
            }
            ans.push_back(max(1, color - 1 - merged));
        }
        return ans;
    }
};
