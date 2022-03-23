class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int n = mat.size();
        if(!n)
            return 0;
        int m = mat[0].size();
        vector<vector<vector<int> > > DP (n, vector<vector<int>> (m, vector <int>(4, 0)));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!mat[i][j])
                    continue;
                DP[i][j] = {1, 1, 1, 1};
                //         {H, V, D, AD}
                if(j>0)
                    DP[i][j][0] += DP[i][j-1][0]; // H
                if(i>0)
                    DP[i][j][1] += DP[i-1][j][1]; // V
                if(i>0 && j<m-1)
                    DP[i][j][2] += DP[i-1][j+1][2]; // AD
                if(i>0 && j>0)
                    DP[i][j][3] += DP[i-1][j-1][3]; // D
                for(int k = 0; k < 4; k++) 
                    ans = max(ans, DP[i][j][k]);
            }
        }
        return ans;
    }
};
