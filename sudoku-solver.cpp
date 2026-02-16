class Solution {
public:
    int getBoxIndex(int i, int j) {
        return 3 * (i / 3) + j / 3;  
    }

    bool helper(vector<vector<char>>& board, vector<int> &row, vector<int> &col, vector<int> &box) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(int n = 1; n <= 9; n++) {
                        bool r = row[i] & (1 << n);
                        bool c = col[j] & (1 << n);
                        bool b = box[getBoxIndex(i, j)] & (1 << n);
                        if(r | c | b)
                            continue;
                        row[i] |= (1 << n);
                        col[j] |= (1 << n);
                        box[getBoxIndex(i, j)] |= (1 << n);
                        board[i][j] = n + '0';
                        if(helper(board, row, col, box)) {
                            return true;
                        }
                        
                        row[i] ^= (1 << n);
                        col[j] ^= (1 << n);
                        box[getBoxIndex(i, j)] ^= (1 << n);
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> row(9);
        vector<int> col(9);
        vector<int> box(9);
        int missing = 0;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int val = board[i][j] - '0';
                    row[i] |= (1 << val);
                    col[j] |= (1 << val);
                    box[getBoxIndex(i, j)] |= (1 << val);
                }
            }
        }
        helper(board, row, col, box);
    }
};
