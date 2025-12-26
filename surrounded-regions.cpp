class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
    void dfs(vector<vector<char>>& board, vector<vector<bool>> &visited, int x, int y, int m, int n) {
        visited[x][y] = true;
        for(int d = 0; d < 4; d++) {
            int nx = dx[d] + x;
            int ny = dy[d] + y;
            if(nx >= m || ny >= n || nx < 0 || ny < 0 || visited[nx][ny] || board[nx][ny] != 'O')
                continue;
            dfs(board, visited, nx, ny, m, n);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O' && !visited[i][0])
                dfs(board, visited, i, 0, m, n);
            if(board[i][n-1] == 'O' && !visited[i][n-1])
                dfs(board, visited, i, n-1, m, n);
        }
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O' && !visited[0][j])
                dfs(board, visited, 0, j, m, n);
            if(board[m-1][j] == 'O' && !visited[m-1][j])
                dfs(board, visited, m-1, j, m, n);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
