class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector< vector < pair<int, int> > > counter(128);
        for(int i = 0; i < words.size(); i++)
            counter[words[i][0]].push_back({i, 1});
        int ans = 0;
        for(char c : s) {
            auto temp = counter[c];
            counter[c] = {};
            for(auto indLen : temp) {
                if(indLen.second == words[indLen.first].length())
                    ans++;
                else {
                    auto nestIndLen = indLen;
                    nestIndLen.second++;
                    counter[words[indLen.first][indLen.second]].push_back(nestIndLen);
                }
            }
        }
        return ans;
    }
};
