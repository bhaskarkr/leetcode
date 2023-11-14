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


class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, vector<int>> ans;
        unordered_map<char, int> temp;
        int count = 0;
        for(int i = 0; i < s.length() ; i++) {
            if(ans[s[i]].size() != 0) {
                int cc = 0, k = ans[s[i]][0];
                for(char c = 'a'; c <= 'z'; c++) {
                    if(upper_bound(ans[c].begin(), ans[c].end(), k) != ans[c].end())
                        cc++;
                }
                temp[s[i]] = cc;
            }
            ans[s[i]].push_back(i);
        }
        for(auto [c, k] : temp)
            count += k;
        return count;
    }
};
