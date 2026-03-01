class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> um;
        sort(words.begin(), words.end(), [](auto a, auto b){return a.length() > b.length();});
        int ans = 0;
        for(string s : words) {
            um[s] = max(1, um[s]);
            for(int i = 0; i < s.length(); i++) {
                string temp = s.substr(0,i) + s.substr(i+1);
                um[temp] = max(um[s] + 1, um[temp]);
            }
            ans = max(ans, um[s]);
        }
        return ans;
    }
};

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

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string a, string b) {
            if(a.length() == b.length())
                return a < b;
            return a.length() < b.length();
        });
        unordered_map<string, int> umap;
        int ans = 0;
        for(string s : words) {
            for(int i = 0; i < s.length(); i++) {
                string temp = s.substr(0, i) + s.substr(i+1);
                umap[s] = max(umap[s], umap[temp] + 1);
            }
            ans = max(umap[s], ans);
        }
        return ans;
    }
};

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> umap;
        sort(words.begin(), words.end(), [&](auto a, auto b) {
            return a.length() < b.length();
        });
        int ans = 0;
        for(string s : words) {
            for(int i = 0; i < s.length(); i++) {
                umap[s] = max(umap[s], umap[s.substr(0, i) + s.substr(i + 1)] + 1);
            }
            ans = max(umap[s], ans);
        }
        return ans;
    }
};
