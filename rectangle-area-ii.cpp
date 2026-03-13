class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int> sx, sy;
        for (const vector<int>& rec : rectangles)
        {
            sx.insert(rec[0]);
            sx.insert(rec[2]);
            sy.insert(rec[1]);
            sy.insert(rec[3]);
        }
        vector<int> x(sx.begin(), sx.end());
        vector<int> y(sy.begin(), sy.end());
        
        unordered_map<int, int> x_i;
        unordered_map<int, int> y_i;
        for (int i = 0; i < x.size(); ++i) x_i[x[i]] = i;
        for (int i = 0; i < y.size(); ++i) y_i[y[i]] = i;

        int res = 0;
        vector<vector<bool>> visit(x.size(), vector<bool>(y.size(), false));
        for (const vector<int>& rec : rectangles)
        {
            int x1 = rec[0], x2 = rec[2];
            int y1 = rec[1], y2 = rec[3];

            for (int i = x_i[x1]; i < x_i[x2]; ++i)
            {   
                for (int j = y_i[y1]; j < y_i[y2]; ++j)
                {             
                    if (visit[i][j] == true) continue;
                    visit[i][j] = true;
                    res = (res + (long long)(x[i+1] - x[i]) * (y[j+1] - y[j])) % 1000000007;
                }
            }
        }
        
        return res;
    }
};
