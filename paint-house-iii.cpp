class Solution {
public:
    /*
        DP[house_index][neighborhood_count][prev_color]
    */
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> DP(m+1, vector<vector<int>>(m+1, vector<int>(n+2, -1)));
        int ans = solve(DP, houses, cost, m, n, target, 0, 0, n+1);
        return ans == INT_MAX ? -1 : ans;
    }
    
    long long solve(vector<vector<vector<int>>>& DP, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int house_index, int neighborhood_count, int prev_color) {
        if(neighborhood_count > target)
            return INT_MAX;
        
        if(house_index == m)
            return neighborhood_count == target ? 0 : INT_MAX;
        
        if(DP[house_index][neighborhood_count][prev_color] != -1)
            return DP[house_index][neighborhood_count][prev_color];
        
        long long temp_ans = INT_MAX;
        
        if(houses[house_index] != 0) {
            int new_neighborhood_count = neighborhood_count;
            if(prev_color != houses[house_index]) 
                new_neighborhood_count++; 
            temp_ans = min(temp_ans, solve(DP, houses, cost, m, n, target, house_index + 1, new_neighborhood_count, houses[house_index]));
        } else {
            for(int color = 1; color <= n; color++) {
                int new_neighborhood_count = neighborhood_count;
                if(prev_color != color) 
                    new_neighborhood_count++;
                temp_ans = min(temp_ans, solve(DP, houses, cost, m, n, target, house_index + 1, new_neighborhood_count, color) + cost[house_index][color - 1]);
            }   
        }
        
        return DP[house_index][neighborhood_count][prev_color] = temp_ans;
    }
};
