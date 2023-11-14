class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, vector<int>> ans;
        int count = 0;
        for(int i = 0; i < s.length() ; i++)
            ans[s[i]].push_back(i);
        for(auto [c, k] : ans)
            if(k.size() > 1) {
                string t = s.substr(k[0] + 1, k.back() - k[0] - 1);
                unordered_set<char> uc(t.begin(), t.end());
                count += uc.size();
            }
        return count;
    }
};
