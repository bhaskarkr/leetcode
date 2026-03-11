class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> umap;
        for(auto p : points) {
            umap[p[0]].push_back(p[1]);
        }

        vector<pair<int, vector<int>>> merged;
        for(auto [k, v] : umap) {
            sort(v.begin(), v.end());
            merged.push_back({k, v});
        }
            
        long ans = INT_MAX;
        for(int x1 = 0; x1 < merged.size() - 1; x1++) {
            for(int x2 = x1 + 1; x2 < merged.size(); x2++) {
                vector<int> both;
                int y1 = 0;
                int y2 = 0;
                while(y1 < merged[x1].second.size() && y2 < merged[x2].second.size()) {
                    if(merged[x1].second[y1] == merged[x2].second[y2]) {
                        if(both.size()) {
                            ans = min(ans, 1L * abs(merged[x1].second[y1] - both.back()) * abs(merged[x2].first - merged[x1].first ));
                        }
                        both.push_back(merged[x1].second[y1]);
                        y1++;
                        y2++;
                    } else if(merged[x1].second[y1] > merged[x2].second[y2]) {
                        y2++;
                    } else {
                        y1++;
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
