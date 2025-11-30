class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n));
        bool a = false;
        for(auto query : queries) {
            ans[query[0]][query[1]]++;
            if(query[3] + 1 < n) {
                ans[query[0]][query[3] + 1]--;
            }
            if(query[2] + 1 < n) {
                ans[query[2] + 1][query[1]]--;
            }
            if(query[2] + 1 < n and query[3] + 1 < n) {
                ans[query[2] + 1][query[3] + 1]++;
            }
        }
        for(int i = 1 ; i < n; i++)
            ans[i][0] += ans[i-1][0];
        for(int j = 1 ; j < n; j++)
            ans[0][j] += ans[0][j-1];
        for(int i = 1 ; i < n; i++) {
            for(int j = 1; j < n; j++) {
                if(i)
                    ans[i][j] += ans[i-1][j];
                if(j)
                    ans[i][j] += ans[i][j-1];
                if(i and j)
                    ans[i][j] -= ans[i-1][j-1];   
            }
        }
        return ans;
    }
};
