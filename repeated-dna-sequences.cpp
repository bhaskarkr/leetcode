class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> umap;
        vector<string> ans;
        for(int i = 0, hash = 0; i < s.length(); i++) {
            if(umap[hash = ((((hash & 0x07FFFFFF) << 3) | (s[i] & 7)))]++ == 1)
                ans.push_back(s.substr(i-9, 10));
        }
        return ans;
    }
};
