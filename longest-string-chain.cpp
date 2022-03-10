class Solution {
public:
    
    static bool compare(string a, string b) {
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> DP;
        int ans = 0;
        for(auto word: words) {
            for(int i = 0; i < word.length(); i++) {
                string sub = word.substr(0, i) + word.substr(i+1);
                DP[word] = max(DP[sub]+1, DP[word]);
            }
            ans = max(DP[word], ans);
        }
        return ans;
    }
};
