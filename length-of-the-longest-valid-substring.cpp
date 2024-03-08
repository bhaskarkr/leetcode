class TrieNode {
public:
    char c;
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode(char cc) {
        c = cc;
        isWord = false;
    }
};
class Solution {
public:
    bool search(TrieNode * root, string &word, int l, int r, int maxLen) {
        TrieNode * curr = root;
        for(int i = l; i <= r && i < l + maxLen; i++) {
            if(curr->children[word[i]] == NULL)
                return false;
            curr = curr->children[word[i]];
            if(curr->isWord)
                return true;
        }
        return false;
    }
    int longestValidSubstring(string word, vector<string>& forbidden) {
        TrieNode * root = new TrieNode('@');
        int ans = 0, maxLen = 0;
        for(auto &w : forbidden) {
            auto *curr = root;
            maxLen = max(maxLen, (int) w.length());
            for(char &c : w) {
                if(!curr->children[c])
                    curr->children[c] = new TrieNode(c);
                curr = curr->children[c];
            }
            curr->isWord = true;
        }
        for(int l = word.length() - 1,  r = word.length() - 1; l >= 0 ; l--) {
            while(l <= r && search(root, word, l, r, maxLen))
                r--;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
