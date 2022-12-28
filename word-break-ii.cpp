class TrieNode {
public:    
    bool isWord;
    vector<TrieNode*> children;
    TrieNode() {
        isWord = false;
        children.resize(26, NULL);
    }
};
class Solution {
public:
    TrieNode* root;
    void constructTrie(vector<string>& wordDict) {
        root = new TrieNode();
        for(string word : wordDict) {
            TrieNode *curr = root;
            for(char ch : word) {
                if(!curr->children[ch-'a'])
                    curr->children[ch-'a'] = new TrieNode();
                curr =  curr->children[ch-'a'];
            }
            curr->isWord = true;
        }
    }

    bool wordExistTrie(string word) {
        TrieNode *curr = root;
        for(char ch : word) {
            if(!curr->children[ch-'a'])
                return false;
            curr =  curr->children[ch-'a'];
        }
        return curr->isWord;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        constructTrie(wordDict);
        helper(s, 0, "", ans);
        return ans;
    }

    void helper(string &s, int index, string path, vector<string> &ans) {
       if(index == s.length()) {
           path.pop_back();
           ans.push_back(path);
           return;
       }
       for(int i = index; i < s.length(); i++) {
           string tmp = s.substr(index, i - index + 1);
           if(wordExistTrie(tmp)) {
               helper(s, i + 1, path + tmp + " ", ans);
           }
       }
    }
};

class Solution {
public:
    unordered_map<string, vector<string> > u;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(u.find(s)!=u.end())
            return u[s];
        vector<string> ans;
        if(!s.length()){
            return {""};
        }
        for(string word: wordDict){
            int l = word.length();
            string t = s.substr(0, l);
            if(t==word){
                vector<string> temp = wordBreak(s.substr(l), wordDict);
                for(string k: temp){
                    ans.push_back(word + (k.length()? " " : "") + k);
                }
            }
            
        }
        u[s] = ans;
        return ans;
    }
};
