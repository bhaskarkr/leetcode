class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        unordered_map<string, set<int>> umap;
        int index = 0;
        for(string &w : arr) {
            for(int l = 1; l <= w.length(); l++)
                for(int i = 0; i <= w.length() - l; i++)
                    umap[w.substr(i, l)].insert(index);
            index++;
        }
        vector<string> ans(arr.size());
        for(auto &[k, v] : umap) {
            if(v.size() == 1) {
                index = *v.begin();
                if(ans[index].empty() || ans[index].length() >= k.length())
                    ans[index] = ans[index].length() == k.length() ? min(ans[index], k) : k;
            }
        }
        return ans;
    }
};
