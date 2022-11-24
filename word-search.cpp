class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        bool ans = false;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(board, m, n, ans, 0, word, i, j);
                if(ans)
                    return true;
            }
        }
        return false;
    }
    
    void dfs(vector<vector<char>>& board, int m, int n, bool &ans, int index, string &word, int r, int c) {
        if(index == word.length())
            ans = true;
        if(ans || r >= m || r < 0 || c >= n || c < 0) 
            return;
        if(word[index] == board[r][c]) {
            char temp = board[r][c];
            board[r][c] = ' ';
            dfs(board, m, n, ans, index + 1, word, r + 1, c);
            dfs(board, m, n, ans, index + 1, word, r - 1, c);
            dfs(board, m, n, ans, index + 1, word, r, c + 1);
            dfs(board, m, n, ans, index + 1, word, r, c - 1);
            board[r][c] = temp;
        }
    }
};
