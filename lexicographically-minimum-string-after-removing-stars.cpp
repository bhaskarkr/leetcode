class Solution {
public:
    string clearStars(string s) {
        map<char, vector<int>> umap;
        vector<bool> validIndex(s.length(), true);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '*') {
                validIndex[i] = false;
                for(char c = 'a'; c <= 'z'; c++) {
                    if(umap[c].size())  {
                        validIndex[umap[c].back()] = false;
                        umap[c].pop_back();
                        break;
                    }
                }
            }
            else
                umap[s[i]].push_back(i);
        }
        string ans = "";
        for(int i = 0; i < s.length(); i++)
            if(validIndex[i])
                ans += s[i];
        return ans;
    }
};
