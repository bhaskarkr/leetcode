class WordDistance {
public:
    unordered_map<string, vector<int>> umap;
    WordDistance(vector<string>& wordsDict) {
        int n = wordsDict.size();
        for(int i = 0; i < n; i++)
            umap[wordsDict[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int i = 0, j = 0, m = umap[word1].size(), n = umap[word2].size();
        int ans = INT_MAX;
        while(i < m && j < n) {
            ans = min(ans, abs(umap[word1][i] - umap[word2][j]));
            umap[word1][i] < umap[word2][j] ? i++ : j++;
        }
        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
