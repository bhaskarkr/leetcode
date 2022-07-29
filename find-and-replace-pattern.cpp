class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string pKey = getKey(pattern);
        vector<string> ans;
        for(string word : words) {
            auto tKey = getKey(word);
            if(tKey == pKey)
                ans.push_back(word);
        }

        return ans;
    }
    
    string getKey(string s) {
        unordered_map<char, int> ans;
        for(char c : s) {
            if(!ans[c])
                ans[c] = ans.size();
        }
        
        for(char& c : s)
            c = 'a' + ans[c];

        return s;
    }
};
