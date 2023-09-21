class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        for(int i = 1; i < costs.size(); i++) {
            for(int j = 0; j < costs[0].size(); j++) {
                int temp = costs[i][j];
                costs[i][j] = INT_MAX;
                for(int k = 0; k < costs[0].size(); k++) {
                    if(j == k)
                        continue;
                    costs[i][j] = min(costs[i][j], costs[i - 1][k] + temp);
                }
            }
        }
        return *min_element(costs.back().begin(), costs.back().end());
    }
};
