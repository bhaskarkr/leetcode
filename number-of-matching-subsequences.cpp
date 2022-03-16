class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<int, int>>> counter(128);
        int ans = 0;
        for(int i = 0; i < words.size(); i++)
            counter[words[i][0]].push_back({i,1});
        for(char c : s) {
            auto temp = counter[c];
            counter[c] = {};
            for(auto indLen : temp) {
                int currIndexOfWord = indLen.second;
                indLen.second++;
                counter[words[indLen.first][currIndexOfWord]].push_back(indLen);
                if(currIndexOfWord == words[indLen.first].length())
                    ans++;
            }
        }
        return ans;
    }
};
