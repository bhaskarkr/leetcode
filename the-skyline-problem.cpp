class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<pair<int, int>> locHeights;
        vector<vector<int>> ans;
        multiset<int> heights;
        heights.insert(0);

        for(auto building : buildings) {
            locHeights.push_back({building[0], building[2]});
            locHeights.push_back({building[1], -building[2]});
        }

        sort(locHeights.begin(), locHeights.end(), [](auto a, auto b) {
            if(a.first == b.first) {
                return a.second > b.second;
            } 
            return a.first < b.first;
        });

        for(auto locHeight : locHeights) {
            int height = abs(locHeight.second);
            int loc = locHeight.first;
            bool start = locHeight.second > 0;
            if(start) {
                if(height > *heights.rbegin())
                    ans.push_back({loc, height});
                heights.insert(height);
            } else {
                heights.erase(heights.find(height));
                if(height > *heights.rbegin()) {
                    ans.push_back({loc, *heights.rbegin()});
                }
            }
        }
        return ans;
    }
};
