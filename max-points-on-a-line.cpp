class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        int n = points.size();
        unordered_map<string, int> umap;
        for(int i = 0; i < n; i++) {
            umap.clear();
            for(int j = i + 1; j < n; j++) {
                 if(points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                     continue;
                 } else {
                     int dx = points[i][0] - points[j][0];
                     int dy = points[i][1] - points[j][1];
                     int g = gcd(dx, dy);
                     umap[to_string(dx/g) + "_" + to_string(dy/g)]++;
                 }
            }
            for(auto [k, v] : umap)
                ans = max(ans, v + 1);
        }
        return ans;
    }
};
