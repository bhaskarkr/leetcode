class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<bool> visited(stones.size());
        int ans = 0;
        for(int i = 0; i < stones.size(); i++) {
            if(!visited[i])
                ans += dfs(i, stones, visited);
        }
        return ans;
    }
    
    int dfs(int index, vector<vector<int>>& stones, vector<bool> &visited) {
        visited[index] = true;
        int tempAns = 0;
        for(int i = 0; i < stones.size(); i++) {
            if(!visited[i] && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1]))
                tempAns += dfs(i, stones, visited) + 1;
        }
        return tempAns;
    }
};
