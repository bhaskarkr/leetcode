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
