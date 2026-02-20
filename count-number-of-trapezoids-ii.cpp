class Solution {
public:
    static long long ngcd(long long a, long long b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        return gcd(a, b);
    }
    
    int countTrapezoids(vector<vector<int>>& points) {
        const int n = (int)points.size();
        const size_t segs = size_t(n) * (n - 1) / 2; // #pairs

        map<tuple<int, int>,int> slopes, lines, mids, midlines;

        long long ans = 0;
        for(int i = 0; i < points.size() - 1; i++) {
            for(int j = i+1; j < points.size(); j++) {
                long long x1 = points[i][0], y1 = points[i][1];
                long long x2 = points[j][0], y2 = points[j][1];
                long long dx = x2 - x1, dy = y2 - y1;
                long long rdy, rdx;

                if (dx == 0) {
                    rdy = 1; rdx = 0;
                } else {
                    long long g = ngcd(dy, dx);
                    rdy = dy / g; 
                    rdx = dx / g;
                    if (rdx < 0) { 
                        rdx = -rdx; 
                        rdy = -rdy;
                    }
                }

                long long bnum = (y1 * rdx - rdy * x1);
                long long bden = rdx;

                long long my = y1 + y2;
                long long mx = x1 + x2;


                ans += slopes[{rdy, rdx}];
                ans -= lines[{10e5 * rdy + bnum, 10e5 *rdx + bden}];
                ans -= mids[{my, mx}];
                ans += midlines[{10e5 *my + rdy, 10e5 *mx + rdx}];

                slopes[{rdy, rdx}]++;
                lines[{10e5 *rdy + bnum, 10e5 *rdx + bden}]++;
                mids[{my, mx}]++;
                midlines[{10e5 *my + rdy, 10e5 *mx + rdx}]++;
            }
        }
        return ans;
    }
};
