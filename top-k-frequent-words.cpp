class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> umap;
        for(auto word : words)
            umap[word]++;
        vector<vector<string>> bucket(words.size()+1);
        for(auto [k, v] : umap)
            bucket[v].push_back(k);
        vector<string> ans;
        for(int i = bucket.size() - 1; i > 0 && k > 0 ; i--) {
            sort(bucket[i].begin(), bucket[i].end());
            for(int j = 0; j < bucket[i].size() && k > 0; j++) {
                ans.push_back(bucket[i][j]);
                k--;
            }
        }
        return ans;
    }
};
