class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n*n + 7);
        queue<int> Q;
        Q.push(1);
        visited[1] = true;
        int ans = 0;
        while(!Q.empty()) {
            int count = Q.size(); 
            while(count--) {
                int curr = Q.front();
                Q.pop();
                if(curr == n*n)
                    return ans;
                // cout<<curr<<endl;
                for(int i = 1; i <= 6 && curr < n*n; i++) {
                    int next = curr + i;
                    if(next > n*n)
                        continue;
                    int r = (next-1)/n;
                    int c = (next-1)%n;
                    if(r % 2)
                        c = n - c - 1;
                    // cout<<r<<" "<<c<<endl;
                    if(board[n-1-r][c] != -1) {
                        next = board[n-1-r][c];
                    }
                    if(visited[next])
                        continue;
                    visited[next] = true;
                    Q.push(next);
                }
            }
            ans++;
        }
        return -1;
    }
};
