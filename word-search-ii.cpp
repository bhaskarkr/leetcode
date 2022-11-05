class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> children;
        int index;
        TrieNode() : index(-1), children(vector<TrieNode*>(26, NULL)) {}
    };
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* curr, vector<string> &ans, vector<string>& words) {
        char currChar = board[i][j];
        if(currChar == '#' || curr->children[currChar-'a'] == NULL)
            return;
        
        curr = curr->children[currChar-'a'];
        if(curr->index != -1) {
            ans.push_back(words[curr->index]);
            curr->index = -1;
        }
        board[i][j] = '#';
        if(i < board.size() - 1)
            dfs(board, i + 1, j, curr, ans, words);
        if(j < board[i].size() - 1)
            dfs(board, i, j + 1, curr, ans, words);
        if(i > 0)
            dfs(board, i - 1, j, curr, ans, words);
        if(j > 0)
            dfs(board, i , j - 1, curr, ans, words);
        board[i][j] = currChar;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        TrieNode* root = createTrie(words);
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                dfs(board, i, j, root, ans, words);
            }
        }
        
        return ans;
    }
    
    TrieNode* createTrie(vector<string> &words) {
        TrieNode* root = new TrieNode();
        int i = 0;
        for(string s : words) {
            TrieNode* curr = root;
            for(char c : s) {
                if(curr->children[c-'a'] == NULL)
                    curr->children[c-'a'] = new TrieNode();
                curr = curr->children[c-'a'];
            }
            curr->index = i++;
        }
        return root;
    }
};
