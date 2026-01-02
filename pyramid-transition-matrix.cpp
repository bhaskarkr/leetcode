class Solution {
public:
    unordered_map<string, bool> memo;
    bool helper(string bottom, string curr, int index, unordered_map<string, unordered_set<char>> &umap) {
        string kk = bottom + "_" + curr;
        if(memo.find(kk) != memo.end()) {
            return memo[kk];
        }
        if(bottom.length() == 1) {
            return memo[kk] = true;
        }
        if(index == bottom.length() - 1) {
            return memo[kk] = helper(curr, "", 0, umap);
        }
        for(auto c : umap[bottom.substr(index, 2)]) {
            if(helper(bottom, curr + c, index + 1, umap)) {
                return memo[kk] = true;
            }
        }
        return memo[kk] = false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, unordered_set<char>> umap;
        for(string s : allowed) {
            umap[s.substr(0, 2)].insert(s.back());
        }
        return helper(bottom, "", 0, umap);
    }
};
