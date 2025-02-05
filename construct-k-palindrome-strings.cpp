class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> umap;
        for(char c : s)
            umap[c]++;
        int odd = 0;
        for(auto [k, v] : umap)
            odd += v % 2; 
        if(odd > k)
            return false;
        return s.length() >= k;
    }
};
