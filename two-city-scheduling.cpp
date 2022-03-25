class Solution {
public:

	static bool comparator(vector<int> o1, vector<int> o2) {
	    return o1[1] - o1[0] < o2[1] - o2[0];
	}

    
    int twoCitySchedCost(vector<vector<int>>& costs) {
         // [[10,20],[30,200],[400,50],[30,20]]
         // if i take B, i will have to pay  10 170 -350 -10
         //     -350 -10 10 170
        int ans = 0;
        for(auto cost : costs)
            ans += cost[0];
        sort(costs.begin(), costs.end(), comparator);
        int n = costs.size()/2;
        for(int i = 0; i < n; i++) {
            ans += costs[i][1] - costs[i][0]; 
        }
        return ans;
    }
};
