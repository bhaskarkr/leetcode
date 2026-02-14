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



class Node {
public:
    unordered_map<char, Node*> children;
    bool isWord = false;
    int idx = 0;
    Node() {

    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        function<void()> buildTree = [&]() {
            int index = 0;
            for(string &word : words) {
                auto curr = root;
                for(char c : word) {
                    if(curr->children.find(c) == curr->children.end()) {
                        curr->children[c] = new Node();
                    }
                    curr = curr->children[c];
                }
                curr->isWord = true;
                curr->idx = index;
                index++;
            }
        };

        int m = board.size(), n = board[0].size();
        buildTree();
        vector<string> ans;
        function<void(int x, int y, Node* curr)> dfs = [&](int x, int y, Node* curr) {
            if(board[x][y] == '#' || !curr) {
                return;
            }
            if(curr->isWord) {
                ans.push_back(words[curr->idx]);
                curr->isWord = false;
            }
            char temp =  board[x][y];
            board[x][y] = '#';
            if(x + 1 < m)
                dfs(x + 1, y, curr->children[board[x+1][y]]);
            if(y + 1 < n)
                dfs(x, y + 1, curr->children[board[x][y+1]]);
            if(x - 1 >= 0)
                dfs(x - 1, y, curr->children[board[x-1][y]]);
            if(y - 1 >= 0)
                dfs(x, y - 1, curr->children[board[x][y-1]]);
            board[x][y] = temp;
        };


        for(int i = 0; i < m; i++) {        
            for(int j = 0; j < n; j++) {
                if(ans.size() == words.size())
                    break;
                dfs(i, j, root->children[board[i][j]]);
            }
        }
        return ans;
    }
};
