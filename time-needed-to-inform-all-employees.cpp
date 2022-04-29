class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> tree;
        for(int i = 0; i < n; i++)
            tree[manager[i]].push_back(i);
        return dfs(tree, headID, informTime);
    }
    
    int dfs(unordered_map<int, vector<int>>& tree, int curr, vector<int>& informTime) {
        int currTime = informTime[curr];
        int childTime = 0;
        for(auto child : tree[curr])
            childTime = max(childTime, dfs(tree, child, informTime));
        return currTime + childTime;
    }
};
