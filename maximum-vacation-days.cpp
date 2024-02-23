class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        vector<int> dp(flights.size(), INT_MIN);
        dp[0] = 0;
        for(int week = 0; week < days[0].size(); week++) {
            vector<int> temp(dp.begin(), dp.end());
            for(int node = 0; node < flights.size(); node++) {
                for(int prevNode = 0; prevNode < flights.size(); prevNode++) {
                    if(node == prevNode || flights[prevNode][node])
                        dp[node] = max(dp[node], temp[prevNode] + days[node][week]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
