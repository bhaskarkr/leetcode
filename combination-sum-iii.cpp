class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        dfs(1, k, comb, ans, n);
        return ans;
    }
    
    void dfs(int start, int k, vector<int>& comb, vector<vector<int>>& ans, int n) {
        if(k == 0)  {
            if(n == 0)
                ans.push_back(comb);
            return;
        }
        for(int i = start; i <= 9; i++) {
            comb.push_back(i);
            dfs(i + 1, k - 1, comb, ans, n - i);
            comb.pop_back();
        }
    }
};
