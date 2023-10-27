class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m));
        for(int i = 0; i < m; i++) {
            int curr = 0;
            for(int j = 0; j <= n; j++) {
                if(j == n || box[i][j] == '*') {
                    int x = i, y = j - 1;
                    while(curr > 0) {
                        ans[y--][m - 1- x] = '#';
                        curr--;
                    }
                    curr = 0;
                    if(j < n)
                        ans[j][m - 1 - i] = '*';
                } else if(box[i][j] == '.') {
                    ans[j][m - 1- i] = '.';
                } else {
                    curr++;
                    ans[j][m - 1- i] = '.';
                }
            }
        }
        return ans;
    }
};
