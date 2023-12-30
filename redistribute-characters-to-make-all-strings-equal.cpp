class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> umap;
        for(auto word : words)
            for(char c : word)
                umap[c]++;
        for(auto [c, v] : umap)
            if(v % words.size())
                return false;
        return true;
    }
};
