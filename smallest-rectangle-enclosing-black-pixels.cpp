class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        queue<pair<int, int>> Q;
        Q.push({x, y});
        int minX = x, minY = y, maxX = x, maxY = y;
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        while(!Q.empty()) {
            auto curr = Q.front();
            Q.pop();
            minX = min(minX, curr.first);
            minY = min(minY, curr.second);
            maxX = max(maxX, curr.first);
            maxY = max(maxY, curr.second);
            for(int d = 0; d < 4; d++) {
                int nx = curr.first + dx[d];
                int ny = curr.second + dy[d];
                if(nx < 0 || ny < 0 || nx >= image.size() || ny >= image[0].size() || image[nx][ny] != '1')
                    continue;
                image[nx][ny] = '0';
                Q.push({nx, ny});
            }
        }
        return (maxX - minX + 1) * (1 + maxY - minY);
    }
};

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int l = x, r = x, t = y, d = y, m = image.size(), n = image[0].size();
        dfs(image, x, y, l, r, t, d, m, n);
        return (r-l + 1)*(t-d+1);
    }

    void dfs(vector<vector<char>>& image, int x, int y, int &l, int &r, int &t, int &d, int m, int n) {
        if(image[x][y]) {
            l = min(l, x);
            r = max(r, x);
            d = min(d, y);
            t = max(t, y);
            image[x][y] = '0';
        }
        if(x < m - 1 && image[x+1][y] == '1')
            dfs(image, x + 1, y, l, r, t, d, m, n);
        if(x > 0 && image[x-1][y] == '1')
            dfs(image, x - 1, y, l, r, t, d, m, n);
        if(y < n - 1 && image[x][y+1] == '1')
            dfs(image, x, y + 1, l, r, t, d, m, n);
        if(y > 0 && image[x][y-1] == '1')
            dfs(image, x, y - 1, l, r, t, d, m, n);
    }
};
