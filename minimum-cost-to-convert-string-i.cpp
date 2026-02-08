class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<vector<long>> costs(26, vector<long>(26, INT_MAX));
        for(int i = 0; i < 26; i++)
            costs[i][i] = 0;
        for(int i = 0; i < n; i++) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            costs[x][y] = min(cost[i]*1l, costs[x][y]);
        }
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < source.length(); i++) {
            int x = source[i] - 'a';
            int y = target[i] - 'a';
            if(costs[x][y] >= INT_MAX)
                return -1;
            ans += costs[x][y];
        }

        return ans;
    }
};
