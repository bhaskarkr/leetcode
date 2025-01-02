class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> umap;
        vector<vector<string>> ans;
        for(string &s : strs) {
            string t = s;
            sort(s.begin(), s.end());
            if(umap.find(s) == umap.end()) {
                umap[s] = ans.size();
                ans.push_back({});
            }
            ans[umap[s]].push_back(t);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> umap;
        vector<vector<string>> ans;
        for(string &s : strs) {
            vector<int> count(26);
            for(char c : s)
                count[c-'a']++;
            string key = "";
            for(int n : count)
                key += to_string(n) + "_";
            if(umap.find(key) == umap.end()) {
                umap[key] = ans.size();
                ans.push_back({});
            }
            ans[umap[key]].push_back(s);
        }
        return ans;
    }
};
