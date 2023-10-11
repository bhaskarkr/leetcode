class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, end, ans;
        for(auto flow : flowers) {
            start.push_back(flow[0]);
            end.push_back(flow[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        for(auto p : people) {
            int firstInterval = lower_bound(end.begin(), end.end(), p) - end.begin();
            int lastInterval = upper_bound(start.begin(), start.end(), p) - start.begin();
            ans.push_back(lastInterval - firstInterval);
        }
        return ans;
    }
    // vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    //     unordered_map<int, int> umap;
    //     set<int> s;
    //     for(auto flo : flowers) {
    //         s.insert(flo[0]);
    //         s.insert(flo[1]);
    //     }
    //     for(auto p : people)
    //         s.insert(p);
    //     vector<int> indices(s.begin(), s.end());
    //     for(int i = 0 ; i < indices.size() ; i++)
    //         umap[indices[i]] = i;
    //     vector<int> cnt(indices.size() + 10);
    //     for(auto flo : flowers) {
    //         cnt[umap[flo[0]]]++;
    //         cnt[umap[flo[1]] + 1]--;
    //     }
    //     for(int i = 1; i < cnt.size(); i++)
    //         cnt[i] += cnt[i-1];
    //     vector<int> ans;
    //     for(auto p : people)
    //         ans.push_back(cnt[umap[p]]);
    //     return ans;
    // }
};
