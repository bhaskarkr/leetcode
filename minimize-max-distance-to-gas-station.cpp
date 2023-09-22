class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double l = 0, r = stations.back() - stations[0], ans;
        while(l < r) {
            double m = (l + r) / 2;
            int c = 0;
            for(int i = 0; i < stations.size() - 1; i++) {
                c += ceil((stations[i+1] - stations[i]) / m) - 1;
            }
            if (c <= k) {
                ans = r;
                r = m - 1e-6;
            } else {
                l = m + 1e-6;
            }
        }
        return r;
    }
};
